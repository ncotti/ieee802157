/*
 * mac_primitives.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: cotti
 */

#include "mac.h"

#include "fsm_scan/fsm_scan.h"

void Mac::mcps_data_request(cMessage* msg) {
//    MCPSDataRequest *xMsg = new MCPSDataRequest();
//
//    MCPSDataConfirm *xMsg = new MCPSDataConfirm();
//    uint16_t frameControl;
//    bool ack        = msg->getTxOptions() & 0b001;
//    bool gts        = msg->getTxOptions() & 0b010;
//    bool indirectTx = msg->getTxOptions() & 0b100;
//
//    xMsg->setMsduHandle(msg->getMsduHandle());
//    xMsg->setTimestamp(0);
//
//    // Check for all possible errors
//    if (msg->getSrcAddrMode() == addressingMode_t::noAddress && msg->getDstAddrMode() == addressingMode_t::noAddress) {
//        xMsg->setStatus(macStatus_t::INVALID_ADDRESS);
//        //this->mcps_data_confirm(xMsg);
//        delete xMsg;
//        return;
//    }
//
//    // TODO frame pending argument ??
//    //this->macFrameControl = this->getFrameControl(frameType_t::data, framePending, ack, msg->getDstAddrMode(), msg->getSrcAddrMode());
//
//    if (gts) {
//        // TODO If not valid GTS
//        xMsg->setStatus(macStatus_t::INVALID_GTS);
//        //this->mcps_data_confirm(xMsg);
//        delete xMsg;
//        return;
//    }
//
//    if (indirectTx && this->varCapabilities.coordinatorCapability && msg->getDstAddrMode() != addressingMode_t::noAddress) {
//        // TODO add data to list of pending transmissions.
//
//        // TODO if data pending full
//        xMsg->setStatus(macStatus_t::TRANSACTION_OVERFLOW);
//        //this->mcps_data_confirm(xMsg);
//        delete xMsg;
//        return;
//    }
//
//
//
//
//    uint32_t timestamp;
//
//    //if (msduLength > aMaxMACPayloadSize) {
//        // FRAME_TOO_LONG
//    //}
//
//
//    //this->mcps_data_confirm(msduHandle, status, timestamp)
//
//    //delete xMsg;
}

/* Notes:
 * coordAddrMode can only be bit16 or bit64 */
void Mac::mlme_associate_request(cMessage* msg) {
    MLMEAssociateRequest *xMsg = check_and_cast<MLMEAssociateRequest *>(msg);

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

    delete xMsg;

}



/*Notes:
 * deviceAddrMode can only be bit16 or bit64
 * check disassociation reasons */
void Mac::mlme_disassociate_request(cMessage* msg) {
    MLMEDisassociateRequest *xMsg = check_and_cast<MLMEDisassociateRequest *>(msg);

    delete xMsg;
}

