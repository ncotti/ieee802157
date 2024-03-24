//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/pd.msg.
//

#ifndef __PD_M_H
#define __PD_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class PDDataRequest;
class PDDataConfirm;
class PDDataIndication;
#include "types_m.h" // import types

/**
 * Class generated from <tt>msgs/pd.msg:18</tt> by opp_msgtool.
 * <pre>
 * message PDDataRequest
 * {
 *     uint16_t psduLength;
 *     uint8_t psdu[];
 *     opticalChannel_t bandplanID;
 * }
 * </pre>
 */
class PDDataRequest : public ::omnetpp::cMessage
{
  protected:
    uint16_t psduLength = 0;
    uint8_t *psdu = nullptr;
    size_t psdu_arraysize = 0;
    opticalChannel_t bandplanID = static_cast<opticalChannel_t>(-1);

  private:
    void copy(const PDDataRequest& other);

  protected:
    bool operator==(const PDDataRequest&) = delete;

  public:
    PDDataRequest(const char *name=nullptr, short kind=0);
    PDDataRequest(const PDDataRequest& other);
    virtual ~PDDataRequest();
    PDDataRequest& operator=(const PDDataRequest& other);
    virtual PDDataRequest *dup() const override {return new PDDataRequest(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint16_t getPsduLength() const;
    virtual void setPsduLength(uint16_t psduLength);

    virtual void setPsduArraySize(size_t size);
    virtual size_t getPsduArraySize() const;
    virtual uint8_t getPsdu(size_t k) const;
    virtual void setPsdu(size_t k, uint8_t psdu);
    virtual void insertPsdu(size_t k, uint8_t psdu);
    [[deprecated]] void insertPsdu(uint8_t psdu) {appendPsdu(psdu);}
    virtual void appendPsdu(uint8_t psdu);
    virtual void erasePsdu(size_t k);

    virtual opticalChannel_t getBandplanID() const;
    virtual void setBandplanID(opticalChannel_t bandplanID);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PDDataRequest& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PDDataRequest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>msgs/pd.msg:24</tt> by opp_msgtool.
 * <pre>
 * message PDDataConfirm
 * {
 *     uint8_t status;
 * }
 * </pre>
 */
class PDDataConfirm : public ::omnetpp::cMessage
{
  protected:
    uint8_t status = 0;

  private:
    void copy(const PDDataConfirm& other);

  protected:
    bool operator==(const PDDataConfirm&) = delete;

  public:
    PDDataConfirm(const char *name=nullptr, short kind=0);
    PDDataConfirm(const PDDataConfirm& other);
    virtual ~PDDataConfirm();
    PDDataConfirm& operator=(const PDDataConfirm& other);
    virtual PDDataConfirm *dup() const override {return new PDDataConfirm(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint8_t getStatus() const;
    virtual void setStatus(uint8_t status);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PDDataConfirm& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PDDataConfirm& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>msgs/pd.msg:28</tt> by opp_msgtool.
 * <pre>
 * message PDDataIndication
 * {
 *     uint16_t psduLength;
 *     uint8_t psdu[];
 *     uint32_t ppduLinkQuality;
 * }
 * </pre>
 */
class PDDataIndication : public ::omnetpp::cMessage
{
  protected:
    uint16_t psduLength = 0;
    uint8_t *psdu = nullptr;
    size_t psdu_arraysize = 0;
    uint32_t ppduLinkQuality = 0;

  private:
    void copy(const PDDataIndication& other);

  protected:
    bool operator==(const PDDataIndication&) = delete;

  public:
    PDDataIndication(const char *name=nullptr, short kind=0);
    PDDataIndication(const PDDataIndication& other);
    virtual ~PDDataIndication();
    PDDataIndication& operator=(const PDDataIndication& other);
    virtual PDDataIndication *dup() const override {return new PDDataIndication(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint16_t getPsduLength() const;
    virtual void setPsduLength(uint16_t psduLength);

    virtual void setPsduArraySize(size_t size);
    virtual size_t getPsduArraySize() const;
    virtual uint8_t getPsdu(size_t k) const;
    virtual void setPsdu(size_t k, uint8_t psdu);
    virtual void insertPsdu(size_t k, uint8_t psdu);
    [[deprecated]] void insertPsdu(uint8_t psdu) {appendPsdu(psdu);}
    virtual void appendPsdu(uint8_t psdu);
    virtual void erasePsdu(size_t k);

    virtual uint32_t getPpduLinkQuality() const;
    virtual void setPpduLinkQuality(uint32_t ppduLinkQuality);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PDDataIndication& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PDDataIndication& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline PDDataRequest *fromAnyPtr(any_ptr ptr) { return check_and_cast<PDDataRequest*>(ptr.get<cObject>()); }
template<> inline PDDataConfirm *fromAnyPtr(any_ptr ptr) { return check_and_cast<PDDataConfirm*>(ptr.get<cObject>()); }
template<> inline PDDataIndication *fromAnyPtr(any_ptr ptr) { return check_and_cast<PDDataIndication*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __PD_M_H

