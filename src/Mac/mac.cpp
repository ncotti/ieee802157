/*
 * mac.cpp
 *
 *  Created on: Mar 2, 2024
 *      Author: cotti
 */

#include "mac.h"
#include "fsm_superframe/fsm_superframe.h"
#include "fsm_random_access/fsm_random_access.h"



using namespace omnetpp;

typedef enum {
    KIND_BEACON,
} macMsgKind;

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
        fsm_superframe(msg, this);
       fsm_random_access(msg, this);
    } else if (msg->arrivedOn("requestIn")) {
        EV << "Arrived on requestIn\n";
        this->processMsgFromHigherLayer(msg);
    }
}

void Mac::processMsgFromHigherLayer(cMessage *msg) {
    switch(msg->getKind()) {
        case MLME_ASSOCIATE_REQUEST: {
            MLMEAssociateRequest *xMsg = check_and_cast<MLMEAssociateRequest *>(msg);
            this->mlme_associate_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_DISASSOCIATE_REQUEST: {
            MLMEDisassociateRequest *xMsg = check_and_cast<MLMEDisassociateRequest *>(msg);
            this->mlme_disassociate_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_GET_REQUEST: {
            MLMEGetRequest *xMsg = check_and_cast<MLMEGetRequest *>(msg);
            this->mlme_get_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_RESET_REQUEST: {
            MLMEResetRequest *xMsg = check_and_cast<MLMEResetRequest *>(msg);
            this->mlme_reset_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_RX_ENABLE_REQUEST: {
            MLMERxEnableRequest *xMsg = check_and_cast<MLMERxEnableRequest *>(msg);
            this->mlme_rx_enable_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_SCAN_REQUEST: {
            MLMEScanRequest *xMsg = check_and_cast<MLMEScanRequest *>(msg);
            this->mlme_scan_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_SET_REQUEST: {
            MLMESetRequest *xMsg = check_and_cast<MLMESetRequest *>(msg);
            this->mlme_set_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_START_REQUEST: {
            MLMEStartRequest *xMsg = check_and_cast<MLMEStartRequest *>(msg);
            this->mlme_start_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_SYNC_REQUEST: {
            MLMESyncRequest *xMsg = check_and_cast<MLMESyncRequest *>(msg);
            this->mlme_sync_request(xMsg);
            delete xMsg;
            break;
        }

        case MLME_POLL_REQUEST: {
            MLMEPollRequest *xMsg = check_and_cast<MLMEPollRequest *>(msg);
            this->mlme_poll_request(xMsg);
            break;
        }
    }
}
