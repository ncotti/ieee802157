/*
 * mac.cpp
 *
 *  Created on: Mar 2, 2024
 *      Author: cotti
 */

#include "mac.h"
#include "fsm_superframe/fsm_superframe.h"
#include "fsm_random_access/fsm_random_access.h"
#include "fsm_reset/fsm_reset.h"
#include "fsm_scan/fsm_scan.h"

using namespace omnetpp;

typedef enum {
    UNSLOTTED_RANDOM_ACCESS,
    SLOTTED_RANDOM_ACCESS,
    UNSLOTTED_CSMA_CA,
    SLOTTED_CSMA_CA,
} transmitType_t;

Define_Module(Mac);


void Mac::initialize() {
    // Initialize with all parameters
    this->varCapabilities.powerSource                       = par("powerSource");
    this->varCapabilities.batteryInformation                = (batteryInformation_t) par("batteryInformation").intValue();
    this->varCapabilities.securityCapability                = false;
    this->varCapabilities.coordinatorCapability             = par("coordinatorCapability");
    this->varCapabilities.traficSupport                     = par("traficSupport");
    this->varCapabilities.broadcastSupport                  = par("broadcastSupport");
    this->varCapabilities.peerToPeerSupport                 = par("peerToPeerSupport");
    this->varCapabilities.starSupport                       = par("starSupport");
    this->varCapabilities.deviceType                        = (deviceType_t) par("deviceType").intValue();
    this->varCapabilities.beaconSupport                     = par("beaconSupport");
    this->varCapabilities.dimmingSupport                    = par("dimmingSupport");
    this->varCapabilities.continuousVisibilityTransmission  = par("continuousVisibilityTransmission");
    this->varCapabilities.cvdSupport                        = par("cvdSupport");
    this->varCapabilities.phyISupport                       = par("phyISupport");
    this->varCapabilities.phyIISupport                      = par("phyIISupport");
    this->varCapabilities.phyIIISupport                     = false;
    this->varCapabilities.colorStabilizationCapability      = (colorStabilizationScheme_t) par("colorStabilizationCapability").intValue();
    this->varCapabilities.maxTxClock                        = (maxSupportedOpticalClock_t) par("maxTxClock").intValue();
    this->varCapabilities.maxRxClock                        = (maxSupportedOpticalClock_t) par("maxRxClock").intValue();
    this->varCapabilities.explicitClockNotificationRequest  = par("explicitClockNotificationRequest");
    this->varCapabilities.ccaSupport                        = par("ccaSupport");
    this->varCapabilities.phyIVSupport                      = false;
    this->varCapabilities.phyVSupport                       = false;
    this->varCapabilities.phyVISupport                      = false;
    this->varCapabilities.numberOfOpticalSources            = par("numberOfOpticalSources");
    this->varCapabilities.multipleDirectionSupport          = par("multipleDirectionSupport");
    this->varCapabilities.numberOfCellsSupported            = par("numberOfCellsSupported");
    this->varCapabilities.bandsUsedForPhy3                  = 0x00;

    // Initialize timers
    this->timerBackoff          = new cMessage("timer_backoff");         // Timer triggered every "aUnitBackoffPeriod" optical clock
    this->timerBeaconInterval   = new cMessage("timer_beacon");
    this->timerOpticalClock     = new cMessage("timer_optical_clock");
    this->timerSlot             = new cMessage("timer_slot");
    this->timerScanDuration     = new cMessage("timer_scan_duration");

    // Initialize notifications
    this->notificationBeaconEnabled = new cMessage("notification_beacon_enabled");

    this->notificationAckNotReceived = new cMessage("notification_ack_not_received");
    this->notificationAckReceived = new cMessage("notification_ack_received");
    this->notificationChannelIdle = new cMessage("notification_channel_idle");
    this->notificationChannelBusy = new cMessage("notification_channel_busy");
    this->notificationStartTx = new cMessage("notification_start_tx");
    this->notificationTxSuccess = new cMessage("notification_tx_success");
    this->notificationTxFailure = new cMessage("notification_tx_failure");
}

void Mac::handleMessage(cMessage *msg) {
    //EV << "Received message " << msg->getName() << " , sending it out again\n";
//    send(msg, "indicationOut"); // send out the message

    // Internal timer or something else
    if (msg->isSelfMessage()) {
        if (msg == timerScanDuration) {
            timerScanDurationTriggered = true;
        }
        fsm_superframe(msg, this);
        fsm_random_access(msg, this);
        fsm_scan(this);
    } else if (msg->arrivedOn("requestIn")) {
        this->processMsgFromHigherLayer(msg);
    } else if (msg->arrivedOn("confirmIn")) {
        this->processMsgFromLowerLayer(msg);
    }

    fsm_reset(this);
}

void Mac::processMsgFromHigherLayer(cMessage *msg) {
    switch(msg->getKind()) {
        case MCPS_DATA_REQUEST: {
            this->mcps_data_request(msg);
            break;
        }

        case MLME_ASSOCIATE_REQUEST: {
            this->mlme_associate_request(msg);
            break;
        }

        case MLME_DISASSOCIATE_REQUEST: {
            this->mlme_disassociate_request(msg);
            break;
        }

        case MLME_GET_REQUEST: {
            this->mlme_get_request(msg);
            break;
        }

        case MLME_RESET_REQUEST: {
            this->mlme_reset_request(msg);
            break;
        }

        case MLME_RX_ENABLE_REQUEST: {
            this->mlme_rx_enable_request(msg);
            break;
        }

        case MLME_SCAN_REQUEST: {
            this->mlme_scan_request(msg);
            break;
        }

        case MLME_SET_REQUEST: {
            this->mlme_set_request(msg);
            break;
        }

        case MLME_START_REQUEST: {
            this->mlme_start_request(msg);
            break;
        }

        case MLME_SYNC_REQUEST: {
            this->mlme_sync_request(msg);
            break;
        }

        case MLME_POLL_REQUEST: {
            this->mlme_poll_request(msg);
            break;
        }
    }
}

