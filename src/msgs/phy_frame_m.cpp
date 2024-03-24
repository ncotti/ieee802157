//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/phy_frame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "phy_frame_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(PhyFrame)

PhyFrame::PhyFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

PhyFrame::PhyFrame(const PhyFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

PhyFrame::~PhyFrame()
{
    delete [] this->payload;
}

PhyFrame& PhyFrame::operator=(const PhyFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PhyFrame::copy(const PhyFrame& other)
{
    this->FLP = other.FLP;
    this->TDP = other.TDP;
    this->burstMode = other.burstMode;
    this->channelNumber = other.channelNumber;
    this->MCSId = other.MCSId;
    this->psduLength = other.psduLength;
    this->dimmedOOKExtension = other.dimmedOOKExtension;
    this->HCS = other.HCS;
    this->tailBits = other.tailBits;
    this->compensationLength = other.compensationLength;
    this->resyncLength = other.resyncLength;
    this->subframeLength = other.subframeLength;
    this->OFCS = other.OFCS;
    delete [] this->payload;
    this->payload = (other.payload_arraysize==0) ? nullptr : new uint8_t[other.payload_arraysize];
    payload_arraysize = other.payload_arraysize;
    for (size_t i = 0; i < payload_arraysize; i++) {
        this->payload[i] = other.payload[i];
    }
}

void PhyFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->FLP);
    doParsimPacking(b,this->TDP);
    doParsimPacking(b,this->burstMode);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->MCSId);
    doParsimPacking(b,this->psduLength);
    doParsimPacking(b,this->dimmedOOKExtension);
    doParsimPacking(b,this->HCS);
    doParsimPacking(b,this->tailBits);
    doParsimPacking(b,this->compensationLength);
    doParsimPacking(b,this->resyncLength);
    doParsimPacking(b,this->subframeLength);
    doParsimPacking(b,this->OFCS);
    b->pack(payload_arraysize);
    doParsimArrayPacking(b,this->payload,payload_arraysize);
}

void PhyFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->FLP);
    doParsimUnpacking(b,this->TDP);
    doParsimUnpacking(b,this->burstMode);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->MCSId);
    doParsimUnpacking(b,this->psduLength);
    doParsimUnpacking(b,this->dimmedOOKExtension);
    doParsimUnpacking(b,this->HCS);
    doParsimUnpacking(b,this->tailBits);
    doParsimUnpacking(b,this->compensationLength);
    doParsimUnpacking(b,this->resyncLength);
    doParsimUnpacking(b,this->subframeLength);
    doParsimUnpacking(b,this->OFCS);
    delete [] this->payload;
    b->unpack(payload_arraysize);
    if (payload_arraysize == 0) {
        this->payload = nullptr;
    } else {
        this->payload = new uint8_t[payload_arraysize];
        doParsimArrayUnpacking(b,this->payload,payload_arraysize);
    }
}

uint64_t PhyFrame::getFLP() const
{
    return this->FLP;
}

void PhyFrame::setFLP(uint64_t FLP)
{
    this->FLP = FLP;
}

uint64_t PhyFrame::getTDP() const
{
    return this->TDP;
}

void PhyFrame::setTDP(uint64_t TDP)
{
    this->TDP = TDP;
}

bool PhyFrame::getBurstMode() const
{
    return this->burstMode;
}

void PhyFrame::setBurstMode(bool burstMode)
{
    this->burstMode = burstMode;
}

opticalChannel_t PhyFrame::getChannelNumber() const
{
    return this->channelNumber;
}

void PhyFrame::setChannelNumber(opticalChannel_t channelNumber)
{
    this->channelNumber = channelNumber;
}

MCS_t PhyFrame::getMCSId() const
{
    return this->MCSId;
}

void PhyFrame::setMCSId(MCS_t MCSId)
{
    this->MCSId = MCSId;
}

uint16_t PhyFrame::getPsduLength() const
{
    return this->psduLength;
}