/// Done
void Mac::mlme_get_request(cMessage* msg) {
    MLMEGetRequest *xMsg = check_and_cast<MLMEGetRequest *>(msg);
    uint64_t value = 0;
    macStatus_t status = macStatus_t::SUCCESS;

    // Check if it's a MAC PIB attribute
    if (xMsg->getPIBAttribute() >= 0x40 && xMsg->getPIBAttribute() <= 0x7d) {
        switch (xMsg->getPIBAttribute()) {
            case MAC_ACK_WAIT_DURATION:
                value = this->macAckWaitDuration;
                break;
            case MAC_ASSOCIATED_OWPAN_COORD:
                value = this->macAssociatedOWPANCoord;
                break;
            case MAC_ASSOCIATED_PERMIT:
                value = this->macAssociationPermit;
                break;
            case MAC_AUTO_REQUEST:
                value = this->macAutoRequest;
                break;
            case MAC_BEACON_PAYLOAD:
                if (xMsg->getPIBAttributeIndex() >= this->macBeaconPayloadLength) {
                    status = macStatus_t::INVALID_INDEX;
                    value = 0;
                } else {
                    value = this->macBeaconPayload[xMsg->getPIBAttributeIndex()];
                }
                break;
            case MAC_BEACON_PAYLOAD_LENGTH:
                value = this->macBeaconPayloadLength;
                break;
            case MAC_BEACON_ORDER:
                value = this->macBeaconOrder;
                break;
            case MAC_BEACON_TX_TIME:
                value = this->macBeaconTxTime;
                break;
            case MAC_BSN:
                value = this->macBeaconTxTime;
                break;
            case MAC_COORD_EXTENDED_ADDRESS:
                value = this->macCoordExtendedAddress;
                break;
            case MAC_COORD_SHORT_ADDRESS:
                value = this->macCoordShortAddress;
                break;
            case MAC_DSN:
                value = this->macDSN;
                break;
            case MAC_GTS_PERMIT:
                value = this->macGTSPermit;
                break;
            case MAC_MAX_BE:
                value = macMaxBE;
                break;
            case MAC_MAX_CSMA_BACKOFFS:
                value = macMaxCSMABackoffs;
                break;
            case MAC_MAX_FRAME_TOTAL_WAIT_TIME:
                value = macMaxFrameTotalWaitTime;
                break;
            case MAC_MAX_FRAME_RETRIES:
                value = macMaxFrameRetries;
                break;
            case MAC_MIN_BE:
                value = macMinBE;
                break;
            case MAC_MIN_LIFS_PERIOD:
                value = macMinLIFSPeriod;
                break;
            case MAC_MIN_SIFS_PERIOD:
                value = macMinSIFSPeriod;
                break;
            case MAC_OWPAN_ID:
                value = macOWPANId;
                break;
            case MAC_RESPONSE_WAIT_TIME:
                value = macResponseWaitTime;
                break;
            case MAC_RX_ON_WHEN_IDLE:
                value = macRxOnWhenIdle;
                break;
            case MAC_SECURITY_ENABLED:
                value = macSecurityEnabled;
                break;
            case MAC_SHORT_ADDRESS:
                value = macShortAddress;
                break;
            case MAC_SUPERFRAME_ORDER:
                value = macSuperframeOrder;
                break;
            case MAC_TIMESTAMP_SUPPORTED:
                value = macTimestampSupported;
                break;
            case MAC_TRANSACTION_PERSISTENCE_TIME:
                value = macTransactionPersistenceTime;
                break;
            case MAC_DIM:
                value = macDim;
                break;
            case MAC_NUM_ACKS:
                value = macNumAcks;
                break;
            case MAC_LINK_TIME_OUT:
                value = macLinkTimeout;
                break;
            case MAC_DIM_OVERRIDE_REQUEST:
                value = macDimOverrideRequest;
                break;
            case MAC_DIM_PWM_OVERRIDE_REQUEST:
                value = macDimPWMOverrideRequest;
                break;
            case MAC_DIM_DATA_FAILURE_INDICATION:
                value = macDimDataFailureIndication;
                break;
            case MAC_DURING_ASSOC_COLOR:
                value = macDuringASSOCColor;
                break;
            case MAC_DURING_DISASSOC_COLOR:
                value = macDuringDISASSOCColor;
                break;
            case MAC_DURING_SCAN_COLOR:
                value = macDuringSCANColor;
                break;
            case MAC_COLOR_RECEIVED:
                value = macColorReceived;
                break;
            case MAC_COLOR_NOT_RECEIVED:
                value = macColorNotReceived;
                break;
            case MAC_CQI_COLOR_LFER:
                value = macCQIColorLFER;
                break;
            case MAC_CQI_COLOR_MFER:
                value = macCQIColorMFER;
                break;
            case MAC_CQI_COLOR_HFER:
                value = macCQIColorHFER;
                break;
            case MAC_CF_APP_COLOR:
                value = macCFAppColor;
                break;
            case MAC_COLOR_STABILIZATION:
                value = macColorStabilization;
                break;
            case MAC_COLOR_STABILIZATION_TIMER:
                value = macColorStabilizationTimer;
                break;
            case MAC_USE_DIMMED_OOK_MODE:
                value = macUseDimmedOOKmode;
                break;
            case MAC_TIME_STAMP_OFFSET:
                value = macTimeStampOffset;
                break;
            case MAC_USE_BLINKING_NOTIFICATION:
                value = macUseBlinkingNotification;
                break;
            case MAC_BLINKING_NOTIFICATION_FREQUENCY:
                value = macBlinkingNotificationFrequency;
                break;
            case MAC_LED_ID_AMBIGUITY_RESOLUTION:
                value = macLedIdAmbiguityResolution;
                break;
            case MAC_FRAME_CONTROL:
                value = macFrameControl;
                break;
            case MAC_SEQUENCE_NUMBER:
                value = macSequenceNumber;
                break;
            case MAC_DESTINATION_OWPAN_IDENTIFIER:
                value = macDestinationOWPANIdentifier;
                break;
            case MAC_DESTINATION_ADDRESS:
                value = macDestinationAddress;
                break;
            case MAC_SOURCE_OWPAN_IDENTIFIER:
                value = macSourceOWPANIdentifier;
                break;
            case MAC_SOURCE_ADDRESS:
                value = macSourceAddress;
                break;
            case MAC_ACKNOWLEDGE_FIELD:
                value = macAcknowledgeField;
                break;
            case MAC_FRAME_PAYLOAD:
                // TODO check if macMsduLength is the length of frame Payload
                if (xMsg->getPIBAttributeIndex() >= macMsduLength) {
                    status = macStatus_t::INVALID_INDEX;
                    value = 0;
                } else {
                    value = this->macFramePayload[xMsg->getPIBAttributeIndex()];
                }
                break;
            case MAC_FCS:
                value = macFCS;
                break;
            case MAC_MSDU_LENGTH:
                value = macMsduLength;
                break;
            case MAC_OFFSET_VPWM_DATA_USAGE:
                value = macOffsetVPWMDataUsage;
                break;
            case MAC_2DCODE_TX_DATA_TYPE:
                value = mac2DCODETxDataType;
                break;
        }
        this->mlme_get_confirm(status, xMsg->getPIBAttribute(), xMsg->getPIBAttributeIndex(), value);

    } else {
        // Check if it is a PHY attribute
        this->notificationGetRequest = true;
        this->getPIBAttribute = xMsg->getPIBAttribute();
    }

    delete xMsg;
}



