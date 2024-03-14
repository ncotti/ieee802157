/*
 * mac_primitives.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: cotti
 */

#include "mac.h"

void Mac::mcps_data_request(MCPSDataRequest* msg) {

//    macStatus_t status = macStatus_t::SUCCESS;
//    uint32_t timestamp;
//
//    bool ack        = txOptions & 0b001;
//    bool gts        = txOptions & 0b010;
//    bool indirectTx = txOptions & 0b100;
//
//    // Check for all possible errors
//    if (srcAddrMode == addressingMode_t::noAddress && dstAddrMode == addressingMode_t::noAddress) {
//        status = macStatus_t::INVALID_ADDRESS;
//    } else if (gts) {
//        // If not valid GTS
//        status = macStatus_t::INVALID_GTS;
//    }
//
//
//
//    if (msduLength > aMaxMACPayloadSize) {
//        // FRAME_TOO_LONG
//    }


    //this->mcps_data_confirm(msduHandle, status, timestamp)
}

void Mac::mcps_data_confirm(MCPSDataConfirm* msg) {
}


void Mac::mcps_data_indication(MCPSDataIndication* msg) {

}



/* Notes:
 * coordAddrMode can only be bit16 or bit64 */
void Mac::mlme_associate_request(MLMEAssociateRequest* msg) {

//    if (this->macAssociationPermit) {
//        // Update MAC and PHY attributes
//        PLMESetRequest *xMsg = new PLMESetRequest();
//
//        xMsg->setKind(PLME_SET_REQUEST);
//        xMsg->setPIBAttribute(phyPIBAtrribute_t::PHY_CURRENT_CHANNEL);
//        xMsg->setPIBAttributeValue(msg->getLogicalChannel());
//
//        send(xMsg, "indicationOut");
//
//        this->macOWPANId = coordOWPANId;
//
//        if (coordAddrMode == addressingMode_t::bit16) {
//            this->macCoordExtendedAddress = coordAddress;
//        } else if (coordAddrMode == addressingMode_t::bit64) {
//            this->macCoordShortAddress = (uint16_t) coordAddress;
//        }
//
//        // Optional
//        this->mlme_sync_request(logicalChannel, true);
//
//        // Send association command with frame
//        // Wait for ack
//    }
//
//    else {
//        // ignore if not permit
//    }





}

void Mac::mlme_associate_indication(MLMEAssociateIndication* msg) {

}

void Mac::mlme_associate_response(MLMEAssociateResponse* msg) {

}

// Revisar status
void Mac::mlme_associate_confirm(MLMEAssociateConfirm* msg) {

}

/*Notes:
 * deviceAddrMode can only be bit16 or bit64
 * check disassociation reasons */
void Mac::mlme_disassociate_request(MLMEDisassociateRequest* msg) {

}

void Mac::mlme_disassociate_indication(MLMEDisassociateIndication* msg) {

}

void Mac::mlme_disassociate_confirm(MLMEDisassociateConfirm* msg) {

}

void Mac::mlme_beacon_notify_indication(MLMEBeaconNotifyIndication* msg) {

}

void Mac::mlme_get_request(MLMEGetRequest* msg) {
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

void Mac::mlme_get_confirm(MLMEGetConfirm* msg) {

}

void Mac::mlme_gts_request(MLMEGTSRequest* msg) {

}

void Mac::mlme_gts_confirm(MLMEGTSConfirm* msg) {

}

void Mac::mlme_reset_request(MLMEResetRequest* msg) {

    //this->phy.plme_set_trx_state_request(phyStatus_t::FORCE_TRX_OFF);
    //this->waitForConfirm(); // SUCCESS_PHY

    // reset all internal variables to zero

//    if (setDefaultPIB) {
//        // Reset all PIB parameters to default values
//    }
//
//    this->mlme_reset_confirm(macStatus_t::SUCCESS);
}

void Mac::mlme_reset_confirm(MLMEResetConfirm* msg) {

}


void Mac::mlme_rx_enable_request(MLMERxEnableRequest* msg) {

}

void Mac::mlme_rx_enable_confirm(MLMERxEnableConfirm* msg) {

}

void Mac::mlme_scan_request(MLMEScanRequest* msg) {

}

void Mac::mlme_scan_confirm(MLMEScanConfirm* msg) {

}

void Mac::mlme_comm_status_indication(MLMECommStatusIndication* msg) {

}

void Mac::mlme_set_request(MLMESetRequest* msg) {

}

void Mac::mlme_set_confirm(MLMESetConfirm* msg) {

}

// Optional for RFD
void Mac::mlme_start_request(MLMEStartRequest* msg) {

}

void Mac::mlme_start_confirm(MLMEStartConfirm* msg) {

}

// Optional for FFD and RFD
void Mac::mlme_sync_request(MLMESyncRequest* msg) {

}

void Mac::mlme_sync_loss_indication(MLMESyncLossIndication* msg) {

}

void Mac::mlme_poll_request(MLMEPollRequest* msg) {

}

void Mac::mlme_poll_confirm(MLMEPollConfirm* msg) {

}