void PhyFrame::setPsduLength(uint16_t psduLength)
{
    this->psduLength = psduLength;
}

bool PhyFrame::getDimmedOOKExtension() const
{
    return this->dimmedOOKExtension;
}

void PhyFrame::setDimmedOOKExtension(bool dimmedOOKExtension)
{
    this->dimmedOOKExtension = dimmedOOKExtension;
}

uint16_t PhyFrame::getHCS() const
{
    return this->HCS;
}

void PhyFrame::setHCS(uint16_t HCS)
{
    this->HCS = HCS;
}

uint8_t PhyFrame::getTailBits() const
{
    return this->tailBits;
}

void PhyFrame::setTailBits(uint8_t tailBits)
{
    this->tailBits = tailBits;
}

uint16_t PhyFrame::getCompensationLength() const
{
    return this->compensationLength;
}

void PhyFrame::setCompensationLength(uint16_t compensationLength)
{
    this->compensationLength = compensationLength;
}

uint8_t PhyFrame::getResyncLength() const
{
    return this->resyncLength;
}

void PhyFrame::setResyncLength(uint8_t resyncLength)
{
    this->resyncLength = resyncLength;
}

uint16_t PhyFrame::getSubframeLength() const
{
    return this->subframeLength;
}

void PhyFrame::setSubframeLength(uint16_t subframeLength)
{
    this->subframeLength = subframeLength;
}

uint8_t PhyFrame::getOFCS() const
{
    return this->OFCS;
}

void PhyFrame::setOFCS(uint8_t OFCS)
{
    this->OFCS = OFCS;
}

size_t PhyFrame::getPayloadArraySize() const
{
    return payload_arraysize;
}

uint8_t PhyFrame::getPayload(size_t k) const
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    return this->payload[k];
}

void PhyFrame::setPayloadArraySize(size_t newSize)
{
    uint8_t *payload2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = payload_arraysize < newSize ? payload_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        payload2[i] = this->payload[i];
    for (size_t i = minSize; i < newSize; i++)
        payload2[i] = 0;
    delete [] this->payload;
    this->payload = payload2;
    payload_arraysize = newSize;
}

void PhyFrame::setPayload(size_t k, uint8_t payload)
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    this->payload[k] = payload;
}

void PhyFrame::insertPayload(size_t k, uint8_t payload)
{
    if (k > payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    size_t newSize = payload_arraysize + 1;
    uint8_t *payload2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        payload2[i] = this->payload[i];
    payload2[k] = payload;
    for (i = k + 1; i < newSize; i++)
        payload2[i] = this->payload[i-1];
    delete [] this->payload;
    this->payload = payload2;
    payload_arraysize = newSize;
}

void PhyFrame::appendPayload(uint8_t payload)
{
    insertPayload(payload_arraysize, payload);
}

void PhyFrame::erasePayload(size_t k)
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    size_t newSize = payload_arraysize - 1;
    uint8_t *payload2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        payload2[i] = this->payload[i];
    for (i = k; i < newSize; i++)
        payload2[i] = this->payload[i+1];
    delete [] this->payload;
    this->payload = payload2;
    payload_arraysize = newSize;
}

class PhyFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_FLP,
        FIELD_TDP,
        FIELD_burstMode,
        FIELD_channelNumber,
        FIELD_MCSId,
        FIELD_psduLength,
        FIELD_dimmedOOKExtension,
        FIELD_HCS,
        FIELD_tailBits,
        FIELD_compensationLength,
        FIELD_resyncLength,
        FIELD_subframeLength,
        FIELD_OFCS,
        FIELD_payload,
    };
  public:
    PhyFrameDescriptor();
    virtual ~PhyFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(PhyFrameDescriptor)

PhyFrameDescriptor::PhyFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PhyFrame)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

PhyFrameDescriptor::~PhyFrameDescriptor()
{
    delete[] propertyNames;
}

bool PhyFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PhyFrame *>(obj)!=nullptr;
}

const char **PhyFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PhyFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PhyFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 14+base->getFieldCount() : 14;
}

