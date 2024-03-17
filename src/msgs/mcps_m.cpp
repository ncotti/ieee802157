//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/mcps.msg.
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
#include "mcps_m.h"

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

Register_Class(MCPSDataRequest)

MCPSDataRequest::MCPSDataRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MCPSDataRequest::MCPSDataRequest(const MCPSDataRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MCPSDataRequest::~MCPSDataRequest()
{
    delete [] this->msdu;
}

MCPSDataRequest& MCPSDataRequest::operator=(const MCPSDataRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MCPSDataRequest::copy(const MCPSDataRequest& other)
{
    this->srcAddrMode = other.srcAddrMode;
    this->dstAddrMode = other.dstAddrMode;
    this->dstOWPANId = other.dstOWPANId;
    this->dstAddr = other.dstAddr;
    this->msduLength = other.msduLength;
    delete [] this->msdu;
    this->msdu = (other.msdu_arraysize==0) ? nullptr : new uint8_t[other.msdu_arraysize];
    msdu_arraysize = other.msdu_arraysize;
    for (size_t i = 0; i < msdu_arraysize; i++) {
        this->msdu[i] = other.msdu[i];
    }
    this->msduHandle = other.msduHandle;
    this->txOptions = other.txOptions;
    this->securityLevel = other.securityLevel;
    this->dataRate = other.dataRate;
    this->burstMode = other.burstMode;
    this->colorReceived = other.colorReceived;
    this->colorNotReceived = other.colorNotReceived;
}

void MCPSDataRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->srcAddrMode);
    doParsimPacking(b,this->dstAddrMode);
    doParsimPacking(b,this->dstOWPANId);
    doParsimPacking(b,this->dstAddr);
    doParsimPacking(b,this->msduLength);
    b->pack(msdu_arraysize);
    doParsimArrayPacking(b,this->msdu,msdu_arraysize);
    doParsimPacking(b,this->msduHandle);
    doParsimPacking(b,this->txOptions);
    doParsimPacking(b,this->securityLevel);
    doParsimPacking(b,this->dataRate);
    doParsimPacking(b,this->burstMode);
    doParsimPacking(b,this->colorReceived);
    doParsimPacking(b,this->colorNotReceived);
}

void MCPSDataRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddrMode);
    doParsimUnpacking(b,this->dstAddrMode);
    doParsimUnpacking(b,this->dstOWPANId);
    doParsimUnpacking(b,this->dstAddr);
    doParsimUnpacking(b,this->msduLength);
    delete [] this->msdu;
    b->unpack(msdu_arraysize);
    if (msdu_arraysize == 0) {
        this->msdu = nullptr;
    } else {
        this->msdu = new uint8_t[msdu_arraysize];
        doParsimArrayUnpacking(b,this->msdu,msdu_arraysize);
    }
    doParsimUnpacking(b,this->msduHandle);
    doParsimUnpacking(b,this->txOptions);
    doParsimUnpacking(b,this->securityLevel);
    doParsimUnpacking(b,this->dataRate);
    doParsimUnpacking(b,this->burstMode);
    doParsimUnpacking(b,this->colorReceived);
    doParsimUnpacking(b,this->colorNotReceived);
}

addressingMode_t MCPSDataRequest::getSrcAddrMode() const
{
    return this->srcAddrMode;
}

void MCPSDataRequest::setSrcAddrMode(addressingMode_t srcAddrMode)
{
    this->srcAddrMode = srcAddrMode;
}

addressingMode_t MCPSDataRequest::getDstAddrMode() const
{
    return this->dstAddrMode;
}

void MCPSDataRequest::setDstAddrMode(addressingMode_t dstAddrMode)
{
    this->dstAddrMode = dstAddrMode;
}

uint16_t MCPSDataRequest::getDstOWPANId() const
{
    return this->dstOWPANId;
}

void MCPSDataRequest::setDstOWPANId(uint16_t dstOWPANId)
{
    this->dstOWPANId = dstOWPANId;
}

uint64_t MCPSDataRequest::getDstAddr() const
{
    return this->dstAddr;
}

void MCPSDataRequest::setDstAddr(uint64_t dstAddr)
{
    this->dstAddr = dstAddr;
}

uint16_t MCPSDataRequest::getMsduLength() const
{
    return this->msduLength;
}

void MCPSDataRequest::setMsduLength(uint16_t msduLength)
{
    this->msduLength = msduLength;
}

size_t MCPSDataRequest::getMsduArraySize() const
{
    return msdu_arraysize;
}

