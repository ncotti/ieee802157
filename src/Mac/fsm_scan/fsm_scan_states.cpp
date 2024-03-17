#include "fsm_scan.h"
#include "../fsm_superframe/fsm_superframe.h"

static fsm_scan_state_t current_state = FSM_SCAN_INITIAL_STATE;

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_scan_state_t st_idle_fn(Mac* mac) {
    if (mac->notificationScan) {
        return ST_SCAN_WAIT_FOR_BEACON_INACTIVE;
    }
    return ST_SCAN_IDLE;
}

static fsm_scan_state_t st_wait_for_beacon_inactive_fn(Mac* mac) {
    if (fsm_superframe_get_state() == fsm_superframe_state_t::ST_INACTIVE) {
        return ST_SCAN_CHANGING_CHANNEL;
    }

    return ST_SCAN_WAIT_FOR_BEACON_INACTIVE;
}

static fsm_scan_state_t st_changing_channel_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        if (mac->scanType == scanType_t::ACTIVE_SCAN) {
            return ST_SCAN_TX_ON;
        } else {
            return ST_SCAN_RX_ON;
        }
    }

    return ST_SCAN_CHANGING_CHANNEL;
}

static fsm_scan_state_t st_tx_on_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_SCAN_SENDING_DATA;
    }

    return ST_SCAN_TX_ON;
}

static fsm_scan_state_t st_sending_data_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_SCAN_RX_ON;
    }

    return ST_SCAN_SENDING_DATA;
}

static fsm_scan_state_t st_rx_on_fn(Mac* mac) {
    if (mac->notificationConfirmReceived) {
        return ST_SCAN_RECEIVING_DATA;
    }

    return ST_SCAN_RX_ON;
}

static fsm_scan_state_t st_receiving_data_fn(Mac* mac) {
    if (mac->timerScanDurationTriggered) {
        if (mac->scanChannelsLeft) {
            return ST_SCAN_CHANGING_CHANNEL;
        } else {
            return ST_SCAN_TRX_OFF;
        }
    }

    return ST_SCAN_RECEIVING_DATA;
}

static fsm_scan_state_t st_trx_off_fn(Mac* mac) {
    return ST_SCAN_TRX_OFF;
}



/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_scan_fn_t fsm_scan_fn_list[FSM_SCAN_STATE_QTY] = {
    st_idle_fn,
    st_wait_for_beacon_inactive_fn,
    st_changing_channel_fn,
    st_tx_on_fn,
    st_sending_data_fn,
    st_rx_on_fn,
    st_receiving_data_fn,
    st_trx_off_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
void fsm_scan(Mac* mac) {
    fsm_scan_state_t new_state = fsm_scan_fn_list[current_state](mac);
    fsm_scan_transition_t transition = fsm_scan_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
}

fsm_scan_state_t fsm_scan_get_state(void) {
    return current_state;
}
