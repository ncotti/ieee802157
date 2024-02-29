/*
 * a.cpp
 *
 *  Created on: Feb 28, 2024
 *      Author: cotti
 */

#include "bit_macros.h"
#include <cstdint>


typedef struct MHR_t {
    uint16_t frameControl;
    uint8_t sequenceNumber;
    uint8_t addressingFields[];
    uint8_t auxiliarySecurityHeader[];
} MHR_t;

typedef struct macFrame_t {
    MHR_t MHR;
    uint8_t payload[];
    uint16_t fcs;
} macFrame_t;

typedef enum frameType_t {
    beacon  = 0b000,
    data    = 0b001,
    ack     = 0b010,
    command = 0b011,
    cvd     = 0b100,
} frameType_t;

typedef enum addressingMode_t {
    no_address  = 0b00,
    broadcast   = 0b01,
    bit16       = 0b10,
    bit64       = 0b11,
} addressingMode_t;

inline void prvSetFrameVersion(macFrame_t &frame) {
    BIT_SET(frame.MHR.frameControl, 0b01, 0); // IEEE 802.15.7 2018
}

inline void prvSetFrameType(macFrame_t &frame, frameType_t type) {
    BIT_CLEAR(frame.MHR.frameControl, 0b111, 6);
    BIT_SET(frame.MHR.frameControl, type, 6);
}

inline void prvSetSecurityEnabled(macFrame_t &frame, bool enabled) {
    if (enabled) {
        BIT_SET(frame.MHR.frameControl, 0b1, 9);
    } else {
        BIT_CLEAR(frame.MHR.frameControl, 0b1, 9);
    }
}

inline void prvSetFramePending(macFrame_t &frame, bool pending) {
    if (pending) {
        BIT_SET(frame.MHR.frameControl, 0b1, 10);
    } else {
        BIT_CLEAR(frame.MHR.frameControl, 0b1, 10);
    }
}

inline void prvSetAckRequest(macFrame_t &frame, bool enable_ack) {
    if (enable_ack) {
        BIT_SET(frame.MHR.frameControl, 0b1, 11);
    } else {
        BIT_CLEAR(frame.MHR.frameControl, 0b1, 11);
    }
}

inline void prvSetDestinationAddressingMode(macFrame_t &frame, addressingMode_t mode) {
    BIT_CLEAR(frame.MHR.frameControl, 0b11, 12);
    BIT_SET(frame.MHR.frameControl, mode, 12);
}

inline void prvSetSourceAddressingMode(macFrame_t &frame, addressingMode_t mode) {
    BIT_CLEAR(frame.MHR.frameControl, 0b11, 14);
    BIT_SET(frame.MHR.frameControl, mode, 14);
}

inline addressingMode_t prvGetDestinationAddressingMode(macFrame_t &frame) {
    return (addressingMode_t) (BIT_GET(frame.MHR.frameControl, 12, 0b11));
}

inline addressingMode_t prvGetSourceAddressingMode(macFrame_t &frame) {
    return (addressingMode_t) (BIT_GET(frame.MHR.frameControl, 14, 0b11));
}

inline void prvSetAddress(macFrame_t &frame, uint16_t destinationID = 0, uint64_t destinationAddress = 0,
        uint16_t sourceID = 0, uint64_t sourceAddress = 0) {
    if (prvGetSourceAddressingMode)
}

void init_macFrame() {
    macFrame_t frame;
}



