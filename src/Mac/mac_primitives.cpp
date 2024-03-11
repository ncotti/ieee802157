/*
 * mac_primitives.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: cotti
 */

#include "mac.h"

void Mac::mcps_data_request(addressingMode_t srcAddrMode,
        addressingMode_t dstAddrMode, uint16_t dstOWPANId, uint64_t dstAddr,
        uint64_t msduLength, uint8_t* msdu, uint8_t msduHandle, uint8_t txOptions,
        security_t security,
        dataRate_t dataRate, bool burstMode,  bool colorReceived, bool colorNotReceived) {

    macStatus_t status = macStatus_t::SUCCESS;
    uint32_t timestamp;

    bool ack        = txOptions & 0b001;
    bool gts        = txOptions & 0b010;
    bool indirectTx = txOptions & 0b100;

    // Check for all possible errors
    if (srcAddrMode == addressingMode_t::noAddress && dstAddrMode == addressingMode_t::noAddress) {
        status = macStatus_t::INVALID_ADDRESS;
    } else if (gts) {
        // If not valid GTS
        status = macStatus_t::INVALID_GTS;
    }



    if (msduLength > aMaxMACPayloadSize) {
        // FRAME_TOO_LONG
    }


    //this->mcps_data_confirm(msduHandle, status, timestamp)
}

void Mac::mcps_data_confirm(uint8_t msduHandle, macStatus_t status, uint32_t timestamp) {
}


void Mac::mcps_data_indication(addressingMode_t dstAddrMode, uint16_t dstOWPANId,
        uint64_t dstAddr, uint64_t msduLength, uint8_t* msdu, uint8_t mpduLinkQuality,
        uint8_t dsn, uint32_t timestamp,
        security_t security,
        dataRate_t dataRate, bool burstMode, bool colorReceived, bool colorNotReceived) {

}



/* Notes:
 * coordAddrMode can only be bit16 or bit64 */
void Mac::mlme_associate_request(opticalChannel_t logicalChannel,
        addressingMode_t coordAddrMode, uint16_t coordOWPANId,
        uint64_t coordAddress, capabilityInformation_t capabilityInformation,
        security_t security, bool colorAssoc) {

    if (this->macAssociationPermit) {
        // Update MAC and PHY attributes
        //this->phy.plme_set_request(phyPIBAtrribute_t::PHY_CURRENT_CHANNEL, (uint64_t) logicalChannel);

        this->macOWPANId = coordOWPANId;

        if (coordAddrMode == addressingMode_t::bit16) {
            this->macCoordExtendedAddress = coordAddress;
        } else if (coordAddrMode == addressingMode_t::bit64) {
            this->macCoordShortAddress = (uint16_t) coordAddress;
        }

        // Optional
        this->mlme_sync_request(logicalChannel, true);

        // Send association command with frame
        // Wait for ack
    }

    else {
        // ignore if not permit
    }





}

void Mac::mlme_associate_indication(uint64_t deviceAddress, capabilityInformation_t capabilityInformation,
        security_t security) {

}

void Mac::mlme_associate_response(uint64_t deviceAddress, uint16_t assocShortAddress,
        macStatus_t status, colorStabilizationScheme_t capabilityNegotiationResponse,
        security_t security) {

}

// Revisar status
void Mac::mlme_associate_confirm(uint16_t assocShortAddress, macStatus_t status,
        colorStabilizationScheme_t capabilityNegotationResponse,
        security_t security) {

}

/*Notes:
 * deviceAddrMode can only be bit16 or bit64
 * check disassociation reasons */
void Mac::mlme_disassociate_request(addressingMode_t deviceAddrMode, uint16_t deviceOWPANId,
        uint64_t deviceAddress, uint8_t disassociateReason, bool txIndirect,
        security_t security, bool colorDisAssoc) {

}

void Mac::mlme_disassociate_indication(uint64_t deviceAddress, uint8_t disassociateReason,
        security_t security) {

}

void Mac::mlme_disassociate_confirm(macStatus_t status, addressingMode_t deviceAddrMode,
        uint16_t deviceOWPANId, uint64_t deviceAddress) {

}

void Mac::mlme_beacon_notify_indication(uint8_t bsn, OWPANDescritpor_t OWPANDescriptor,
        uint8_t pendAddrSpec, uint64_t* addrList, int sduLength, uint8_t* sdu) {

}

void Mac::mlme_get_request(int PIBAttribute, int PIBAttributeIndex) {
//    mlme_get_confirm confirm;
//    confirm.PIBAttribute = PIBAttribute;
//
//    // TODO passing to PHY get.
//    switch (PIBAttribute) {
//        case 0x40:
//            //confirm.PIBAttribute
//        default:
//
//    }
}

void Mac::mlme_get_confirm(macStatus_t status, int PIBAttribute,
        int PIBAttributeIndex, uint64_t PIBAttributeValue){

}

void Mac::mlme_gts_request(uint8_t GTSCharacteristics,
        security_t security) {

}

void Mac::mlme_gts_confirm(uint8_t GTSCharacteristics, macStatus_t status) {

}

void Mac::mlme_reset_request(bool setDefaultPIB) {

    //this->phy.plme_set_trx_state_request(phyStatus_t::FORCE_TRX_OFF);
    //this->waitForConfirm(); // SUCCESS_PHY

    // reset all internal variables to zero

    if (setDefaultPIB) {
        // Reset all PIB parameters to default values
    }

    this->mlme_reset_confirm(macStatus_t::SUCCESS);
}

void Mac::mlme_reset_confirm(macStatus_t status) {

}


void Mac::mlme_rx_enable_request(bool deferPermit, uint32_t rxOnTime, uint32_t rxOnDuration) {

}

void Mac::mlme_rx_enable_confirm(macStatus_t status) {

}

void Mac::mlme_scan_request(scanType_t scanType, uint8_t scanChannels, uint8_t scanDuration,
        security_t security, bool colorScan) {

}

void Mac::mlme_scan_confirm(macStatus_t status, uint8_t scanType, uint8_t unscannedChannels,
        int resultListSize, uint8_t* OWPANDescriptorList) {

}

void Mac::mlme_comm_status_indication(uint16_t OWPANId, addressingMode_t srcAddrMode,
        uint64_t srcAddr, addressingMode_t dstAddrMode, uint64_t dstAddr, macStatus_t status,
        security_t security) {

}

void Mac::mlme_set_request(int PIBAttribute, int PIBAttributeIndex, int PIBAttributeValue) {

}

void Mac::mlme_set_confirm(macStatus_t status, int PIBAttribute, int PIBAttributeIndex) {

}

// Optional for RFD
void Mac::mlme_start_request(uint16_t OWPANId, opticalChannel_t logicalChannel,
        uint32_t startTime, uint8_t beaconOrder, uint8_t superframeOrder,
        bool OWPANCoordinator, bool coordRealignment, security_t coordSecurity,
        security_t beaconSecurity) {

}

void Mac::mlme_start_confirm(macStatus_t status) {

}

// Optional for FFD and RFD
void Mac::mlme_sync_request(opticalChannel_t logicalChannel, bool trackBeacon) {

}

void Mac::mlme_sync_loss_indication(uint8_t lossReason, uint16_t OWPANId,
        opticalChannel_t logicalChannel, security_t security) {

}

void Mac::mlme_poll_request(addressingMode_t coordAddrMode, uint16_t coordOWPANId,
        uint64_t coordAddress, security_t security) {

}

void Mac::mlme_poll_confirm(macStatus_t status) {

}
