#include "fsm_start_net.h"

static uint8_t scanSavedBeaconOrder;
static uint16_t scanSavedNetOWPANId;

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_idle_to_reset(Net* net) {
    net->notificationStartOWPAN = false;
    net->mlme_reset_request(true);
}

static void from_reset_to_set_owpan_id(Net* net) {
    net->notificationConfirmReset = false;
    net->mlme_set_request(PIBAttribute_t::MAC_OWPAN_ID, 0, net->OWPANId);
}

static void from_set_owpan_id_to_scan(Net* net) {
    net->notificationConfirmSet = false;
    // TODO chequear bien los parámetros a pasar
    //net->mlme_scan_request(scanType_t::ACTIVE_SCAN, 0xff, scanDuration, 0, colorScan)
}

static void from_scan_to_set_variables(Net* net) {
    net->notificationConfirmScan = false;
    // TODO get short address from scan
    //net->mlme_set_request(PIBAttribute_t::MAC_SHORT_ADDRESS, PIBAttributeIndex, PIBAttributeValue)
}

static void from_set_variables_to_start(Net* net) {
    net->notificationConfirmSet = false;
    // TODO get parameters
    //net->mlme_start_request(OWPANId, logicalChannel, startTime, beaconOrder, superframeOrder, OWPANCoordinator, coordRealignment, coordRealingmentSecurityLevel, beaconSecurityLevel)
}

static void from_start_to_idle(Net* net) {
    net->notificationConfirmStart = false;
}


/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_start_net_transition_t fsm_start_net_transition_table[FSM_START_NET_STATE_QTY][FSM_START_NET_STATE_QTY] = {
                    /*ST_IDLE*/             /*ST_WAIT*/                             /*ST_CHANGING*/                                     /*ST_TX_ON*/                    /*ST_SENDING*/                  /*ST_RX_ON*/                    /*ST_RECEIVING*/                        /*ST_TRX_OFF*/
    /*ST_IDLE*/     {NULL,                  from_idle_to_wait_for_beacon_inactive,  NULL,                                               NULL,                           NULL,                           NULL,                           NULL,                                   NULL,                           },
    /*ST_WAIT*/     {NULL,                  NULL,                                   from_wait_for_beacon_inactive_to_changing_channel,  NULL,                           NULL,                           NULL,                           NULL,                                   NULL,                           },
    /*ST_CHANGING*/ {NULL,                  NULL,                                   NULL,                                               from_changing_channel_to_tx_on, NULL,                           from_changing_channel_to_rx_on, NULL,                                   NULL,                           },
    /*ST_TX_ON*/    {NULL,                  NULL,                                   NULL,                                               NULL,                           from_tx_on_to_sending_data,     NULL,                           NULL,                                   NULL,                           },
    /*ST_SENDING*/  {NULL,                  NULL,                                   NULL,                                               NULL,                           NULL,                           from_sending_data_to_rx_on,     NULL,                                   NULL,                           },
    /*ST_RX_ON*/    {NULL,                  NULL,                                   NULL,                                               NULL,                           NULL,                           NULL,                           from_rx_on_to_receiving_data,           NULL,                           },
    /*ST_RECEIVING*/{NULL,                  NULL,                                   from_receiving_data_to_changing_channel,            NULL,                           NULL,                           NULL,                           from_receiving_data_to_receiving_data,  from_receiving_data_to_trx_off  },
    /*ST_TRX_OFF*/  {from_trx_off_to_idle,  NULL,                                   NULL,                                               NULL,                           NULL,                           NULL,                           NULL,                                   NULL,                           },
};
