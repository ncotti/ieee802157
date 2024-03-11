/*
 * mac_procedures.cpp
 *
 *  Created on: Mar 3, 2024
 *      Author: cotti
 */

#include "mac.h"

void Mac::association(bool activeScan) {
    //this->mlme_reset_request(true);
    if (activeScan) {
        //this->activeChannelScan();
    } else {
        this->passiveChannelScan();
    }

    //this->mlme_associate_request(logicalChannel, coordAddrMode, coordOWPANId, coordAddress, capabilityInformation, security, colorAssoc)
}

void Mac::randomAccess() {
    //uint32_t numberOfBackoffs = 0; // NB
    //uint32_t backoffExponent = this->macMinBE;    // BE

    //if ()

}

/******************************************************************************
 * @brief: Start and active scan.
 *
 * @param scanChannels: 8bit value, where each bit corresponds with an optical
 *  channel, as shown in opticalChannel_t.
 *
******************************************************************************/
void Mac::activeChannelScan(uint8_t scanChannels) {
    uint16_t oldMacOWPANId = this->macOWPANId;
    this->macOWPANId = 0xffff;

    //this->mlme_scan_request(scanType_t::ACTIVE_SCAN, scanChannels, scanDuration, security, colorScan)

    for (uint8_t i = 0; i < 8; i++) {
        if (scanChannels & (0x01 << i)) {
            //this->phy.plme_set_request("phyCurrentChannel", "correct channel")
            // send beacon request command
        }
    }



    //this->mlme_scan_confirm();
    this->macOWPANId = oldMacOWPANId;
}

void Mac::passiveChannelScan() {

}

