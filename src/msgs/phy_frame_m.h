//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/phy_frame.msg.
//

#ifndef __PHY_FRAME_M_H
#define __PHY_FRAME_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class PhyFrame;
#include "types_m.h" // import types

/**
 * Class generated from <tt>msgs/phy_frame.msg:21</tt> by opp_msgtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet PhyFrame
 * {
 *     // Preamble
 *     uint64_t FLP = 0xaaaaaaaaaaaaaaaa; 	// 64 to 16384 bits
 *     uint64 TDP;	// 60 bits
 * 
 *     // PHY header
 *     bool burstMode;						// 1 bit
 *     opticalChannel_t channelNumber;		// 3 bit
 *     MCS_t MCSId;						// 6 bit
 *     uint16_t psduLength;				// 16 bit
 *     bool dimmedOOKExtension;			// 1 bit
 *     // RESERVED							// 5 bit
 * 
 *     // HCS (Header check sequence)
 *     uint16_t HCS;						// 16 bit CRC
 * 
 *     // Optional Fields
 *     // Present ONLY when transmitting with 200 kHz
 *     uint8_t tailBits;					// 6 bits
 * 
 *     // Present ONLY when dimmedOOKExtension == true
 *     uint16_t compensationLength;			// 10 bit
 *     uint8_t resyncLength = 15;				// 4 bit
 *     uint16_t subframeLength;				// 10 bit
 *     uint8_t OFCS;							// 8 bit, some kind of CRC
 * 
 * 
 * 
 *     // PSDU (payload)
 *     uint8_t payload[];
 * }
 * </pre>
 */
class PhyFrame : public ::omnetpp::cPacket
{
  protected:
    uint64_t FLP = 0xaaaaaaaaaaaaaaaa;
    uint64_t TDP = 0;
    bool burstMode = false;
    opticalChannel_t channelNumber = static_cast<opticalChannel_t>(-1);
    MCS_t MCSId = static_cast<MCS_t>(-1);
    uint16_t psduLength = 0;
    bool dimmedOOKExtension = false;
    uint16_t HCS = 0;
    uint8_t tailBits = 0;
    uint16_t compensationLength = 0;
    uint8_t resyncLength = 15;
    uint16_t subframeLength = 0;
    uint8_t OFCS = 0;
    uint8_t *payload = nullptr;
    size_t payload_arraysize = 0;

  private:
    void copy(const PhyFrame& other);

  protected:
    bool operator==(const PhyFrame&) = delete;

  public:
    PhyFrame(const char *name=nullptr, short kind=0);
    PhyFrame(const PhyFrame& other);
    virtual ~PhyFrame();
    PhyFrame& operator=(const PhyFrame& other);
    virtual PhyFrame *dup() const override {return new PhyFrame(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint64_t getFLP() const;
    virtual void setFLP(uint64_t FLP);

    virtual uint64_t getTDP() const;
    virtual void setTDP(uint64_t TDP);

    virtual bool getBurstMode() const;
    virtual void setBurstMode(bool burstMode);

    virtual opticalChannel_t getChannelNumber() const;
    virtual void setChannelNumber(opticalChannel_t channelNumber);

    virtual MCS_t getMCSId() const;
    virtual void setMCSId(MCS_t MCSId);

    virtual uint16_t getPsduLength() const;
    virtual void setPsduLength(uint16_t psduLength);

    virtual bool getDimmedOOKExtension() const;
    virtual void setDimmedOOKExtension(bool dimmedOOKExtension);

    virtual uint16_t getHCS() const;
    virtual void setHCS(uint16_t HCS);

    virtual uint8_t getTailBits() const;
    virtual void setTailBits(uint8_t tailBits);

    virtual uint16_t getCompensationLength() const;
    virtual void setCompensationLength(uint16_t compensationLength);

    virtual uint8_t getResyncLength() const;
    virtual void setResyncLength(uint8_t resyncLength);

    virtual uint16_t getSubframeLength() const;
    virtual void setSubframeLength(uint16_t subframeLength);

    virtual uint8_t getOFCS() const;
    virtual void setOFCS(uint8_t OFCS);

    virtual void setPayloadArraySize(size_t size);
    virtual size_t getPayloadArraySize() const;
    virtual uint8_t getPayload(size_t k) const;
    virtual void setPayload(size_t k, uint8_t payload);
    virtual void insertPayload(size_t k, uint8_t payload);
    [[deprecated]] void insertPayload(uint8_t payload) {appendPayload(payload);}
    virtual void appendPayload(uint8_t payload);
    virtual void erasePayload(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PhyFrame& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PhyFrame& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline PhyFrame *fromAnyPtr(any_ptr ptr) { return check_and_cast<PhyFrame*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __PHY_FRAME_M_H

