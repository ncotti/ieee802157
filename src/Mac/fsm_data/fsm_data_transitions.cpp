#include "fsm_data.h"

static bool success = false;

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_idle_rx_on(Mac* mac) {
    mac->notificationRequestData = false;
    mac->plme_set_trx_state_request(phyStatus_t::RX_ON);
}

static void from_rx_on_to_cca(Mac* mac) {
    mac->notificationConfirmReceived = false;
    mac->plme_cca_request();
}

static void from_cca_to_tx_on(Mac* mac) {
    mac->notificationConfirmReceived = false;
    mac->plme_set_trx_state_request(phyStatus_t::TX_ON);
}

static void from_tx_on_to_transmit(Mac* mac) {
    mac->notificationConfirmReceived = false;
    // TODO arguments
    // mac->pd_data_request(psduLength, psdu, bandplanID);
}

static void from_transmit_to_wait_for_ack(Mac* mac) {
    mac->notificationConfirmReceived = false;
    mac->scheduleAfter(mac->macAckWaitDuration, mac->timerAckWait);
}

static void from_transmit_to_trx_off(Mac* mac) {
    if (mac->timerAckWaitTriggered) {
        mac->timerAckWaitTriggered = false;
        success = false;
    } else if (mac->notificationConfirmReceived) {
        mac->notificationConfirmReceived = false;
        success = true;
    }

    mac->plme_set_trx_state_request(phyStatus_t::TRX_OFF);
}


/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_data_transition_t fsm_data_transition_table[FSM_DATA_STATE_QTY][FSM_DATA_STATE_QTY] = {};
//const fsm_data_transition_t fsm_data_transition_table[FSM_DATA_STATE_QTY][FSM_DATA_STATE_QTY] = {
//                    /*ST_IDLE*/             /*ST_WAIT*/                             /*ST_CHANGING*/                                     /*ST_TX_ON*/                    /*ST_SENDING*/                  /*ST_RX_ON*/                    /*ST_RECEIVING*/                        /*ST_TRX_OFF*/
//    /*ST_IDLE*/     {NULL,                  from_idle_to_wait_for_beacon_inactive,  NULL,                                               NULL,                           NULL,                           NULL,                           NULL,                                   NULL,                           },
//    /*ST_WAIT*/     {NULL,                  NULL,                                   from_wait_for_beacon_inactive_to_changing_channel,  NULL,                           NULL,                           NULL,                           NULL,                                   NULL,                           },
//    /*ST_CHANGING*/ {NULL,                  NULL,                                   NULL,                                               from_changing_channel_to_tx_on, NULL,                           from_changing_channel_to_rx_on, NULL,                                   NULL,                           },
//    /*ST_TX_ON*/    {NULL,                  NULL,                                   NULL,                                               NULL,                           from_tx_on_to_sending_data,     NULL,                           NULL,                                   NULL,                           },
//    /*ST_SENDING*/  {NULL,                  NULL,                                   NULL,                                               NULL,                           NULL,                           from_sending_data_to_rx_on,     NULL,                                   NULL,                           },
//    /*ST_RX_ON*/    {NULL,                  NULL,                                   NULL,                                               NULL,                           NULL,                           NULL,                           from_rx_on_to_receiving_data,           NULL,                           },
//    /*ST_RECEIVING*/{NULL,                  NULL,                                   from_receiving_data_to_changing_channel,            NULL,                           NULL,                           NULL,                           from_receiving_data_to_receiving_data,  from_receiving_data_to_trx_off  },
//    /*ST_TRX_OFF*/  {from_trx_off_to_idle,  NULL,                                   NULL,                                               NULL,                           NULL,                           NULL,                           NULL,                                   NULL,                           },
//};
