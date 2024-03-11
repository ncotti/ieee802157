/*
 * MacFrame.h
 *
 *  Created on: Feb 29, 2024
 *      Author: cotti
 */

#ifndef MACFRAME_H_
#define MACFRAME_H_

#include "MacFrame_m.h"
#include "../types.h"

/* MAC sublayer constants, as defined in Table 61 of the IEEE 802.15.7 */
#define aBaseSlotDuration           60
#define aBaseSuperframeDuration     (aBaseSlotDuration * aNumSuperframeSlots)
#define aExtendedAddress            ((uint64_t) 0x1) // Device specific
#define aGTSDDescPersistenceTime    4
#define aMaxBeaconOverhead          75
#define aMaxBeaconPayloadLength     (aMaxPHYFrameSize - aMaxBeaconOverhead)
#define aMaxLostBeacons             4
#define aMaxMACPayloadSize          (aMaxPHYFrameSize - AMinMPDUOOverhead)
#define aMaxMPDUUnsecuredOverhead   25
#define aMaxSIFSFrameSize           18
#define aMinCAPLength               440
#define aMinMPDUOverhead            9
#define aNumSuperframeSlots         16
#define aUnitBackoffPeriod          20




class MacFrame : public MacFrame_Base {

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
         void setMHR(frameType_t type, bool securityEnabled, bool framePending, bool ackRequest,
                          addressingMode_t destinationAddressMode, addressingMode_t sourceAddressMode, uint8_t sequenceNumber,
                          uint16_t destinationOWPANId, uint64_t destinationAddress, uint16_t sourceOWPANId, uint64_t sourceAddress);

         void setBeaconOrder(uint8_t beaconOrder);
         void setSuperframeOrder(uint8_t superframeOrder);
         void setFinalCAPSlot(uint8_t finalCAPSlot);
         void setOWPANCoordinator(bool isCoordinator);
         void setAssociationPermit(bool associationPermit);
         void setCellSearchEn(bool cellSearchEn);

         //void setGTSDirections(uint8_t directionsMask);

         void setDataPayload(dataType_t dataType, uint8_t numberOfPPDU, uint8_t* data, size_t size);


    public:
         MacFrame(const char *name=nullptr, short kind=0) : MacFrame_Base(name,kind) {}
         MacFrame(const MacFrame& other) : MacFrame_Base(other) {copy(other);}
         MacFrame& operator=(const MacFrame& other) {if (this==&other) return *this; MacFrame_Base::operator=(other); copy(other); return *this;}
         virtual MacFrame *dup() const override {return new MacFrame(*this);}
         // ADD CODE HERE to redefine and implement pure virtual functions from MacFrame_Base

//         void setBeaconFrame(bool enableSecurity, bool framePending, uint8_t macBSN,
//                 addressingMode_t sourceMode, uint16_t sourceOWPANID, uint64_t sourceAddress);

         void setDataFrame(bool securityEnabled, bool framePending, bool ackRequest,
                 addressingMode_t destinationAddressMode, addressingMode_t sourceAddressMode,
                 uint8_t macDSN, uint16_t destinationOWPANId, uint64_t destinationAddress,
                 uint16_t sourceOWPANId, uint64_t sourceAddress,
                 dataType_t dataType, uint8_t numberOfPPDU, uint8_t* data, size_t size);




};



#endif /* MACFRAME_H_ */