uint8_t MCPSDataRequest::getMsdu(size_t k) const
{
    if (k >= msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    return this->msdu[k];
}

void MCPSDataRequest::setMsduArraySize(size_t newSize)
{
    uint8_t *msdu2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = msdu_arraysize < newSize ? msdu_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        msdu2[i] = this->msdu[i];
    for (size_t i = minSize; i < newSize; i++)
        msdu2[i] = 0;
    delete [] this->msdu;
    this->msdu = msdu2;
    msdu_arraysize = newSize;
}

void MCPSDataRequest::setMsdu(size_t k, uint8_t msdu)
{
    if (k >= msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    this->msdu[k] = msdu;
}

void MCPSDataRequest::insertMsdu(size_t k, uint8_t msdu)
{
    if (k > msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    size_t newSize = msdu_arraysize + 1;
    uint8_t *msdu2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        msdu2[i] = this->msdu[i];
    msdu2[k] = msdu;
    for (i = k + 1; i < newSize; i++)
        msdu2[i] = this->msdu[i-1];
    delete [] this->msdu;
    this->msdu = msdu2;
    msdu_arraysize = newSize;
}

void MCPSDataRequest::appendMsdu(uint8_t msdu)
{
    insertMsdu(msdu_arraysize, msdu);
}

void MCPSDataRequest::eraseMsdu(size_t k)
{
    if (k >= msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    size_t newSize = msdu_arraysize - 1;
    uint8_t *msdu2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        msdu2[i] = this->msdu[i];
    for (i = k; i < newSize; i++)
        msdu2[i] = this->msdu[i+1];
    delete [] this->msdu;
    this->msdu = msdu2;
    msdu_arraysize = newSize;
}

uint8_t MCPSDataRequest::getMsduHandle() const
{
    return this->msduHandle;
}

void MCPSDataRequest::setMsduHandle(uint8_t msduHandle)
{
    this->msduHandle = msduHandle;
}

uint8_t MCPSDataRequest::getTxOptions() const
{
    return this->txOptions;
}

void MCPSDataRequest::setTxOptions(uint8_t txOptions)
{
    this->txOptions = txOptions;
}

uint8_t MCPSDataRequest::getSecurityLevel() const
{
    return this->securityLevel;
}

void MCPSDataRequest::setSecurityLevel(uint8_t securityLevel)
{
    this->securityLevel = securityLevel;
}

MCS_t MCPSDataRequest::getDataRate() const
{
    return this->dataRate;
}

void MCPSDataRequest::setDataRate(MCS_t dataRate)
{
    this->dataRate = dataRate;
}

bool MCPSDataRequest::getBurstMode() const
{
    return this->burstMode;
}

void MCPSDataRequest::setBurstMode(bool burstMode)
{
    this->burstMode = burstMode;
}

bool MCPSDataRequest::getColorReceived() const
{
    return this->colorReceived;
}

void MCPSDataRequest::setColorReceived(bool colorReceived)
{
    this->colorReceived = colorReceived;
}

bool MCPSDataRequest::getColorNotReceived() const
{
    return this->colorNotReceived;
}

void MCPSDataRequest::setColorNotReceived(bool colorNotReceived)
{
    this->colorNotReceived = colorNotReceived;
}

class MCPSDataRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddrMode,
        FIELD_dstAddrMode,
        FIELD_dstOWPANId,
        FIELD_dstAddr,
        FIELD_msduLength,
        FIELD_msdu,
        FIELD_msduHandle,
        FIELD_txOptions,
        FIELD_securityLevel,
        FIELD_dataRate,
        FIELD_burstMode,
        FIELD_colorReceived,
        FIELD_colorNotReceived,
    };
  public:
    MCPSDataRequestDescriptor();
    virtual ~MCPSDataRequestDescriptor();

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

Register_ClassDescriptor(MCPSDataRequestDescriptor)

MCPSDataRequestDescriptor::MCPSDataRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MCPSDataRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MCPSDataRequestDescriptor::~MCPSDataRequestDescriptor()
{
    delete[] propertyNames;
}

bool MCPSDataRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MCPSDataRequest *>(obj)!=nullptr;
}

const char **MCPSDataRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MCPSDataRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MCPSDataRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 13+base->getFieldCount() : 13;
}

unsigned int MCPSDataRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcAddrMode
        FD_ISEDITABLE,    // FIELD_dstAddrMode
        FD_ISEDITABLE,    // FIELD_dstOWPANId
        FD_ISEDITABLE,    // FIELD_dstAddr
        FD_ISEDITABLE,    // FIELD_msduLength
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_msdu
        FD_ISEDITABLE,    // FIELD_msduHandle
        FD_ISEDITABLE,    // FIELD_txOptions
        FD_ISEDITABLE,    // FIELD_securityLevel
        FD_ISEDITABLE,    // FIELD_dataRate
        FD_ISEDITABLE,    // FIELD_burstMode
        FD_ISEDITABLE,    // FIELD_colorReceived
        FD_ISEDITABLE,    // FIELD_colorNotReceived
    };
    return (field >= 0 && field < 13) ? fieldTypeFlags[field] : 0;
}

