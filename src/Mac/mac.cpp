/*
 * mac.cpp
 *
 *  Created on: Mar 2, 2024
 *      Author: cotti
 */

#include "mac.h"
#include "fsm_superframe/fsm_superframe.h"

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
}

void Mac::handleMessage(cMessage *msg) {
//    EV << "Received message " << msg->getName() << " , sending it out again\n";
//    send(msg, "indicationOut"); // send out the message

    stateSuperframe_t currentSuperframeState = stInactive;

    // Internal timer or something else
    if (msg->isSelfMessage()) {


        currentSuperframeState = fsmSuperframe(currentSuperframeState, msg, this);


        if (msg == this->timerBackoff) {
            scheduleAfter(aUnitBackoffPeriod * this->varOpticalClockDuration, this->timerBackoff);

        // Timer that starts a new beacon frame
        } else if (msg == this->timerBeaconInterval) {
            if (this->macBeaconOrder == 15) {
                // No beacon, nothing to do
                cancelEvent(this->timerBackoff);
            } else {
                // Beacon enabled
                uint16_t beaconInterval = aBaseSuperframeDuration * pow(2, this->macBeaconOrder);
                uint16_t superframeDuration;
                uint16_t slotDuration;

                if (this->macSuperframeOrder == 15) {
                    superframeDuration = 0;
                    slotDuration = 0;
                } else {
                    superframeDuration = aBaseSuperframeDuration * pow(2, this->macSuperframeOrder);
                    slotDuration = aBaseSlotDuration * pow(2, this->macSuperframeOrder);
                }

                rescheduleAfter(this->varOpticalClockDuration, this->timerBackoff);

                // We schedule the last 15 slots, and wait to schedule the first slot after
                // the end of the beacon transmission
                for (uint8_t i = 1; i < aNumSuperframeSlots; i++) {
                    //scheduleAt(simTime() + i * slotDuration * this->varOpticalClockDuration);
                }

                // Schedule next beacon
                //scheduleAt(simTime() + beaconInterval * this->varOpticalClockDuration);
            }
        }
    }
}

//void Mac::sendMessage(uint8_t* msg, uint16_t size, transmitType_t type) {
//
//    // Messages should have a delay between them
//    // TODO burst mode
//    if (size <= aMaxSIFSFrameSize) {
//        scheduleAt(simTime() + macMinSIFSPeriod * this->varOpticalClockDuration);
//    } else {
//        scheduleAt(simTime() + macMinLIFSPeriod * this->varOpticalClockDuration);
//    }
//
//    // TODO send message
//    uint16_t numberOfBackoffs = 0;
//    uint16_t backoffExponent = this->macMinBE;
//
//    if (type == transmitType_t::SLOTTED_RANDOM_ACCESS || type == transmitType_t::SLOTTED_CSMA_CA) {
//        // locate backoff period boundary
//    }
//
//    //
//
//}