unsigned int PhyFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_FLP
        FD_ISEDITABLE,    // FIELD_TDP
        FD_ISEDITABLE,    // FIELD_burstMode
        FD_ISEDITABLE,    // FIELD_channelNumber
        FD_ISEDITABLE,    // FIELD_MCSId
        FD_ISEDITABLE,    // FIELD_psduLength
        FD_ISEDITABLE,    // FIELD_dimmedOOKExtension
        FD_ISEDITABLE,    // FIELD_HCS
        FD_ISEDITABLE,    // FIELD_tailBits
        FD_ISEDITABLE,    // FIELD_compensationLength
        FD_ISEDITABLE,    // FIELD_resyncLength
        FD_ISEDITABLE,    // FIELD_subframeLength
        FD_ISEDITABLE,    // FIELD_OFCS
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_payload
    };
    return (field >= 0 && field < 14) ? fieldTypeFlags[field] : 0;
}

const char *PhyFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "FLP",
        "TDP",
        "burstMode",
        "channelNumber",
        "MCSId",
        "psduLength",
        "dimmedOOKExtension",
        "HCS",
        "tailBits",
        "compensationLength",
        "resyncLength",
        "subframeLength",
        "OFCS",
        "payload",
    };
    return (field >= 0 && field < 14) ? fieldNames[field] : nullptr;
}

int PhyFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "FLP") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "TDP") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "burstMode") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "channelNumber") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "MCSId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "psduLength") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "dimmedOOKExtension") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "HCS") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "tailBits") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "compensationLength") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "resyncLength") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "subframeLength") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "OFCS") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 13;
    return base ? base->findField(fieldName) : -1;
}

const char *PhyFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",    // FIELD_FLP
        "uint64",    // FIELD_TDP
        "bool",    // FIELD_burstMode
        "opticalChannel_t",    // FIELD_channelNumber
        "MCS_t",    // FIELD_MCSId
        "uint16_t",    // FIELD_psduLength
        "bool",    // FIELD_dimmedOOKExtension
        "uint16_t",    // FIELD_HCS
        "uint8_t",    // FIELD_tailBits
        "uint16_t",    // FIELD_compensationLength
        "uint8_t",    // FIELD_resyncLength
        "uint16_t",    // FIELD_subframeLength
        "uint8_t",    // FIELD_OFCS
        "uint8_t",    // FIELD_payload
    };
    return (field >= 0 && field < 14) ? fieldTypeStrings[field] : nullptr;
}

const char **PhyFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_channelNumber: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_MCSId: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PhyFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_channelNumber:
            if (!strcmp(propertyName, "enum")) return "opticalChannel_t";
            return nullptr;
        case FIELD_MCSId:
            if (!strcmp(propertyName, "enum")) return "MCS_t";
            return nullptr;
        default: return nullptr;
    }
}

int PhyFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        case FIELD_payload: return pp->getPayloadArraySize();
        default: return 0;
    }
}

void PhyFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        case FIELD_payload: pp->setPayloadArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PhyFrame'", field);
    }
}

const char *PhyFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PhyFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        case FIELD_FLP: return uint642string(pp->getFLP());
        case FIELD_TDP: return uint642string(pp->getTDP());
        case FIELD_burstMode: return bool2string(pp->getBurstMode());
        case FIELD_channelNumber: return enum2string(pp->getChannelNumber(), "opticalChannel_t");
        case FIELD_MCSId: return enum2string(pp->getMCSId(), "MCS_t");
        case FIELD_psduLength: return ulong2string(pp->getPsduLength());
        case FIELD_dimmedOOKExtension: return bool2string(pp->getDimmedOOKExtension());
        case FIELD_HCS: return ulong2string(pp->getHCS());
        case FIELD_tailBits: return ulong2string(pp->getTailBits());
        case FIELD_compensationLength: return ulong2string(pp->getCompensationLength());
        case FIELD_resyncLength: return ulong2string(pp->getResyncLength());
        case FIELD_subframeLength: return ulong2string(pp->getSubframeLength());
        case FIELD_OFCS: return ulong2string(pp->getOFCS());
        case FIELD_payload: return ulong2string(pp->getPayload(i));
        default: return "";
    }
}

void PhyFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        case FIELD_FLP: pp->setFLP(string2uint64(value)); break;
        case FIELD_TDP: pp->setTDP(string2uint64(value)); break;
        case FIELD_burstMode: pp->setBurstMode(string2bool(value)); break;
        case FIELD_channelNumber: pp->setChannelNumber((opticalChannel_t)string2enum(value, "opticalChannel_t")); break;
        case FIELD_MCSId: pp->setMCSId((MCS_t)string2enum(value, "MCS_t")); break;
        case FIELD_psduLength: pp->setPsduLength(string2ulong(value)); break;
        case FIELD_dimmedOOKExtension: pp->setDimmedOOKExtension(string2bool(value)); break;
        case FIELD_HCS: pp->setHCS(string2ulong(value)); break;
        case FIELD_tailBits: pp->setTailBits(string2ulong(value)); break;
        case FIELD_compensationLength: pp->setCompensationLength(string2ulong(value)); break;
        case FIELD_resyncLength: pp->setResyncLength(string2ulong(value)); break;
        case FIELD_subframeLength: pp->setSubframeLength(string2ulong(value)); break;
        case FIELD_OFCS: pp->setOFCS(string2ulong(value)); break;
        case FIELD_payload: pp->setPayload(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PhyFrame'", field);
    }
}

omnetpp::cValue PhyFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        case FIELD_FLP: return (omnetpp::intval_t)(pp->getFLP());
        case FIELD_TDP: return omnetpp::checked_int_cast<omnetpp::intval_t>(pp->getTDP());
        case FIELD_burstMode: return pp->getBurstMode();
        case FIELD_channelNumber: return static_cast<int>(pp->getChannelNumber());
        case FIELD_MCSId: return static_cast<int>(pp->getMCSId());
        case FIELD_psduLength: return (omnetpp::intval_t)(pp->getPsduLength());
        case FIELD_dimmedOOKExtension: return pp->getDimmedOOKExtension();
        case FIELD_HCS: return (omnetpp::intval_t)(pp->getHCS());
        case FIELD_tailBits: return (omnetpp::intval_t)(pp->getTailBits());
        case FIELD_compensationLength: return (omnetpp::intval_t)(pp->getCompensationLength());
        case FIELD_resyncLength: return (omnetpp::intval_t)(pp->getResyncLength());
        case FIELD_subframeLength: return (omnetpp::intval_t)(pp->getSubframeLength());
        case FIELD_OFCS: return (omnetpp::intval_t)(pp->getOFCS());
        case FIELD_payload: return (omnetpp::intval_t)(pp->getPayload(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PhyFrame' as cValue -- field index out of range?", field);
    }
}

void PhyFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        case FIELD_FLP: pp->setFLP(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_TDP: pp->setTDP(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_burstMode: pp->setBurstMode(value.boolValue()); break;
        case FIELD_channelNumber: pp->setChannelNumber(static_cast<opticalChannel_t>(value.intValue())); break;
        case FIELD_MCSId: pp->setMCSId(static_cast<MCS_t>(value.intValue())); break;
        case FIELD_psduLength: pp->setPsduLength(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_dimmedOOKExtension: pp->setDimmedOOKExtension(value.boolValue()); break;
        case FIELD_HCS: pp->setHCS(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_tailBits: pp->setTailBits(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_compensationLength: pp->setCompensationLength(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_resyncLength: pp->setResyncLength(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_subframeLength: pp->setSubframeLength(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_OFCS: pp->setOFCS(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_payload: pp->setPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PhyFrame'", field);
    }
}

const char *PhyFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr PhyFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PhyFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyFrame *pp = omnetpp::fromAnyPtr<PhyFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PhyFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