void Mac::processMsgFromLowerLayer(cMessage* msg) {
    switch(msg->getKind()) {
        case PLME_CCA_CONFIRM: {
            this->plme_cca_confirm(msg);
            break;
        }

        case PLME_GET_CONFIRM: {
            this->plme_get_confirm(msg);
            break;
        }

        case PLME_SET_CONFIRM: {
            this->plme_set_confirm(msg);
            break;
        }

        case PLME_SET_TRX_STATE_CONFIRM: {
            this->plme_set_trx_state_confirm(msg);
            break;
        }

        case PLME_SWITCH_CONFIRM: {
            this->plme_switch_confirm(msg);
            break;
        }

        case PD_DATA_CONFIRM: {
            this->pd_data_confirm(msg);
            break;
        }
    }

}

/// @brief Reset all PIB MAC attributes to their default values
void Mac::resetPIB(void) {
    if (this->phyType == 1) {
        this->macAckWaitDuration = aUnitBackoffPeriod + aTurnaroundTime_RX_TX_PHYI + 103;   // In optical clocks
    } else {
        this->macAckWaitDuration = aUnitBackoffPeriod + aTurnaroundTime_RX_TX_PHYII + 103;
    }
    this->macAssociatedOWPANCoord = false;
    this->macAssociationPermit = false;
    this->macAutoRequest = true;
    this->macBeaconPayload = nullptr;
    this->macBeaconPayloadLength = 0;
    this->macBeaconOrder = 15;
    this->macBeaconTxTime = 0;
    this->macBSN = intuniform(0, 0xff);
    this->macCoordExtendedAddress = 0;
    this->macCoordShortAddress = 0xffff;
    this->macDSN = intuniform(0, 0xff);
    this->macGTSPermit = true;
    this->macMaxBE = 5;
    this->macMaxCSMABackoffs = 4;
    // macMaxFrameTotalWaitTime is set last.
    this->macMaxFrameRetries = 3;
    this->macMinBE = 3;
    this->macMinLIFSPeriod = 400;
    this->macMinSIFSPeriod = 120;
    this->macOWPANId = 0xffff;
    this->macResponseWaitTime = 32;
    this->macRxOnWhenIdle = false;
    this->macSecurityEnabled = true;
    this->macShortAddress = 0xffff;
    this->macSuperframeOrder = 15;
    this->macTimestampSupported = false; // TODO Implementation specific
    this->macTransactionPersistenceTime = 0x01f4;
    this->macDim = 0;
    this->macNumAcks = 3;
    this->macLinkTimeout = 63;
    this->macDimOverrideRequest              = false;
    this->macDimPWMOverrideRequest           = false;
    this->macDimDataFailureIndication        = false;
    this->macDuringASSOCColor             = 0;
    this->macDuringDISASSOCColor          = 0;
    this->macDuringSCANColor              = 0;
    this->macColorReceived                = 0;
    this->macColorNotReceived             = 0;
    this->macCQIColorLFER                 = 0;
    this->macCQIColorMFER                 = 0;
    this->macCQIColorHFER                 = 0;
    this->macCFAppColor                   = 0;
    this->macColorStabilization =   (colorStabilizationScheme_t) 0;
    this->macColorStabilizationTimer     = 0x00400000;
    this->macUseDimmedOOKmode                = false;
    this->macTimeStampOffset              = 0;
    this->macUseBlinkingNotification         = true;
    this->macBlinkingNotificationFrequency = 0;
    this->macLedIdAmbiguityResolution     = 0;
    this->macFrameControl                = 0;
    this->macSequenceNumber               = 0;
    this->macDestinationOWPANIdentifier  = 0;
    this->macDestinationAddress          = 0;
    this->macSourceOWPANIdentifier       = 0;
    this->macSourceAddress               = 0;
    this->macAcknowledgeField            = NULL;
    this->macFramePayload                = NULL;
    this->macFCS                         = 0;
    this->macMsduLength                  = 0;
    this->macOffsetVPWMDataUsage          = 0;
    this->mac2DCODETxDataType             = 0;

    this->setMacMaxFrameTotalWaitTime();
}

void Mac::setMacMaxFrameTotalWaitTime(void) {
    this->macMaxFrameTotalWaitTime = 0;
    uint8_t m = ((macMaxBE - macMinBE) < macMaxCSMABackoffs) ? (macMaxBE - macMinBE) : macMaxCSMABackoffs;
    for (uint8_t k = 0; k < m ; k++) {
        this->macMaxFrameTotalWaitTime += pow(2, macMinBE);
    }
    this->macMaxFrameTotalWaitTime += (pow(2, macMaxBE) - 1) * (macMaxCSMABackoffs - m);
    this->macMaxFrameTotalWaitTime *= aUnitBackoffPeriod;

    if (this->phyType == 1) {
        this->macMaxFrameTotalWaitTime += aMaxPHYIFrameSize;
    } else {
        this->macMaxFrameTotalWaitTime += aMaxPHYIIFrameSize;
    }
}
