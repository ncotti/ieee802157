#include "fsm_reset.h"

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_reset_state_t st_idle_fn(Mac* mac) {
    if (mac->notificationResetRequest) {
        return ST_RESET_WAIT_TRX_CONFIRM;
    }

    return ST_RESET_IDLE;
}

static fsm_reset_state_t st_wait_trx_confirm_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_RESET_IDLE;
    }

    return ST_RESET_WAIT_TRX_CONFIRM;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_reset_fn_t fsm_reset_fn_list[FSM_RESET_STATE_QTY] = {
    st_idle_fn,
    st_wait_trx_confirm_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_reset_state_t fsm_reset(Mac* mac) {
    static fsm_reset_state_t current_state = FSM_RESET_INITIAL_STATE;
    fsm_reset_state_t new_state = fsm_reset_fn_list[current_state](mac);
    fsm_reset_transition_t transition = fsm_reset_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
    return current_state;
}