void Mac::mlme_gts_request(cMessage* msg) {
    MLMEGTSRequest *xMsg = check_and_cast<MLMEGTSRequest *>(msg);

    delete xMsg;
}

/// DONE
void Mac::mlme_reset_request(cMessage* msg) {
    MLMEResetRequest *xMsg = check_and_cast<MLMEResetRequest *>(msg);

    this->resetSetDefaultPIB = xMsg->getSetDefaultPIB();
    this->notificationResetRequest = true;

    delete xMsg;
}

void Mac::mlme_rx_enable_request(cMessage* msg) {
    MLMERxEnableRequest *xMsg = check_and_cast<MLMERxEnableRequest *>(msg);

    delete xMsg;
}

/// TODO doing
void Mac::mlme_scan_request(cMessage* msg) {
    MLMEScanRequest *xMsg = check_and_cast<MLMEScanRequest *>(msg);

    if (fsm_scan_get_state() != ST_SCAN_IDLE) {
        // Scan already in progress
        this->mlme_scan_confirm(macStatus_t::SCAN_IN_PROGRESS, xMsg->getScanType(), 0xff, 0, nullptr);
    } else if (xMsg->getScanChannels() == 0) {
        // Scan requested, but no channels specified
        // TODO
    } else {
        this->notificationScan = true;

        // Store each optical channel to be checked
        this->scanChannelsLeft = 0;
        for (uint8_t i = 0; i < 8; i++) {
            if (xMsg->getScanChannels() & (0x01 << i)) {
                this->scanChannels[scanChannelsLeft] = (opticalChannel_t) i;
                this->scanChannelsLeft++;
            }
        }

        this->scanDuration = xMsg->getScanDuration();
        this->scanType = xMsg->getScanType();
    }

    delete xMsg;
}


