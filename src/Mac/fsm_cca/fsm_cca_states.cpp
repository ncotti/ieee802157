#include "fsm_cca.h"

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_cca_state_t st_idle_fn(Mac* mac) {
    if (mac->notificationSetRequest) {
        return ST_CCA_WAIT_CONFIRM;
    }

    return ST_CCA_IDLE;
}

static fsm_cca_state_t st_wait_confirm_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_CCA_IDLE;
    }

    return ST_CCA_WAIT_CONFIRM;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_cca_fn_t fsm_cca_fn_list[FSM_CCA_STATE_QTY] = {
    st_idle_fn,
    st_wait_confirm_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_cca_state_t fsm_cca(Mac* mac) {
    static fsm_cca_state_t current_state = FSM_CCA_INITIAL_STATE;
    fsm_cca_state_t new_state = fsm_cca_fn_list[current_state](mac);
    fsm_cca_transition_t transition = fsm_cca_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
    return current_state;
}