const char *MCPSDataRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddrMode",
        "dstAddrMode",
        "dstOWPANId",
        "dstAddr",
        "msduLength",
        "msdu",
        "msduHandle",
        "txOptions",
        "securityLevel",
        "dataRate",
        "burstMode",
        "colorReceived",
        "colorNotReceived",
    };
    return (field >= 0 && field < 13) ? fieldNames[field] : nullptr;
}

int MCPSDataRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddrMode") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "dstAddrMode") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "dstOWPANId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "dstAddr") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "msduLength") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "msdu") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "msduHandle") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "txOptions") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "dataRate") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "burstMode") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "colorReceived") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "colorNotReceived") == 0) return baseIndex + 12;
    return base ? base->findField(fieldName) : -1;
}

const char *MCPSDataRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "addressingMode_t",    // FIELD_srcAddrMode
        "addressingMode_t",    // FIELD_dstAddrMode
        "uint16_t",    // FIELD_dstOWPANId
        "uint64_t",    // FIELD_dstAddr
        "uint16_t",    // FIELD_msduLength
        "uint8_t",    // FIELD_msdu
        "uint8_t",    // FIELD_msduHandle
        "uint8_t",    // FIELD_txOptions
        "uint8_t",    // FIELD_securityLevel
        "MCS_t",    // FIELD_dataRate
        "bool",    // FIELD_burstMode
        "bool",    // FIELD_colorReceived
        "bool",    // FIELD_colorNotReceived
    };
    return (field >= 0 && field < 13) ? fieldTypeStrings[field] : nullptr;
}

const char **MCPSDataRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_srcAddrMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_dstAddrMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_dataRate: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MCPSDataRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_srcAddrMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        case FIELD_dstAddrMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        case FIELD_dataRate:
            if (!strcmp(propertyName, "enum")) return "MCS_t";
            return nullptr;
        default: return nullptr;
    }
}

int MCPSDataRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_msdu: return pp->getMsduArraySize();
        default: return 0;
    }
}

void MCPSDataRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_msdu: pp->setMsduArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MCPSDataRequest'", field);
    }
}

const char *MCPSDataRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MCPSDataRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: return enum2string(pp->getSrcAddrMode(), "addressingMode_t");
        case FIELD_dstAddrMode: return enum2string(pp->getDstAddrMode(), "addressingMode_t");
        case FIELD_dstOWPANId: return ulong2string(pp->getDstOWPANId());
        case FIELD_dstAddr: return uint642string(pp->getDstAddr());
        case FIELD_msduLength: return ulong2string(pp->getMsduLength());
        case FIELD_msdu: return ulong2string(pp->getMsdu(i));
        case FIELD_msduHandle: return ulong2string(pp->getMsduHandle());
        case FIELD_txOptions: return ulong2string(pp->getTxOptions());
        case FIELD_securityLevel: return ulong2string(pp->getSecurityLevel());
        case FIELD_dataRate: return enum2string(pp->getDataRate(), "MCS_t");
        case FIELD_burstMode: return bool2string(pp->getBurstMode());
        case FIELD_colorReceived: return bool2string(pp->getColorReceived());
        case FIELD_colorNotReceived: return bool2string(pp->getColorNotReceived());
        default: return "";
    }
}

void MCPSDataRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: pp->setSrcAddrMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_dstAddrMode: pp->setDstAddrMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_dstOWPANId: pp->setDstOWPANId(string2ulong(value)); break;
        case FIELD_dstAddr: pp->setDstAddr(string2uint64(value)); break;
        case FIELD_msduLength: pp->setMsduLength(string2ulong(value)); break;
        case FIELD_msdu: pp->setMsdu(i,string2ulong(value)); break;
        case FIELD_msduHandle: pp->setMsduHandle(string2ulong(value)); break;
        case FIELD_txOptions: pp->setTxOptions(string2ulong(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2ulong(value)); break;
        case FIELD_dataRate: pp->setDataRate((MCS_t)string2enum(value, "MCS_t")); break;
        case FIELD_burstMode: pp->setBurstMode(string2bool(value)); break;
        case FIELD_colorReceived: pp->setColorReceived(string2bool(value)); break;
        case FIELD_colorNotReceived: pp->setColorNotReceived(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataRequest'", field);
    }
}

