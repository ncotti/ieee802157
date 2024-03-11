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

/******************************************************************************
 * MHR: MAC Header
 *****************************************************************************/
void MacFrame::setMHR(frameType_t type, bool securityEnabled, bool framePending, bool ackRequest,
        addressingMode_t destinationAddressMode, addressingMode_t sourceAddressMode, uint8_t sequenceNumber,
        uint16_t destinationOWPANId, uint64_t destinationAddress, uint16_t sourceOWPANId, uint64_t sourceAddress) {
    this->setFrameVersion();
    this->setFrameType(type);
    this->setSecurityEnabled(securityEnabled);
    this->setFramePending(framePending);
    this->setAckRequest(ackRequest);
    this->setDestinationAddressingMode(destinationAddressMode);
    this->setSourceAddressingMode(sourceAddressMode);
    this->setSequenceNumber(sequenceNumber);
    this->setAddress(destinationOWPANId, destinationAddress, sourceOWPANId, sourceAddress);
}

/********************* Frame Control *****************************************/
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

addressingMode_t MacFrame::getDestinationAddressingMode(void) const {
    return (addressingMode_t) (BIT_GET(this->frameControl, 12, 0b11));
}

addressingMode_t MacFrame::getSourceAddressingMode(void) const {
    return (addressingMode_t) (BIT_GET(this->frameControl, 14, 0b11));
}

/************************ Addressing Fields **********************************/
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

/******************************************************************************
 * Beacon Frame
 *****************************************************************************/
//void MacFrame::setBeaconFrame(bool securityEnabled, bool framePending, uint8_t macBSN,
//        addressingMode_t sourceAddressMode, uint16_t sourceOWPANId, uint64_t sourceAddress) {
//
//    if (sourceAddressMode == addressingMode_t::broadcast || sourceAddressMode == addressingMode_t::noAddress) {
//            throw omnetpp::cRuntimeError("Wrong source addressing mode in MAC beacon frame");
//    }
//
//    this->setMHR(frameType_t::beacon, securityEnabled, framePending, false,
//            addressingMode_t::noAddress, sourceAddressMode, macBSN,
//            0, 0, sourceOWPANId, sourceAddress);
//
//    // TODO beacon payload
//    this->setBeaconPayload()
//}


// TODO
//void MacFrame::setBeaconPayload(uint8_t beaconOrder, uint8_t superframeOrder, uint8_t finalCAPSlot,
//        bool isCoordinator, bool associationPermit, bool cellSearchEn,
//        uint8_t GTSDescriptorCount, bool GTSPermit) {
//
//    this->setBeaconOrder(beaconOrder);
//    this->setSuperframeOrder(superframeOrder);
//    this->setFinalCAPSlot(finalCAPSlot);
//    this->setOWPANCoordinator(isCoordinator);
//    this->setAssociationPermit(associationPermit);
//    this->setCellSearchEn(cellSearchEn);
//
//    // TODO
//
//
//}

/************************* Superframe Specification **************************/
void MacFrame::setBeaconOrder(uint8_t beaconOrder) {
    if (beaconOrder > 15) {
        throw omnetpp::cRuntimeError("Beacon Order > 15");
    }
    if (this->getPayloadArraySize() > 0) {
        BIT_SET(this->payload[0], beaconOrder, 0)
    } else {
        this->appendPayload(beaconOrder & 0xf);
    }
}

void MacFrame::setSuperframeOrder(uint8_t superframeOrder) {
    if (superframeOrder > 15) {
        throw omnetpp::cRuntimeError("Superframe Order > 15");
    }
    BIT_SET(this->payload[0], superframeOrder, 4);
}

void MacFrame::setFinalCAPSlot(uint8_t finalCAPSlot) {
    if (finalCAPSlot > 15) {
        throw omnetpp::cRuntimeError("finalCAPSlot > 15");
    }
    if (this->getPayloadArraySize() > 1) {
        BIT_SET(this->payload[1], finalCAPSlot, 0);
    } else {
        this->appendPayload(finalCAPSlot & 0xf);
    }
}

