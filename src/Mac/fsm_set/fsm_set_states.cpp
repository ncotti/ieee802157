#include "fsm_set.h"

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_set_state_t st_idle_fn(Mac* mac) {
    if (mac->notificationSetRequest) {
        return ST_SET_WAIT_CONFIRM;
    }

    return ST_SET_IDLE;
}

static fsm_set_state_t st_wait_confirm_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_SET_IDLE;
    }

    return ST_SET_WAIT_CONFIRM;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_set_fn_t fsm_set_fn_list[FSM_SET_STATE_QTY] = {
    st_idle_fn,
    st_wait_confirm_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_set_state_t fsm_set(Mac* mac) {
    static fsm_set_state_t current_state = FSM_SET_INITIAL_STATE;
    fsm_set_state_t new_state = fsm_set_fn_list[current_state](mac);
    fsm_set_transition_t transition = fsm_set_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
    return current_state;
}