omnetpp::cValue MCPSDataRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: return static_cast<int>(pp->getSrcAddrMode());
        case FIELD_dstAddrMode: return static_cast<int>(pp->getDstAddrMode());
        case FIELD_dstOWPANId: return (omnetpp::intval_t)(pp->getDstOWPANId());
        case FIELD_dstAddr: return (omnetpp::intval_t)(pp->getDstAddr());
        case FIELD_msduLength: return (omnetpp::intval_t)(pp->getMsduLength());
        case FIELD_msdu: return (omnetpp::intval_t)(pp->getMsdu(i));
        case FIELD_msduHandle: return (omnetpp::intval_t)(pp->getMsduHandle());
        case FIELD_txOptions: return (omnetpp::intval_t)(pp->getTxOptions());
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->getSecurityLevel());
        case FIELD_dataRate: return static_cast<int>(pp->getDataRate());
        case FIELD_burstMode: return pp->getBurstMode();
        case FIELD_colorReceived: return pp->getColorReceived();
        case FIELD_colorNotReceived: return pp->getColorNotReceived();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MCPSDataRequest' as cValue -- field index out of range?", field);
    }
}

void MCPSDataRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: pp->setSrcAddrMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_dstAddrMode: pp->setDstAddrMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_dstOWPANId: pp->setDstOWPANId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_dstAddr: pp->setDstAddr(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_msduLength: pp->setMsduLength(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_msdu: pp->setMsdu(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_msduHandle: pp->setMsduHandle(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_txOptions: pp->setTxOptions(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_dataRate: pp->setDataRate(static_cast<MCS_t>(value.intValue())); break;
        case FIELD_burstMode: pp->setBurstMode(value.boolValue()); break;
        case FIELD_colorReceived: pp->setColorReceived(value.boolValue()); break;
        case FIELD_colorNotReceived: pp->setColorNotReceived(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataRequest'", field);
    }
}

const char *MCPSDataRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MCPSDataRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MCPSDataRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataRequest *pp = omnetpp::fromAnyPtr<MCPSDataRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataRequest'", field);
    }
}

Register_Class(MCPSDataConfirm)

MCPSDataConfirm::MCPSDataConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MCPSDataConfirm::MCPSDataConfirm(const MCPSDataConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MCPSDataConfirm::~MCPSDataConfirm()
{
}

MCPSDataConfirm& MCPSDataConfirm::operator=(const MCPSDataConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MCPSDataConfirm::copy(const MCPSDataConfirm& other)
{
    this->msduHandle = other.msduHandle;
    this->status = other.status;
    this->timestamp = other.timestamp;
}

void MCPSDataConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->msduHandle);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->timestamp);
}

void MCPSDataConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->msduHandle);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->timestamp);
}

uint8_t MCPSDataConfirm::getMsduHandle() const
{
    return this->msduHandle;
}

void MCPSDataConfirm::setMsduHandle(uint8_t msduHandle)
{
    this->msduHandle = msduHandle;
}

macStatus_t MCPSDataConfirm::getStatus() const
{
    return this->status;
}

void MCPSDataConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

uint32_t MCPSDataConfirm::getTimestamp() const
{
    return this->timestamp;
}

void MCPSDataConfirm::setTimestamp(uint32_t timestamp)
{
    this->timestamp = timestamp;
}

class MCPSDataConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_msduHandle,
        FIELD_status,
        FIELD_timestamp,
    };
  public:
    MCPSDataConfirmDescriptor();
    virtual ~MCPSDataConfirmDescriptor();

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

Register_ClassDescriptor(MCPSDataConfirmDescriptor)

MCPSDataConfirmDescriptor::MCPSDataConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MCPSDataConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MCPSDataConfirmDescriptor::~MCPSDataConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MCPSDataConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MCPSDataConfirm *>(obj)!=nullptr;
}

const char **MCPSDataConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MCPSDataConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MCPSDataConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MCPSDataConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_msduHandle
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_timestamp
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MCPSDataConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "msduHandle",
        "status",
        "timestamp",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MCPSDataConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "msduHandle") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MCPSDataConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_msduHandle
        "macStatus_t",    // FIELD_status
        "uint32_t",    // FIELD_timestamp
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MCPSDataConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MCPSDataConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int MCPSDataConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MCPSDataConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MCPSDataConfirm'", field);
    }
}

