/*
 * mac_command_frame.cpp
 *
 *  Created on: Mar 5, 2024
 *      Author: cotti
 */

#include "mac.h"

uint16_t Mac::getFrameControl(frameType_t type, bool framePending, bool ackRequest,
        addressingMode_t destinationAddressMode, addressingMode_t sourceAddressMode) {
    uint16_t frameControl = 0;

    BIT_SET(frameControl, 0b01, 0); // Version IEEE 802.15.7 2018
    BIT_SET(frameControl, type, 6);
    BIT_SET(frameControl, (uint8_t) framePending, 10);
    BIT_SET(frameControl, (uint8_t) ackRequest, 11);
    BIT_SET(frameControl, destinationAddressMode, 12);
    BIT_SET(frameControl, sourceAddressMode, 14);

    return frameControl;
}

uint16_t Mac::formatMHR(uint8_t* frame, uint16_t i, uint16_t frameControl, uint8_t sequenceNumber,
        uint16_t destOWPANId, uint64_t destAddress, uint16_t srcOWPANId, uint64_t srcAddress) {

    frame[i++] = (uint8_t) ((frameControl >> 0) & 0xff);
    frame[i++] = (uint8_t) ((frameControl >> 8) & 0xff);

    frame[i++] = sequenceNumber;

    if (destOWPANId != 0) {
        frame[i++] = (uint8_t) ((destOWPANId >> 0)& 0xff);
        frame[i++] = (uint8_t) ((destOWPANId >> 8) & 0xff);
    }

    frame[i++] = (uint8_t) ((destAddress >> 0) & 0xff);
    frame[i++] = (uint8_t) ((destAddress >> 8) & 0xff);
    if (destAddress & 0xffffffffffff0000 != 0) {
        frame[i++] = (uint8_t) ((destAddress >> 16) & 0xff);
        frame[i++] = (uint8_t) ((destAddress >> 24) & 0xff);
        frame[i++] = (uint8_t) ((destAddress >> 32) & 0xff);
        frame[i++] = (uint8_t) ((destAddress >> 40) & 0xff);
        frame[i++] = (uint8_t) ((destAddress >> 48) & 0xff);
        frame[i++] = (uint8_t) ((destAddress >> 56) & 0xff);
    }

    if (srcOWPANId != 0) {
        frame[i++] = (uint8_t) ((srcOWPANId >> 0) & 0xff);
        frame[i++] = (uint8_t) ((srcOWPANId >> 8) & 0xff);
    }

    frame[i++] = (uint8_t) ((srcAddress >> 0) & 0xff);
    frame[i++] = (uint8_t) ((srcAddress >> 8) & 0xff);
    if (srcAddress & 0xffffffffffff0000 != 0) {
        frame[i++] = (uint8_t) ((srcAddress >> 16) & 0xff);
        frame[i++] = (uint8_t) ((srcAddress >> 24) & 0xff);
        frame[i++] = (uint8_t) ((srcAddress >> 32) & 0xff);
        frame[i++] = (uint8_t) ((srcAddress >> 40) & 0xff);
        frame[i++] = (uint8_t) ((srcAddress >> 48) & 0xff);
        frame[i++] = (uint8_t) ((srcAddress >> 56) & 0xff);
    }

    return i;
}