void MacFrame::setOWPANCoordinator(bool isCoordinator) {
    if (isCoordinator) {
        BIT_SET(this->payload[1], 0b1, 5);
    } else {
        BIT_CLEAR(this->payload[1], 0b1, 5);
    }
}

void MacFrame::setAssociationPermit(bool associationPermit) {
    if (associationPermit) {
        BIT_SET(this->payload[1], 0b1, 6);
    } else {
        BIT_CLEAR(this->payload[1], 0b1, 6);
    }
}

void MacFrame::setCellSearchEn(bool cellSearchEn) {
    if (cellSearchEn) {
        BIT_SET(this->payload[1], 0b1, 7);
    } else {
        BIT_CLEAR(this->payload[1], 0b1, 7);
    }
}

//void MacFrame::setGTSSpecification(uint8_t GTSDescriptorCount, bool GTSPermit) {
//    if (GTSDescriptorCount > 7) {
//        throw omnetpp::cRuntimeError("GTS Descriptor Count > 7");
//    }
//    if(getPayloadArraySize() > 2) {
//        this->appendPayload(GTSDescriptorCount & 0x7 | (((uint8_t) GTSPermit) << 7));
//    } else {
//        BIT_CLEAR(this->payload[2], 0b111, 0);
//        BIT_SET(this->payload[2], GTSDescriptorCount, 0);
//        if (GTSPermit) {
//            BIT_SET(this->payload[2], 0b1, 7);
//        } else {
//            BIT_CLEAR(this->payload[2], 0b1, 7);
//        }
//    }
//}

//void MacFrame::setGTSDirections(uint8_t directionsMask) {
//    // TODO, habría que ver como agregar nuevo GTS
//    // GTS descriptor count
//    if (BIT_GET(this->payload[2], 0, 0b111) == 0) {
//        throw omnetpp::cRuntimeError("Trying to set GTS directions with no GTS");
//    } else {
//        this->insertPayload(3, directionsMask);
//    }
//}
//
//void MacFrame::setGTSList(uint16_t deviceShortAddress, uint8_t startingSlot, uint8_t length) {
//    // TODO, habría que ver como agregar nuevo GTS
//    if ()
//}


/******************************************************************************
 * Data Frame
 *****************************************************************************/
void MacFrame::setDataFrame(bool securityEnabled, bool framePending, bool ackRequest,
        addressingMode_t destinationAddressMode, addressingMode_t sourceAddressMode,
        uint8_t macDSN, uint16_t destinationOWPANId, uint64_t destinationAddress,
        uint16_t sourceOWPANId, uint64_t sourceAddress,
        dataType_t dataType, uint8_t numberOfPPDU, uint8_t* data, size_t size) {
    this->setMHR(frameType_t::data, securityEnabled, framePending, ackRequest,
            destinationAddressMode, sourceAddressMode, macDSN, destinationOWPANId,
            destinationAddress, sourceOWPANId, sourceAddress);

    this->setDataPayload(dataType, numberOfPPDU, data, size);


}


void MacFrame::setDataPayload(dataType_t dataType, uint8_t numberOfPPDU, uint8_t* data, size_t size) {
    this->setPayloadArraySize(size + 1);
    this->setPayload(0, (uint8_t) dataType | ((numberOfPPDU & 0x3f) << 2) );

    for (size_t i = 0; i < size; i++) {
        this->setPayload(i+1, data[i]);
    }
}

/******************************************************************************
 * Acknowledgment Frame
******************************************************************************/

//void MacFrame::setAckFrame() {
    //this->setMHR(frameType_t::ack, fal, framePending, ackRequest, destinationAddressMode, sourceAddressMode, sequenceNumber, destinationOWPANId, destinationAddress, sourceOWPANId, sourceAddress)
//}

//void MacFrame::setAckPayload() {

//}