const char *MCPSDataConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MCPSDataConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_msduHandle: return ulong2string(pp->getMsduHandle());
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        case FIELD_timestamp: return ulong2string(pp->getTimestamp());
        default: return "";
    }
}

void MCPSDataConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_msduHandle: pp->setMsduHandle(string2ulong(value)); break;
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        case FIELD_timestamp: pp->setTimestamp(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataConfirm'", field);
    }
}

omnetpp::cValue MCPSDataConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_msduHandle: return (omnetpp::intval_t)(pp->getMsduHandle());
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_timestamp: return (omnetpp::intval_t)(pp->getTimestamp());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MCPSDataConfirm' as cValue -- field index out of range?", field);
    }
}

void MCPSDataConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_msduHandle: pp->setMsduHandle(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        case FIELD_timestamp: pp->setTimestamp(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataConfirm'", field);
    }
}

const char *MCPSDataConfirmDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MCPSDataConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MCPSDataConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataConfirm *pp = omnetpp::fromAnyPtr<MCPSDataConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataConfirm'", field);
    }
}

Register_Class(MCPSDataIndication)

MCPSDataIndication::MCPSDataIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MCPSDataIndication::MCPSDataIndication(const MCPSDataIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MCPSDataIndication::~MCPSDataIndication()
{
    delete [] this->msdu;
}

MCPSDataIndication& MCPSDataIndication::operator=(const MCPSDataIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MCPSDataIndication::copy(const MCPSDataIndication& other)
{
    this->srcAddrMode = other.srcAddrMode;
    this->srcOWPANId = other.srcOWPANId;
    this->srcAddr = other.srcAddr;
    this->dstAddrMode = other.dstAddrMode;
    this->dstOWPANId = other.dstOWPANId;
    this->dstAddr = other.dstAddr;
    this->msduLength = other.msduLength;
    delete [] this->msdu;
    this->msdu = (other.msdu_arraysize==0) ? nullptr : new uint8_t[other.msdu_arraysize];
    msdu_arraysize = other.msdu_arraysize;
    for (size_t i = 0; i < msdu_arraysize; i++) {
        this->msdu[i] = other.msdu[i];
    }
    this->mpduLinkQuality = other.mpduLinkQuality;
    this->DSN = other.DSN;
    this->timestamp = other.timestamp;
    this->securityLevel = other.securityLevel;
    this->dataRate = other.dataRate;
    this->burstMode = other.burstMode;
    this->colorReceived = other.colorReceived;
    this->colorNotReceived = other.colorNotReceived;
}

void MCPSDataIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->srcAddrMode);
    doParsimPacking(b,this->srcOWPANId);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->dstAddrMode);
    doParsimPacking(b,this->dstOWPANId);
    doParsimPacking(b,this->dstAddr);
    doParsimPacking(b,this->msduLength);
    b->pack(msdu_arraysize);
    doParsimArrayPacking(b,this->msdu,msdu_arraysize);
    doParsimPacking(b,this->mpduLinkQuality);
    doParsimPacking(b,this->DSN);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->securityLevel);
    doParsimPacking(b,this->dataRate);
    doParsimPacking(b,this->burstMode);
    doParsimPacking(b,this->colorReceived);
    doParsimPacking(b,this->colorNotReceived);
}

void MCPSDataIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddrMode);
    doParsimUnpacking(b,this->srcOWPANId);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->dstAddrMode);
    doParsimUnpacking(b,this->dstOWPANId);
    doParsimUnpacking(b,this->dstAddr);
    doParsimUnpacking(b,this->msduLength);
    delete [] this->msdu;
    b->unpack(msdu_arraysize);
    if (msdu_arraysize == 0) {
        this->msdu = nullptr;
    } else {
        this->msdu = new uint8_t[msdu_arraysize];
        doParsimArrayUnpacking(b,this->msdu,msdu_arraysize);
    }
    doParsimUnpacking(b,this->mpduLinkQuality);
    doParsimUnpacking(b,this->DSN);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->securityLevel);
    doParsimUnpacking(b,this->dataRate);
    doParsimUnpacking(b,this->burstMode);
    doParsimUnpacking(b,this->colorReceived);
    doParsimUnpacking(b,this->colorNotReceived);
}

int MCPSDataIndication::getSrcAddrMode() const
{
    return this->srcAddrMode;
}

void MCPSDataIndication::setSrcAddrMode(int srcAddrMode)
{
    this->srcAddrMode = srcAddrMode;
}

