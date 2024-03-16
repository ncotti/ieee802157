#include "fsm_get.h"

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_get_state_t st_idle_fn(Mac* mac) {
    if (mac->notificationGetRequest) {
        return ST_GET_WAIT_CONFIRM;
    }

    return ST_GET_IDLE;
}

static fsm_get_state_t st_wait_confirm_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_GET_IDLE;
    }

    return ST_GET_WAIT_CONFIRM;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_get_fn_t fsm_get_fn_list[FSM_GET_STATE_QTY] = {
    st_idle_fn,
    st_wait_confirm_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_get_state_t fsm_get(Mac* mac) {
    static fsm_get_state_t current_state = FSM_GET_INITIAL_STATE;
    fsm_get_state_t new_state = fsm_get_fn_list[current_state](mac);
    fsm_get_transition_t transition = fsm_get_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
    return current_state;
}