/// Done
void Mac::mlme_set_request(cMessage* msg) {
    MLMESetRequest *xMsg = check_and_cast<MLMESetRequest *>(msg);
    macStatus_t status = macStatus_t::SUCCESS;
    uint64_t value = xMsg->getPIBAttributeValue();

    if (xMsg->getPIBAttribute() >= 0x40 && xMsg->getPIBAttribute() <= 0x7d) {
        switch (xMsg->getPIBAttribute()) {
            case MAC_ACK_WAIT_DURATION:
                status = macStatus_t::READ_ONLY;
                break;
            case MAC_ASSOCIATED_OWPAN_COORD:
                this->macAssociatedOWPANCoord = value;
                break;
            case MAC_ASSOCIATED_PERMIT:
                this->macAssociationPermit = value;
                break;
            case MAC_AUTO_REQUEST:
                this->macAutoRequest = value;
                break;
            case MAC_BEACON_PAYLOAD:
                if (xMsg->getPIBAttributeIndex() >= this->macBeaconPayloadLength) {
                    status = macStatus_t::INVALID_INDEX;
                } else {
                    this->macBeaconPayload[xMsg->getPIBAttributeIndex()] = value;
                }
                break;
            case MAC_BEACON_PAYLOAD_LENGTH:
                if (value > aMaxBeaconPayloadLength) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    this->macBeaconPayloadLength = value;
                }
                break;
            case MAC_BEACON_ORDER:
                if (value > 15) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    this->macBeaconOrder = value;
                }
                break;
            case MAC_BEACON_TX_TIME:
                status = macStatus_t::READ_ONLY;
                break;
            case MAC_BSN:
                this->macBeaconTxTime = value;
                break;
            case MAC_COORD_EXTENDED_ADDRESS:
                this->macCoordExtendedAddress = value;
                break;
            case MAC_COORD_SHORT_ADDRESS:
                this->macCoordShortAddress = value;
                break;
            case MAC_DSN:
                this->macDSN = value;
                break;
            case MAC_GTS_PERMIT:
                this->macGTSPermit = value;
                break;
            case MAC_MAX_BE:
                if (value < 3 || value > 15) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    macMaxBE = value;
                }
                break;
            case MAC_MAX_CSMA_BACKOFFS:
                if (value > 5) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    macMaxCSMABackoffs = value;
                }
                break;
            case MAC_MAX_FRAME_TOTAL_WAIT_TIME:
                status = macStatus_t::READ_ONLY;
                break;
            case MAC_MAX_FRAME_RETRIES:
                if (value > 7) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    macMaxFrameRetries = value;
                }
                break;
            case MAC_MIN_BE:
                if (value > macMaxBE) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    macMinBE = value;
                }
                break;
            case MAC_MIN_LIFS_PERIOD:
                status = macStatus_t::READ_ONLY;
                break;
            case MAC_MIN_SIFS_PERIOD:
                status = macStatus_t::READ_ONLY;
                break;
            case MAC_OWPAN_ID:
                macOWPANId = value;
                break;
            case MAC_RESPONSE_WAIT_TIME:
                if (value < 2 || value > 64) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    macResponseWaitTime = value;
                }
                break;
            case MAC_RX_ON_WHEN_IDLE:
                macRxOnWhenIdle = value;
                break;
            case MAC_SECURITY_ENABLED:
                macSecurityEnabled = value;
                break;
            case MAC_SHORT_ADDRESS:
                macShortAddress = value;
                break;
            case MAC_SUPERFRAME_ORDER:
                status = macStatus_t::READ_ONLY;
                break;
            case MAC_TIMESTAMP_SUPPORTED:
                status = macStatus_t::READ_ONLY;
                break;
            case MAC_TRANSACTION_PERSISTENCE_TIME:
                macTransactionPersistenceTime = value;
                break;
            case MAC_DIM:
                if (value > 1000) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    macDim = value;
                }
                break;
            case MAC_NUM_ACKS:
                macNumAcks = value;
                break;
            case MAC_LINK_TIME_OUT:
                macLinkTimeout = value;
                break;
            case MAC_DIM_OVERRIDE_REQUEST:
                macDimOverrideRequest = value;
                break;
            case MAC_DIM_PWM_OVERRIDE_REQUEST:
                macDimPWMOverrideRequest = value;
                break;
            case MAC_DIM_DATA_FAILURE_INDICATION:
                macDimDataFailureIndication = value;
                break;
            case MAC_DURING_ASSOC_COLOR:
                macDuringASSOCColor = value;
                break;
            case MAC_DURING_DISASSOC_COLOR:
                macDuringDISASSOCColor = value;
                break;
            case MAC_DURING_SCAN_COLOR:
                macDuringSCANColor = value;
                break;
            case MAC_COLOR_RECEIVED:
                macColorReceived = value;
                break;
            case MAC_COLOR_NOT_RECEIVED:
                macColorNotReceived = value;
                break;
            case MAC_CQI_COLOR_LFER:
                macCQIColorLFER = value;
                break;
            case MAC_CQI_COLOR_MFER:
                macCQIColorMFER = value;
                break;
            case MAC_CQI_COLOR_HFER:
                macCQIColorHFER = value;
                break;
            case MAC_CF_APP_COLOR:
                macCFAppColor = value;
                break;
            case MAC_COLOR_STABILIZATION:
                macColorStabilization = (colorStabilizationScheme_t) value;
                break;
            case MAC_COLOR_STABILIZATION_TIMER:
                macColorStabilizationTimer = value;
                break;
            case MAC_USE_DIMMED_OOK_MODE:
                macUseDimmedOOKmode = value;
                break;
            case MAC_TIME_STAMP_OFFSET:
                macTimeStampOffset = value;
                break;
            case MAC_USE_BLINKING_NOTIFICATION:
                macUseBlinkingNotification = value;
                break;
            case MAC_BLINKING_NOTIFICATION_FREQUENCY:
                if (value > 10) {
                    status = macStatus_t::INVALID_PARAMETER;
                } else {
                    macBlinkingNotificationFrequency = value;
                }
                break;
            case MAC_LED_ID_AMBIGUITY_RESOLUTION:
                macLedIdAmbiguityResolution = value;
                break;
            case MAC_FRAME_CONTROL:
                macFrameControl = value;
                break;
            case MAC_SEQUENCE_NUMBER:
                macSequenceNumber = value;
                break;
            case MAC_DESTINATION_OWPAN_IDENTIFIER:
                macDestinationOWPANIdentifier = value;
                break;
            case MAC_DESTINATION_ADDRESS:
                macDestinationAddress = value;
                break;
            case MAC_SOURCE_OWPAN_IDENTIFIER:
                macSourceOWPANIdentifier = value;
                break;
            case MAC_SOURCE_ADDRESS:
                macSourceAddress = value;
                break;
            case MAC_ACKNOWLEDGE_FIELD:
                macAcknowledgeField = value;
                break;
            case MAC_FRAME_PAYLOAD:
                if (xMsg->getPIBAttributeIndex() >= macMsduLength) {
                    status = macStatus_t::INVALID_INDEX;
                } else {
                    this->macFramePayload[xMsg->getPIBAttributeIndex()] = value;
                }
                break;
            case MAC_FCS:
                macFCS = value;
                break;
            case MAC_MSDU_LENGTH:
                macMsduLength = value;
                break;
            case MAC_OFFSET_VPWM_DATA_USAGE:
                macOffsetVPWMDataUsage = value;
                break;
            case MAC_2DCODE_TX_DATA_TYPE:
                mac2DCODETxDataType = value;
                break;
        }

        this->mlme_set_confirm(status, xMsg->getPIBAttribute(), xMsg->getPIBAttributeIndex());
    } else {
        this->notificationSetRequest = true;
        this->setPIBAttribute = xMsg->getPIBAttribute();
        this->setPIBAttributeValue = value;
    }

    delete xMsg;
}