int MCPSDataIndication::getSrcOWPANId() const
{
    return this->srcOWPANId;
}

void MCPSDataIndication::setSrcOWPANId(int srcOWPANId)
{
    this->srcOWPANId = srcOWPANId;
}

uint64_t MCPSDataIndication::getSrcAddr() const
{
    return this->srcAddr;
}

void MCPSDataIndication::setSrcAddr(uint64_t srcAddr)
{
    this->srcAddr = srcAddr;
}

int MCPSDataIndication::getDstAddrMode() const
{
    return this->dstAddrMode;
}

void MCPSDataIndication::setDstAddrMode(int dstAddrMode)
{
    this->dstAddrMode = dstAddrMode;
}

int MCPSDataIndication::getDstOWPANId() const
{
    return this->dstOWPANId;
}

void MCPSDataIndication::setDstOWPANId(int dstOWPANId)
{
    this->dstOWPANId = dstOWPANId;
}

uint64_t MCPSDataIndication::getDstAddr() const
{
    return this->dstAddr;
}

void MCPSDataIndication::setDstAddr(uint64_t dstAddr)
{
    this->dstAddr = dstAddr;
}

int MCPSDataIndication::getMsduLength() const
{
    return this->msduLength;
}

void MCPSDataIndication::setMsduLength(int msduLength)
{
    this->msduLength = msduLength;
}

size_t MCPSDataIndication::getMsduArraySize() const
{
    return msdu_arraysize;
}

uint8_t MCPSDataIndication::getMsdu(size_t k) const
{
    if (k >= msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    return this->msdu[k];
}

void MCPSDataIndication::setMsduArraySize(size_t newSize)
{
    uint8_t *msdu2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = msdu_arraysize < newSize ? msdu_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        msdu2[i] = this->msdu[i];
    for (size_t i = minSize; i < newSize; i++)
        msdu2[i] = 0;
    delete [] this->msdu;
    this->msdu = msdu2;
    msdu_arraysize = newSize;
}

void MCPSDataIndication::setMsdu(size_t k, uint8_t msdu)
{
    if (k >= msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    this->msdu[k] = msdu;
}

void MCPSDataIndication::insertMsdu(size_t k, uint8_t msdu)
{
    if (k > msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    size_t newSize = msdu_arraysize + 1;
    uint8_t *msdu2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        msdu2[i] = this->msdu[i];
    msdu2[k] = msdu;
    for (i = k + 1; i < newSize; i++)
        msdu2[i] = this->msdu[i-1];
    delete [] this->msdu;
    this->msdu = msdu2;
    msdu_arraysize = newSize;
}

void MCPSDataIndication::appendMsdu(uint8_t msdu)
{
    insertMsdu(msdu_arraysize, msdu);
}

void MCPSDataIndication::eraseMsdu(size_t k)
{
    if (k >= msdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)msdu_arraysize, (unsigned long)k);
    size_t newSize = msdu_arraysize - 1;
    uint8_t *msdu2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        msdu2[i] = this->msdu[i];
    for (i = k; i < newSize; i++)
        msdu2[i] = this->msdu[i+1];
    delete [] this->msdu;
    this->msdu = msdu2;
    msdu_arraysize = newSize;
}

int MCPSDataIndication::getMpduLinkQuality() const
{
    return this->mpduLinkQuality;
}

void MCPSDataIndication::setMpduLinkQuality(int mpduLinkQuality)
{
    this->mpduLinkQuality = mpduLinkQuality;
}

int MCPSDataIndication::getDSN() const
{
    return this->DSN;
}

void MCPSDataIndication::setDSN(int DSN)
{
    this->DSN = DSN;
}

int MCPSDataIndication::getTimestamp() const
{
    return this->timestamp;
}

void MCPSDataIndication::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

int MCPSDataIndication::getSecurityLevel() const
{
    return this->securityLevel;
}

void MCPSDataIndication::setSecurityLevel(int securityLevel)
{
    this->securityLevel = securityLevel;
}

uint8_t MCPSDataIndication::getDataRate() const
{
    return this->dataRate;
}

void MCPSDataIndication::setDataRate(uint8_t dataRate)
{
    this->dataRate = dataRate;
}

bool MCPSDataIndication::getBurstMode() const
{
    return this->burstMode;
}

void MCPSDataIndication::setBurstMode(bool burstMode)
{
    this->burstMode = burstMode;
}

bool MCPSDataIndication::getColorReceived() const
{
    return this->colorReceived;
}

void MCPSDataIndication::setColorReceived(bool colorReceived)
{
    this->colorReceived = colorReceived;
}

bool MCPSDataIndication::getColorNotReceived() const
{
    return this->colorNotReceived;
}

void MCPSDataIndication::setColorNotReceived(bool colorNotReceived)
{
    this->colorNotReceived = colorNotReceived;
}

class MCPSDataIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddrMode,
        FIELD_srcOWPANId,
        FIELD_srcAddr,
        FIELD_dstAddrMode,
        FIELD_dstOWPANId,
        FIELD_dstAddr,
        FIELD_msduLength,
        FIELD_msdu,
        FIELD_mpduLinkQuality,
        FIELD_DSN,
        FIELD_timestamp,
        FIELD_securityLevel,
        FIELD_dataRate,
        FIELD_burstMode,
        FIELD_colorReceived,
        FIELD_colorNotReceived,
    };
  public:
    MCPSDataIndicationDescriptor();
    virtual ~MCPSDataIndicationDescriptor();

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

Register_ClassDescriptor(MCPSDataIndicationDescriptor)

MCPSDataIndicationDescriptor::MCPSDataIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MCPSDataIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MCPSDataIndicationDescriptor::~MCPSDataIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MCPSDataIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MCPSDataIndication *>(obj)!=nullptr;
}

