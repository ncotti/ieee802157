#include "fsm_tx.h"

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_tx_state_t st_idle_fn(Phy* phy) {
    if (phy->notificationStartTxion) {
        return ST_TX_WAIT_CONFIRM;
    }

    return ST_TX_IDLE;
}

static fsm_tx_state_t st_wait_confirm_fn(Phy* phy) {
    if (mac->notificationConfirmReceived) {
        return ST_TX_IDLE;
    }

    return ST_TX_WAIT_CONFIRM;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_tx_fn_t fsm_tx_fn_list[FSM_TX_STATE_QTY] = {
    st_idle_fn,
    st_wait_confirm_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_tx_state_t fsm_tx(Phy* phy) {
    static fsm_tx_state_t current_state = FSM_TX_INITIAL_STATE;
    fsm_tx_state_t new_state = fsm_tx_fn_list[current_state](mac);
    fsm_tx_transition_t transition = fsm_tx_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
    return current_state;
}
