#include "fsm_scan.h"

static uint8_t scanSavedBeaconOrder;
static uint16_t scanSavedMacOWPANId;

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_idle_to_wait_for_beacon_inactive(Mac* mac) {
    // Suspend beacon transmissions
    scanSavedBeaconOrder = mac->macBeaconOrder;
    mac->macBeaconOrder = 15;
}

static void from_wait_for_beacon_inactive_to_changing_channel(Mac* mac) {
    scanSavedMacOWPANId = mac->macOWPANId;
    mac->macOWPANId = 0xffff;

    mac->scanChannelsLeft--;
    mac->plme_set_request(PIBAttribute_t::PHY_CURRENT_CHANNEL, mac->scanChannels[mac->scanChannelsLeft]);
}

static void from_changing_channel_to_tx_on(Mac* mac) {
    mac->notificationConfirmReceived = false;
    mac->plme_set_trx_state_request(phyStatus_t::TX_ON);
}

static void from_changing_channel_to_rx_on(Mac* mac) {
    mac->notificationConfirmReceived = false;
    mac->plme_set_trx_state_request(phyStatus_t::RX_ON);
}

static void from_tx_on_to_sending_data(Mac* mac) {
    mac->notificationConfirmReceived = false;
    // TODO send data
    //mac->pd_data_request(psduLength, psdu, bandplanID)
}

static void from_sending_data_to_rx_on(Mac* mac) {
    mac->notificationConfirmReceived = false;
    mac->plme_set_trx_state_request(phyStatus_t::RX_ON);
}

static void from_rx_on_to_receiving_data(Mac* mac) {
    mac->notificationConfirmReceived = false;
    mac->scheduleAfter(aBaseSuperframeDuration * (pow(2, mac->scanDuration) + 1), mac->timerScanDuration);
}

static void from_receiving_data_to_receiving_data(Mac* mac) {
    if (mac->pdDataConfirmReceived) {
        mac->pdDataConfirmReceived = false;
        // TODO do something when a beacon was received during the scan
    }
}

static void from_receiving_data_to_changing_channel(Mac* mac) {
    mac->timerScanDurationTriggered = false;
    mac->scanChannelsLeft--;
    mac->plme_set_request(PIBAttribute_t::PHY_CURRENT_CHANNEL, mac->scanChannels[mac->scanChannelsLeft]);
}

static void from_receiving_data_to_trx_off(Mac* mac) {
    mac->timerScanDurationTriggered = false;
    mac->plme_set_trx_state_request(phyStatus_t::TRX_OFF);
}

static void from_trx_off_to_idle(Mac* mac) {
    mac->notificationConfirmReceived = false;
    // TODO
    //mac->mlme_scan_confirm(macStatus_t::SUCCESS, mac->scanType, unscannedChannels, resultListSize, OWPANDescriptorList)
    mac->macBeaconOrder = scanSavedBeaconOrder;
    mac->macOWPANId = scanSavedMacOWPANId;

}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_scan_transition_t fsm_scan_transition_table[FSM_SCAN_STATE_QTY][FSM_SCAN_STATE_QTY] = {
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