// Optional for RFD
void Mac::mlme_start_request(cMessage* msg) {
    MLMEStartRequest *xMsg = check_and_cast<MLMEStartRequest *>(msg);

    delete xMsg;
}

// Optional for FFD and RFD
void Mac::mlme_sync_request(cMessage* msg) {
    MLMESyncRequest *xMsg = check_and_cast<MLMESyncRequest *>(msg);

    delete xMsg;
}

void Mac::mlme_poll_request(cMessage* msg) {
    MLMEPollRequest *xMsg = check_and_cast<MLMEPollRequest *>(msg);

    delete xMsg;
}


///////////////////////////////////////////////////////////////////////////////

/// Done
void Mac::mcps_data_confirm(uint8_t msduHandle, macStatus_t status, uint32_t timestamp) {
    MCPSDataConfirm *msg = new MCPSDataConfirm();

    msg->setMsduHandle(msduHandle);
    msg->setStatus(status);
    msg->setTimestamp(timestamp);

    msg->setKind(MCPS_DATA_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}

/// Done
void Mac::mlme_associate_confirm(uint16_t assocShortAddress, macStatus_t status, colorStabilizationScheme_t capabilityNegotationResponse, uint8_t securityLevel) {
    MLMEAssociateConfirm *msg = new MLMEAssociateConfirm();

    msg->setAssocShortAddress(assocShortAddress);
    msg->setStatus(status);
    msg->setCapabilityNegotiationResponse(capabilityNegotationResponse);
    msg->setSecurityLevel(securityLevel);

    msg->setKind(MLME_ASSOCIATE_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}

/// Done
void Mac::mlme_disassociate_confirm(macStatus_t status, addressingMode_t deviceAddrMode, uint16_t deviceOWPANId, uint64_t deviceAddress) {
    MLMEDisassociateConfirm *msg = new MLMEDisassociateConfirm();

    msg->setStatus(status);
    msg->setDeviceAddrMode(deviceAddrMode);
    msg->setDeviceOWPANId(deviceOWPANId);
    msg->setDeviceAddress(deviceAddress);

    msg->setKind(MLME_DISASSOCIATE_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}

/// Done
void Mac::mlme_get_confirm(macStatus_t status, PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex, uint64_t PIBAttributeValue){
    MLMEGetConfirm *msg = new MLMEGetConfirm();

    msg->setStatus(status);
    msg->setPIBAttribute(PIBAttribute);
    msg->setPIBAttributeIndex(PIBAttributeIndex);
    msg->setPIBAttributeValue(PIBAttributeValue);

    msg->setKind(MLME_GET_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}


/// Done
void Mac::mlme_gts_confirm(uint8_t GTSCharacteristics, macStatus_t status) {
    MLMEGTSConfirm *msg = new MLMEGTSConfirm();

    msg->setGTSCharacteristics(GTSCharacteristics);
    msg->setStatus(status);

    msg->setKind(MLME_GTS_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}


/// Done
void Mac::mlme_reset_confirm(macStatus_t status) {
    MLMEResetConfirm *msg = new MLMEResetConfirm();

    msg->setStatus(status);

    msg->setKind(MLME_RESET_CONFIRM);
    send(msg, "confirmOut");
}


/// Done
void Mac::mlme_rx_enable_confirm(macStatus_t status) {
    MLMERxEnableConfirm *msg = new MLMERxEnableConfirm();

    msg->setStatus(status);

    msg->setKind(MLME_RX_ENABLE_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}


/// Done
void Mac::mlme_scan_confirm(macStatus_t status, scanType_t scanType, uint8_t unscannedChannels, uint16_t resultListSize, uint8_t* OWPANDescriptorList) {
    MLMEScanConfirm *msg = new MLMEScanConfirm();

    msg->setStatus(status);
    msg->setScanType(scanType);
    msg->setUnscannedChannels(unscannedChannels);
    msg->setResultListSize(resultListSize);

    msg->setOWPANDescriptorListArraySize(resultListSize);
    for (uint16_t i = 0; i < resultListSize; i++) {
        msg->setOWPANDescriptorList(i, OWPANDescriptorList[i]);
    }

    msg->setKind(MLME_SCAN_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}

/// Done
void Mac::mlme_set_confirm(macStatus_t status, PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex) {
    MLMESetConfirm *msg = new MLMESetConfirm();

    msg->setStatus(status);
    msg->setPIBAttribute(PIBAttribute);
    msg->setPIBAttributeIndex(PIBAttributeIndex);

    msg->setKind(MLME_SET_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}

/// Done
void Mac::mlme_start_confirm(macStatus_t status) {
    MLMEStartConfirm *msg = new MLMEStartConfirm();

    msg->setStatus(status);

    msg->setKind(MLME_START_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}

/// Done
void Mac::mlme_poll_confirm(macStatus_t status) {
    MLMEPollConfirm *msg = new MLMEPollConfirm();

    msg->setStatus(status);

    msg->setKind(MLME_POLL_CONFIRM);
    send(msg, "confirmOut");
    delete msg;
}

////////////////////////////////////////////////////////////////////////////////

void Mac::mcps_data_indication(MCPSDataIndication* msg) {

}

void Mac::mlme_associate_indication(MLMEAssociateIndication* msg) {

}


void Mac::mlme_disassociate_indication(MLMEDisassociateIndication* msg) {

}

void Mac::mlme_beacon_notify_indication(MLMEBeaconNotifyIndication* msg) {

}

void Mac::mlme_comm_status_indication(MLMECommStatusIndication* msg) {

}

void Mac::mlme_sync_loss_indication(MLMESyncLossIndication* msg) {

}


////////////////////////////////////////////////////////////////////////////////

void Mac::mlme_associate_response(MLMEAssociateResponse* msg) {

}



//////////////////////////////////////////

void Mac::plme_cca_confirm(cMessage* msg) {
    PLMECCAConfirm *xMsg = check_and_cast<PLMECCAConfirm *>(msg);

    delete xMsg;
}

/// Done
void Mac::plme_get_confirm(cMessage* msg) {
    PLMEGetConfirm *xMsg = check_and_cast<PLMEGetConfirm *>(msg);

    this->confirmPhyStatus = xMsg->getStatus();
    this->getPHYPIBAttributeValue = xMsg->getPIBAttributeValue();

    delete xMsg;
}

/// Done
void Mac::plme_set_confirm(cMessage* msg) {
    PLMESetConfirm *xMsg = check_and_cast<PLMESetConfirm *>(msg);

    this->confirmPhyStatus = xMsg->getStatus();
    this->setPIBAttribute = xMsg->getPIBAttribute();

    delete xMsg;
}

/// Done
void Mac::plme_set_trx_state_confirm(cMessage* msg) {
    PLMESetTrxStateConfirm *xMsg = check_and_cast<PLMESetTrxStateConfirm *>(msg);

    this->confirmPhyStatus = xMsg->getStatus();
    this->notificationConfirmReceived = true;

    delete xMsg;
}

void Mac::plme_switch_confirm(cMessage* msg) {
    PLMESwitchConfirm *xMsg = check_and_cast<PLMESwitchConfirm *>(msg);
    delete xMsg;
}

void Mac::pd_data_confirm(cMessage* msg) {
    PDDataConfirm *xMsg = check_and_cast<PDDataConfirm *>(msg);
    delete xMsg;
}


//////////////////////////////////////////////////////////

/// Done
void Mac::plme_cca_request(void) {
    PLMECCARequest *msg = new PLMECCARequest();

    msg->setKind(PLME_CCA_REQUEST);
    send(msg, "indicationOut");
    delete msg;
}

/// Done
void Mac::plme_get_request(PIBAttribute_t PIBAttribute) {
    PLMEGetRequest *msg = new PLMEGetRequest();

    msg->setPIBAttribute(PIBAttribute);

    msg->setKind(PLME_GET_REQUEST);
    send(msg, "indicationOut");
}

/// Done
void Mac::plme_set_request(PIBAttribute_t PIBAttribute, uint64_t PIBAttributeValue) {
    PLMESetRequest *msg = new PLMESetRequest();

    msg->setPIBAttribute(PIBAttribute);
    msg->setPIBAttributeValue(PIBAttributeValue);

    msg->setKind(PLME_SET_REQUEST);
    send(msg, "indicationOut");
    delete msg;
}

/// Done
void Mac::plme_set_trx_state_request(phyStatus_t state) {
    PLMESetTrxStateRequest *msg = new PLMESetTrxStateRequest();

    msg->setState(state);

    msg->setKind(PLME_SET_TRX_STATE_REQUEST);
    send(msg, "indicationOut");
}

void Mac::plme_switch_request(bool* swBitMap, bool dir) {
    PLMESwitchRequest *msg = new PLMESwitchRequest();

    msg->setKind(PLME_SWITCH_REQUEST);
    send(msg, "indicationOut");
    delete msg;
}

void Mac::pd_data_request(uint64_t psduLength, uint8_t* psdu, uint8_t bandplanID) {
    PDDataRequest *msg = new PDDataRequest();

    msg->setKind(PD_DATA_REQUEST);
    send(msg, "indicationOut");
    delete msg;
}

