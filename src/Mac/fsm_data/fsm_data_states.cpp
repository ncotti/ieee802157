#include "fsm_data.h"

static fsm_data_state_t current_state = FSM_DATA_INITIAL_STATE;

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_data_state_t st_idle_fn(Mac* mac) {
    if (mac->notificationRequestData) {
        return ST_DATA_RX_ON;
    }
    return ST_DATA_IDLE;
}

static fsm_data_state_t st_rx_on_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_DATA_CCA;
    }
    return ST_DATA_RX_ON;
}

static fsm_data_state_t st_cca_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_DATA_TX_ON;
    }

    return ST_DATA_CCA;
}

static fsm_data_state_t st_tx_on_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_DATA_TRANSMIT;
    }

    return ST_DATA_TX_ON;
}

static fsm_data_state_t st_transmit_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        if (mac->macAcknowledgeField) {
            ST_DATA_WAIT_FOR_ACK;
        } else {
            ST_DATA_TRX_OFF;
        }
    }

    return ST_DATA_TRANSMIT;
}

static fsm_data_state_t st_wait_for_ack_fn(Mac* mac) {
    if (mac->timerAckWaitTriggered) {
        return ST_DATA_TRX_OFF;
    } else if (mac->notificationConfirmReceived) {
        return ST_DATA_TRX_OFF;
    }

    return ST_DATA_WAIT_FOR_ACK;
}


static fsm_data_state_t st_trx_off_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_DATA_IDLE;
    }

    return ST_DATA_TRX_OFF;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_data_fn_t fsm_data_fn_list[FSM_DATA_STATE_QTY] = {
        st_idle_fn,
        st_rx_on_fn,
        st_cca_fn,
        st_tx_on_fn,
        st_transmit_fn,
        st_wait_for_ack_fn,
        st_trx_off_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
void fsm_data(Mac* mac) {
    fsm_data_state_t new_state = fsm_data_fn_list[current_state](mac);
    fsm_data_transition_t transition = fsm_data_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
}

fsm_data_state_t fsm_data_get_state(void) {
    return current_state;
}