const char **MCPSDataIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MCPSDataIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MCPSDataIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 16+base->getFieldCount() : 16;
}

unsigned int MCPSDataIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcAddrMode
        FD_ISEDITABLE,    // FIELD_srcOWPANId
        FD_ISEDITABLE,    // FIELD_srcAddr
        FD_ISEDITABLE,    // FIELD_dstAddrMode
        FD_ISEDITABLE,    // FIELD_dstOWPANId
        FD_ISEDITABLE,    // FIELD_dstAddr
        FD_ISEDITABLE,    // FIELD_msduLength
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_msdu
        FD_ISEDITABLE,    // FIELD_mpduLinkQuality
        FD_ISEDITABLE,    // FIELD_DSN
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_securityLevel
        FD_ISEDITABLE,    // FIELD_dataRate
        FD_ISEDITABLE,    // FIELD_burstMode
        FD_ISEDITABLE,    // FIELD_colorReceived
        FD_ISEDITABLE,    // FIELD_colorNotReceived
    };
    return (field >= 0 && field < 16) ? fieldTypeFlags[field] : 0;
}

const char *MCPSDataIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddrMode",
        "srcOWPANId",
        "srcAddr",
        "dstAddrMode",
        "dstOWPANId",
        "dstAddr",
        "msduLength",
        "msdu",
        "mpduLinkQuality",
        "DSN",
        "timestamp",
        "securityLevel",
        "dataRate",
        "burstMode",
        "colorReceived",
        "colorNotReceived",
    };
    return (field >= 0 && field < 16) ? fieldNames[field] : nullptr;
}

int MCPSDataIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddrMode") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "srcOWPANId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "srcAddr") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "dstAddrMode") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "dstOWPANId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "dstAddr") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "msduLength") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "msdu") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "mpduLinkQuality") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "DSN") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "dataRate") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "burstMode") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "colorReceived") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "colorNotReceived") == 0) return baseIndex + 15;
    return base ? base->findField(fieldName) : -1;
}

const char *MCPSDataIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_srcAddrMode
        "int",    // FIELD_srcOWPANId
        "uint64_t",    // FIELD_srcAddr
        "int",    // FIELD_dstAddrMode
        "int",    // FIELD_dstOWPANId
        "uint64_t",    // FIELD_dstAddr
        "int",    // FIELD_msduLength
        "uint8_t",    // FIELD_msdu
        "int",    // FIELD_mpduLinkQuality
        "int",    // FIELD_DSN
        "int",    // FIELD_timestamp
        "int",    // FIELD_securityLevel
        "uint8_t",    // FIELD_dataRate
        "bool",    // FIELD_burstMode
        "bool",    // FIELD_colorReceived
        "bool",    // FIELD_colorNotReceived
    };
    return (field >= 0 && field < 16) ? fieldTypeStrings[field] : nullptr;
}

const char **MCPSDataIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MCPSDataIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MCPSDataIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msdu: return pp->getMsduArraySize();
        default: return 0;
    }
}

void MCPSDataIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msdu: pp->setMsduArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MCPSDataIndication'", field);
    }
}

