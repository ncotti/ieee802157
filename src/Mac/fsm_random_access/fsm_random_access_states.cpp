#include "fsm_random_access.h"

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_random_access_state_t st_idle_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->notificationStartTx) {
        if (mac->varSlottedTx) {
            return ST_WAIT_FOR_BACKOFF_BOUNDARY;
        } else {
            return ST_DELAY;
        }
    }

    return ST_IDLE;
}

static fsm_random_access_state_t st_wait_for_backoff_boundary_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerBackoff) {
        return ST_DELAY;
    }

    return ST_WAIT_FOR_BACKOFF_BOUNDARY;
}

static fsm_random_access_state_t st_delay_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerBackoff) {
        if (mac->varRandomDelay == 0) {
            if (mac->varCapabilities.ccaSupport) {
                return ST_CCA;
            } else {
                return ST_TRANSMIT;
            }
        }
    }

    return ST_DELAY;
}

static fsm_random_access_state_t st_CCA_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->notificationChannelIdle) {
        return ST_TRANSMIT;
    }
    else if (msg == mac->notificationChannelBusy) {
        return ST_RETRY;
    }

    return ST_CCA;
}

static fsm_random_access_state_t st_transmit_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->notificationFinishTx) {
        if (mac->varAckRequired) {
            return ST_WAIT_FOR_ACK;
        } else {
            return ST_IDLE;
        }
    }

    return ST_TRANSMIT;
}

static fsm_random_access_state_t st_wait_for_ack_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->notificationAckNotReceived) {
        return ST_RETRY;
    } else if (msg == mac->notificationAckReceived) {
        return ST_IDLE;
    }

    return ST_WAIT_FOR_ACK;
}

static fsm_random_access_state_t st_retry_fn(const cMessage* msg, Mac* mac) {
    if (mac->varNumberOfBackoffs <= mac->macMaxRABackoffs) {
        return ST_IDLE;
    } else {
        if (mac->varSlottedTx) {
            return ST_WAIT_FOR_BACKOFF_BOUNDARY;
        } else {
            return ST_DELAY;
        }
    }
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_random_access_fn_t fsm_random_access_fn_list[FSM_RANDOM_ACCESS_STATE_QTY] = {
        st_idle_fn,
        st_wait_for_backoff_boundary_fn,
        st_delay_fn,
        st_CCA_fn,
        st_transmit_fn,
        st_wait_for_ack_fn,
        st_retry_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
fsm_random_access_state_t fsm_random_access(const cMessage* msg, Mac* mac) {
    static fsm_random_access_state_t current_state = FSM_RANDOM_ACCESS_INITIAL_STATE;
    fsm_random_access_state_t new_state = fsm_random_access_fn_list[current_state](msg, mac);
    fsm_random_access_transition_t transition = fsm_random_access_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
    return current_state;
}
