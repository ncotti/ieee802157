/*
 * MacFrame.h
 *
 *  Created on: Feb 29, 2024
 *      Author: cotti
 */

#ifndef MACFRAME_H_
#define MACFRAME_H_

#include "MacFrame_m.h"

class MacFrame : public MacFrame_Base {
    typedef enum frameType_t {
        beacon  = 0b000,
        data    = 0b001,
        ack     = 0b010,
        command = 0b011,
        cvd     = 0b100,
    } frameType_t;

    typedef enum addressingMode_t {
        noAddress  = 0b00,
        broadcast   = 0b01,
        bit16       = 0b10,
        bit64       = 0b11,
    } addressingMode_t;

    private:
         void copy(const MacFrame& other);
         void setFrameVersion(void);
         void setFrameType(frameType_t type);
         void setSecurityEnabled(bool enabled);
         void setFramePending(bool pending);
         void setAckRequest(bool enable_ack);
         void setDestinationAddressingMode(addressingMode_t mode);
         void setSourceAddressingMode(addressingMode_t mode);
         addressingMode_t getDestinationAddressingMode(void) const;
         addressingMode_t getSourceAddressingMode(void) const;
         void setAddress(uint16_t destinationID = 0xffff, uint64_t destinationAddress = 0xffff,
                 uint16_t sourceID = 0xffff, uint64_t sourceAddress = 0xffff);
         void setBeaconFrame(bool enableSecurity, bool framePending, uint8_t macBSN,
                 addressingMode_t sourceMode, uint16_t sourceOWPANID, uint64_t sourceAddress);

    public:
         MacFrame(const char *name=nullptr, short kind=0) : MacFrame_Base(name,kind) {}
         MacFrame(const MacFrame& other) : MacFrame_Base(other) {copy(other);}
         MacFrame& operator=(const MacFrame& other) {if (this==&other) return *this; MacFrame_Base::operator=(other); copy(other); return *this;}
         virtual MacFrame *dup() const override {return new MacFrame(*this);}
         // ADD CODE HERE to redefine and implement pure virtual functions from MacFrame_Base
};



#endif /* MACFRAME_H_ */
