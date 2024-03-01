/*
 * a.cpp
 *
 *  Created on: Feb 28, 2024
 *      Author: cotti
 */

#include "../bit_macros.h"
#include <cstdint>
#include "MacFrame.h"

Register_Class(MacFrame);

void MacFrame::copy(const MacFrame& other) {
    // TODO Complete copy constructor
}

void MacFrame::setFrameVersion(void) {
    BIT_SET(this->frameControl, 0b01, 0); // IEEE 802.15.7 2018
}

void MacFrame::setFrameType(frameType_t type) {
    BIT_CLEAR(this->frameControl, 0b111, 6);
    BIT_SET(this->frameControl, type, 6);
}

void MacFrame::setSecurityEnabled(bool enabled) {
    if (enabled) {
        BIT_SET(this->frameControl, 0b1, 9);
    } else {
        BIT_CLEAR(this->frameControl, 0b1, 9);
    }
}

void MacFrame::setFramePending(bool pending) {
    if (pending) {
        BIT_SET(this->frameControl, 0b1, 10);
    } else {
        BIT_CLEAR(this->frameControl, 0b1, 10);
    }
}

void MacFrame::setAckRequest(bool enable_ack) {
    if (enable_ack) {
        BIT_SET(this->frameControl, 0b1, 11);
    } else {
        BIT_CLEAR(this->frameControl, 0b1, 11);
    }
}

void MacFrame::setDestinationAddressingMode(addressingMode_t mode) {
    BIT_CLEAR(this->frameControl, 0b11, 12);
    BIT_SET(this->frameControl, mode, 12);
}

void MacFrame::setSourceAddressingMode(addressingMode_t mode) {
    BIT_CLEAR(this->frameControl, 0b11, 14);
    BIT_SET(this->frameControl, mode, 14);
}

MacFrame::addressingMode_t MacFrame::getDestinationAddressingMode(void) const {
    return (addressingMode_t) (BIT_GET(this->frameControl, 12, 0b11));
}

MacFrame::addressingMode_t MacFrame::getSourceAddressingMode(void) const {
    return (addressingMode_t) (BIT_GET(this->frameControl, 14, 0b11));
}

void MacFrame::setAddress(uint16_t destinationID, uint64_t destinationAddress,
        uint16_t sourceID, uint64_t sourceAddress) {
    switch (this->getDestinationAddressingMode()) {
        case addressingMode_t::noAddress: {
            // No addressing fields should be transmitted
            break;
        }
        case addressingMode_t::broadcast: {
            this->setDestinationAddressArraySize(1);
            this->setDestinationAddress(0, 0xffff);
            break;
        }
        case addressingMode_t::bit16: {
            this->setDestinationOWPANIdArraySize(1);
            this->setDestinationOWPANId(0, destinationID);

            this->setDestinationAddressArraySize(1);
            this->setDestinationAddress(0, (uint16_t) destinationAddress);
            break;
        }
        case addressingMode_t::bit64: {
            this->setDestinationOWPANIdArraySize(1);
            this->setDestinationOWPANId(0, destinationID);

            this->setDestinationAddressArraySize(4);
            this->setDestinationAddress(0, (uint16_t) destinationAddress);
            this->setDestinationAddress(1, (uint16_t) (destinationAddress >> 16));
            this->setDestinationAddress(2, (uint16_t) (destinationAddress >> 32));
            this->setDestinationAddress(3, (uint16_t) (destinationAddress >> 48));
            break;
        }
    }

    switch (this->getSourceAddressingMode()) {
        case addressingMode_t::noAddress: {
            // No addressing fields should be transmitted
            break;
        }
        case addressingMode_t::broadcast: {
            this->setSourceOWPANIdArraySize(1);
            this->setSourceOWPANId(0, sourceID);
            break;
        }
        case addressingMode_t::bit16: {
            this->setSourceOWPANIdArraySize(1);
            this->setSourceOWPANId(0, sourceID);

            this->setSourceAddressArraySize(1);
            this->setSourceAddress(0, (uint16_t) sourceAddress);
            break;
        }
        case addressingMode_t::bit64: {
            this->setSourceOWPANIdArraySize(1);
            this->setSourceOWPANId(0, sourceID);

            this->setSourceAddressArraySize(4);
            this->setSourceAddress(0, (uint16_t) sourceAddress);
            this->setSourceAddress(1, (uint16_t) (sourceAddress >> 16));
            this->setSourceAddress(2, (uint16_t) (sourceAddress >> 32));
            this->setSourceAddress(3, (uint16_t) (sourceAddress >> 48));
            break;
        }
    }

}

void MacFrame::setBeaconFrame(bool enableSecurity, bool framePending, uint8_t macBSN,
        addressingMode_t sourceMode, uint16_t sourceOWPANID, uint64_t sourceAddress) {
    this->setFrameVersion();
    this->setFrameType(frameType_t::beacon);
    this->setSecurityEnabled(enableSecurity);
    this->setFramePending(framePending);
    this->setAckRequest(false);
    this->setDestinationAddressingMode(addressingMode_t::noAddress);

    if (sourceMode == addressingMode_t::broadcast || sourceMode == addressingMode_t::noAddress) {
        throw omnetpp::cRuntimeError("Wrong source addressing mode in MAC beacon frame");
    }
    this->setSourceAddressingMode(sourceMode);

    this->setSequenceNumber(macBSN);

    this->setAddress(0, 0, sourceOWPANID, sourceAddress);

    // TODO beacon payload

}