// Destination Address mode should be set to the same mode as indicated in the beacon frame.
void Mac::transmitCommandFrame(commandFrameIdentifier_t id, addressingMode_t destinationAddressMode) {
    uint8_t frame [1000];
    uint16_t i = 0;

    uint16_t frameControl;
    uint8_t sequenceNumber;
    uint16_t destOWPANId;
    uint64_t destAddress;
    uint16_t srcOWPANId;
    uint64_t srcAddress;

    switch(id) {
        case commandFrameIdentifier_t::ASSOCIATION_REQUEST: {
            capabilityInformation_t info = this->varCapabilities;

            frameControl = this->getFrameControl(frameType_t::command, false, true, destinationAddressMode, addressingMode_t::bit64);
            sequenceNumber = this->macDSN;
            destOWPANId = this->macDestinationOWPANIdentifier;
            destAddress = this->macDestinationAddress;
            srcOWPANId = 0xffff;
            srcAddress = aExtendedAddress;

            i = this->formatMHR(frame, i, frameControl, sequenceNumber, destOWPANId, destAddress, srcOWPANId, srcAddress);

            frame[i++] = (uint8_t) id;

            frame[i++] = info.powerSource | info.batteryInformation << 1 |
                    info.securityCapability << 3 | info.coordinatorCapability << 4 |
                    info.traficSupport << 5 | info.broadcastSupport << 6 |
                    info.peerToPeerSupport << 7;
            frame[i++] = info.starSupport | info.deviceType << 1 | info.beaconSupport << 3 |
                    info.dimmingSupport << 4 | info.continuousVisibilityTransmission << 5 |
                    info.cvdSupport << 6;
            frame[i++] = 0; // Reserved from capability information
            frame[i++] = info.phyISupport | info.phyIISupport << 1 | info.phyIIISupport << 2 |
                    info.colorStabilizationCapability << 3 | info.maxTxClock << 5;
            frame[i++] = info.maxRxClock | info.explicitClockNotificationRequest << 3 |
                    info.ccaSupport << 4 | info.phyIVSupport << 5 | info.phyVSupport << 6 |
                    info.phyVISupport << 7;
            frame[i++] = info.numberOfOpticalSources | info.multipleDirectionSupport << 3 |
                    ((info.numberOfCellsSupported & 0b11) << 6);
            frame[i++] = (info.numberOfCellsSupported >> 2);
            frame[i++] = info.bandsUsedForPhy3;

            for(int j=0; j < info.numberOfCellsSupported; j++) {
                // TODO frame[i++] = info.aggregationBitmap[j];
            }
            for(int j=0; j< info.numberOfCellsSupported; j++) {
                // TODO frame[i++] = info.guardBitmap[j];
            }
            break;
        }

        case commandFrameIdentifier_t::ASSOCIATION_RESPONSE: {
            frameControl = this->getFrameControl(frameType_t::command, false, true, addressingMode_t::bit64, addressingMode_t::bit64);
            sequenceNumber = this->macDSN;
            destOWPANId = this->macOWPANId;
            destAddress = this->macDestinationAddress;
            srcOWPANId = 0; // Omitted
            srcAddress = aExtendedAddress;

            // Frame formatting
            i = this->formatMHR(frame, i, frameControl, sequenceNumber, destOWPANId, destAddress, srcOWPANId, srcAddress);

            frame[i++] = (uint8_t) id;

            // frame[i++] = uint16_t shortAddressValue

            // frame[i++] = status;

            frame[i++] = this->macColorStabilization;

            break;
        }

        case commandFrameIdentifier_t::DISASSOCIATION_NOTIFICATION: {
            frameControl = this->getFrameControl(frameType_t::command, false, true, destinationAddressMode, addressingMode_t::bit64);
            sequenceNumber = this->macDSN;
            destOWPANId = this->macOWPANId;
            //destAddress = vary if device or coordinator
            srcOWPANId = 0; // ommited
            srcAddress = aExtendedAddress;

            i = this->formatMHR(frame, i, frameControl, sequenceNumber, destOWPANId, destAddress, srcOWPANId, srcAddress);
            frame[i++] = (uint8_t) id;

           // frame[i++] = table 15 dissasociation reason

            break;
        }

        case commandFrameIdentifier_t::DATA_REQUEST: {
            break;
        }

        case commandFrameIdentifier_t::OWPAN_ID_CONFLICT_NOTIFICATION: {
            frameControl = this->getFrameControl(frameType_t::command, false, true, addressingMode_t::bit64, addressingMode_t::bit64);
            sequenceNumber = this->macBSN;
            destOWPANId = this->macOWPANId;
            destAddress = this->macCoordExtendedAddress;
            srcOWPANId = 0; // omitted
            srcAddress = aExtendedAddress;

            i = this->formatMHR(frame, i, frameControl, sequenceNumber, destOWPANId, destAddress, srcOWPANId, srcAddress);
            frame[i++] = (uint8_t) id;
            break;
        }

        case commandFrameIdentifier_t::BEACON_REQUEST: {
            frameControl = this->getFrameControl(frameType_t::command, false, false, addressingMode_t::bit16, addressingMode_t::noAddress);
            destOWPANId = 0xffff;
            destAddress = 0xffff;
            srcOWPANId = 0; // omitted
            srcAddress = 0; // omitted

            i = this->formatMHR(frame, i, frameControl, sequenceNumber, destOWPANId, destAddress, srcOWPANId, srcAddress);
            frame[i++] = (uint8_t) id;
            break;
        }

        case commandFrameIdentifier_t::COORDINATOR_REALIGNMENT: {
            frameControl = this->getFrameControl(frameType_t::command, false, false, addressingMode_t::bit16, addressingMode_t::bit64);
            destOWPANId = 0xffff;
            destAddress = 0xffff;
            srcOWPANId = this->macOWPANId;
            srcAddress = aExtendedAddress;

            i = this->formatMHR(frame, i, frameControl, sequenceNumber, destOWPANId, destAddress, srcOWPANId, srcAddress);
            frame[i++] = (uint8_t) id;

            frame[i++] = (uint8_t) this->macOWPANId;
            frame[i++] = (uint8_t) ((this->macOWPANId >> 8) & 0xff);

            frame[i++] = (uint8_t) this->macShortAddress;
            frame[i++] = (uint8_t) ((this->macShortAddress >> 8) & 0xff);

            // frame[i++] = logical channel for comm

            frame[i++] = 0xff;
            frame[i++] = 0xff;

            frame[i++] = this->macBSN;

            break;
        }

        case commandFrameIdentifier_t::GTS_REQUEST: {
            // optional command
            break;
        }

        case commandFrameIdentifier_t::BLINKING_NOTIFICATION: {
            // ??
            break;
        }

        case commandFrameIdentifier_t::DIMMING_NOTIFICATION: {
            // ??
            break;
        }

        case commandFrameIdentifier_t::FAST_LINK_RECOVERY: {
            // ??
            break;
        }

        case commandFrameIdentifier_t::MOBILITY_NOTIFICATION: {
            // ??
            break;
        }

        case commandFrameIdentifier_t::GTS_RESPONSE: {
            // optional
            break;
        }

        case commandFrameIdentifier_t::CLOCK_RATE_CHANGE_NOTIFICATION: {
            break;
        }

        case commandFrameIdentifier_t::MULTIPLE_CHANNEL_ASSIGNMENT: {
            break;
        }

        case commandFrameIdentifier_t::BAND_HOPING: {
            break;
        }

        case commandFrameIdentifier_t::COLOR_STABILIZATION_TIMER_NOTIFICATION: {
            break;
        }

        case commandFrameIdentifier_t::COLOR_STABILIZATION_INFORMATION: {
            break;
        }

        case commandFrameIdentifier_t::CVD_DISABLE: {
            break;
        }

        case commandFrameIdentifier_t::INFORMATION_ELEMENT: {
            break;
        }
    }


    // add FEC
    //this->transmitFrame(frame, i);


}


