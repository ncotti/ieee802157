#include "fsm_start_net.h"

static fsm_start_net_state_t current_state = FSM_START_NET_INITIAL_STATE;

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_start_net_state_t st_idle_fn(Net* net) {
    if (net->notificationStartOWPAN) {
        return ST_START_NET_RESET;
    }

    return ST_START_NET_IDLE;
}

static fsm_start_net_state_t st_reset_fn(Net* net) {
    if (net->notificationConfirmReset) {
        return ST_START_NET_SET_OWPAN_ID;
    }

    return ST_START_NET_RESET;
}

static fsm_start_net_state_t st_set_owpan_id_fn(Net* net) {
    if (net->notificationConfirmSet) {
        return ST_START_NET_SCAN;
    }

    return ST_START_NET_SET_OWPAN_ID;
}

static fsm_start_net_state_t st_set_scan_fn(Net* net) {
    if (net->notificationConfirmScan) {
        return ST_START_NET_SET_VARIABLES;
    }

    return ST_START_NET_SCAN;
}

static fsm_start_net_state_t st_set_variables_fn(Net* net) {
    if (net->notificationConfirmSet) {
        return ST_START_NET_START;
    }
    return ST_START_NET_SET_VARIABLES;
}

static fsm_start_net_state_t st_start_fn(Net* net) {
    if (net->notificationConfirmStart) {
        return ST_START_NET_IDLE;
    }

    return ST_START_NET_START;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_start_net_fn_t fsm_start_net_fn_list[FSM_START_NET_STATE_QTY] = {
    st_idle_fn,
    st_reset_fn,
    st_set_owpan_id_fn,
    st_set_scan_fn,
    st_set_variables_fn,
    st_start_fn,
};

/******************************************************************************
 * FSM (Finite state nethine)
******************************************************************************/
void fsm_start_net(Net* net) {
    fsm_start_net_state_t new_state = fsm_start_net_fn_list[current_state](net);
    fsm_start_net_transition_t transition = fsm_start_net_transition_table[current_state][new_state];

    if (transition) {
        transition(net);
    }

    current_state = new_state;
}

fsm_start_net_state_t fsm_start_net_get_state(void) {
    return current_state;
}