const char *MCPSDataIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MCPSDataIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: return long2string(pp->getSrcAddrMode());
        case FIELD_srcOWPANId: return long2string(pp->getSrcOWPANId());
        case FIELD_srcAddr: return uint642string(pp->getSrcAddr());
        case FIELD_dstAddrMode: return long2string(pp->getDstAddrMode());
        case FIELD_dstOWPANId: return long2string(pp->getDstOWPANId());
        case FIELD_dstAddr: return uint642string(pp->getDstAddr());
        case FIELD_msduLength: return long2string(pp->getMsduLength());
        case FIELD_msdu: return ulong2string(pp->getMsdu(i));
        case FIELD_mpduLinkQuality: return long2string(pp->getMpduLinkQuality());
        case FIELD_DSN: return long2string(pp->getDSN());
        case FIELD_timestamp: return long2string(pp->getTimestamp());
        case FIELD_securityLevel: return long2string(pp->getSecurityLevel());
        case FIELD_dataRate: return ulong2string(pp->getDataRate());
        case FIELD_burstMode: return bool2string(pp->getBurstMode());
        case FIELD_colorReceived: return bool2string(pp->getColorReceived());
        case FIELD_colorNotReceived: return bool2string(pp->getColorNotReceived());
        default: return "";
    }
}

void MCPSDataIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: pp->setSrcAddrMode(string2long(value)); break;
        case FIELD_srcOWPANId: pp->setSrcOWPANId(string2long(value)); break;
        case FIELD_srcAddr: pp->setSrcAddr(string2uint64(value)); break;
        case FIELD_dstAddrMode: pp->setDstAddrMode(string2long(value)); break;
        case FIELD_dstOWPANId: pp->setDstOWPANId(string2long(value)); break;
        case FIELD_dstAddr: pp->setDstAddr(string2uint64(value)); break;
        case FIELD_msduLength: pp->setMsduLength(string2long(value)); break;
        case FIELD_msdu: pp->setMsdu(i,string2ulong(value)); break;
        case FIELD_mpduLinkQuality: pp->setMpduLinkQuality(string2long(value)); break;
        case FIELD_DSN: pp->setDSN(string2long(value)); break;
        case FIELD_timestamp: pp->setTimestamp(string2long(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2long(value)); break;
        case FIELD_dataRate: pp->setDataRate(string2ulong(value)); break;
        case FIELD_burstMode: pp->setBurstMode(string2bool(value)); break;
        case FIELD_colorReceived: pp->setColorReceived(string2bool(value)); break;
        case FIELD_colorNotReceived: pp->setColorNotReceived(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataIndication'", field);
    }
}

omnetpp::cValue MCPSDataIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: return pp->getSrcAddrMode();
        case FIELD_srcOWPANId: return pp->getSrcOWPANId();
        case FIELD_srcAddr: return (omnetpp::intval_t)(pp->getSrcAddr());
        case FIELD_dstAddrMode: return pp->getDstAddrMode();
        case FIELD_dstOWPANId: return pp->getDstOWPANId();
        case FIELD_dstAddr: return (omnetpp::intval_t)(pp->getDstAddr());
        case FIELD_msduLength: return pp->getMsduLength();
        case FIELD_msdu: return (omnetpp::intval_t)(pp->getMsdu(i));
        case FIELD_mpduLinkQuality: return pp->getMpduLinkQuality();
        case FIELD_DSN: return pp->getDSN();
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_securityLevel: return pp->getSecurityLevel();
        case FIELD_dataRate: return (omnetpp::intval_t)(pp->getDataRate());
        case FIELD_burstMode: return pp->getBurstMode();
        case FIELD_colorReceived: return pp->getColorReceived();
        case FIELD_colorNotReceived: return pp->getColorNotReceived();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MCPSDataIndication' as cValue -- field index out of range?", field);
    }
}

void MCPSDataIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddrMode: pp->setSrcAddrMode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcOWPANId: pp->setSrcOWPANId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcAddr: pp->setSrcAddr(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_dstAddrMode: pp->setDstAddrMode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dstOWPANId: pp->setDstOWPANId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dstAddr: pp->setDstAddr(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_msduLength: pp->setMsduLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_msdu: pp->setMsdu(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_mpduLinkQuality: pp->setMpduLinkQuality(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_DSN: pp->setDSN(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_timestamp: pp->setTimestamp(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dataRate: pp->setDataRate(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_burstMode: pp->setBurstMode(value.boolValue()); break;
        case FIELD_colorReceived: pp->setColorReceived(value.boolValue()); break;
        case FIELD_colorNotReceived: pp->setColorNotReceived(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataIndication'", field);
    }
}

const char *MCPSDataIndicationDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MCPSDataIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MCPSDataIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MCPSDataIndication *pp = omnetpp::fromAnyPtr<MCPSDataIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MCPSDataIndication'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

