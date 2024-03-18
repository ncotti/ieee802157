//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/mac_frame.msg.
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
#include "mac_frame_m.h"

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

Register_Class(MacFrame)

MacFrame::MacFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

MacFrame::MacFrame(const MacFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

MacFrame::~MacFrame()
{
}

MacFrame& MacFrame::operator=(const MacFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MacFrame::copy(const MacFrame& other)
{
    this->frameVersion = other.frameVersion;
    this->frameType = other.frameType;
    this->securityEnable = other.securityEnable;
    this->framePending = other.framePending;
    this->acknoledgementRequest = other.acknoledgementRequest;
    this->destinationAddressingMode = other.destinationAddressingMode;
    this->sourceAddressingMode = other.sourceAddressingMode;
    this->sequenceNumber = other.sequenceNumber;
    this->destinationOWPANIdentifier = other.destinationOWPANIdentifier;
    this->destinationAddress = other.destinationAddress;
    this->sourceOWPANIdentifier = other.sourceOWPANIdentifier;
    this->sourceAddress = other.sourceAddress;
    this->FCS = other.FCS;
}

void MacFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->frameVersion);
    doParsimPacking(b,this->frameType);
    doParsimPacking(b,this->securityEnable);
    doParsimPacking(b,this->framePending);
    doParsimPacking(b,this->acknoledgementRequest);
    doParsimPacking(b,this->destinationAddressingMode);
    doParsimPacking(b,this->sourceAddressingMode);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->destinationOWPANIdentifier);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->sourceOWPANIdentifier);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->FCS);
}

void MacFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->frameVersion);
    doParsimUnpacking(b,this->frameType);
    doParsimUnpacking(b,this->securityEnable);
    doParsimUnpacking(b,this->framePending);
    doParsimUnpacking(b,this->acknoledgementRequest);
    doParsimUnpacking(b,this->destinationAddressingMode);
    doParsimUnpacking(b,this->sourceAddressingMode);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->destinationOWPANIdentifier);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->sourceOWPANIdentifier);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->FCS);
}

uint8_t MacFrame::getFrameVersion() const
{
    return this->frameVersion;
}

void MacFrame::setFrameVersion(uint8_t frameVersion)
{
    this->frameVersion = frameVersion;
}

frameType_t MacFrame::getFrameType() const
{
    return this->frameType;
}

void MacFrame::setFrameType(frameType_t frameType)
{
    this->frameType = frameType;
}

bool MacFrame::getSecurityEnable() const
{
    return this->securityEnable;
}

void MacFrame::setSecurityEnable(bool securityEnable)
{
    this->securityEnable = securityEnable;
}

bool MacFrame::getFramePending() const
{
    return this->framePending;
}

void MacFrame::setFramePending(bool framePending)
{
    this->framePending = framePending;
}

bool MacFrame::getAcknoledgementRequest() const
{
    return this->acknoledgementRequest;
}

void MacFrame::setAcknoledgementRequest(bool acknoledgementRequest)
{
    this->acknoledgementRequest = acknoledgementRequest;
}

addressingMode_t MacFrame::getDestinationAddressingMode() const
{
    return this->destinationAddressingMode;
}

void MacFrame::setDestinationAddressingMode(addressingMode_t destinationAddressingMode)
{
    this->destinationAddressingMode = destinationAddressingMode;
}

addressingMode_t MacFrame::getSourceAddressingMode() const
{
    return this->sourceAddressingMode;
}

void MacFrame::setSourceAddressingMode(addressingMode_t sourceAddressingMode)
{
    this->sourceAddressingMode = sourceAddressingMode;
}

uint8_t MacFrame::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void MacFrame::setSequenceNumber(uint8_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

uint16_t MacFrame::getDestinationOWPANIdentifier() const
{
    return this->destinationOWPANIdentifier;
}

void MacFrame::setDestinationOWPANIdentifier(uint16_t destinationOWPANIdentifier)
{
    this->destinationOWPANIdentifier = destinationOWPANIdentifier;
}

uint64_t MacFrame::getDestinationAddress() const
{
    return this->destinationAddress;
}

void MacFrame::setDestinationAddress(uint64_t destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

uint16_t MacFrame::getSourceOWPANIdentifier() const
{
    return this->sourceOWPANIdentifier;
}

void MacFrame::setSourceOWPANIdentifier(uint16_t sourceOWPANIdentifier)
{
    this->sourceOWPANIdentifier = sourceOWPANIdentifier;
}

uint64_t MacFrame::getSourceAddress() const
{
    return this->sourceAddress;
}

void MacFrame::setSourceAddress(uint64_t sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

uint16_t MacFrame::getFCS() const
{
    return this->FCS;
}

void MacFrame::setFCS(uint16_t FCS)
{
    this->FCS = FCS;
}

class MacFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_frameVersion,
        FIELD_frameType,
        FIELD_securityEnable,
        FIELD_framePending,
        FIELD_acknoledgementRequest,
        FIELD_destinationAddressingMode,
        FIELD_sourceAddressingMode,
        FIELD_sequenceNumber,
        FIELD_destinationOWPANIdentifier,
        FIELD_destinationAddress,
        FIELD_sourceOWPANIdentifier,
        FIELD_sourceAddress,
        FIELD_FCS,
    };
  public:
    MacFrameDescriptor();
    virtual ~MacFrameDescriptor();

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

Register_ClassDescriptor(MacFrameDescriptor)

MacFrameDescriptor::MacFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MacFrame)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

MacFrameDescriptor::~MacFrameDescriptor()
{
    delete[] propertyNames;
}

bool MacFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacFrame *>(obj)!=nullptr;
}

const char **MacFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 13+base->getFieldCount() : 13;
}

unsigned int MacFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_frameVersion
        FD_ISEDITABLE,    // FIELD_frameType
        FD_ISEDITABLE,    // FIELD_securityEnable
        FD_ISEDITABLE,    // FIELD_framePending
        FD_ISEDITABLE,    // FIELD_acknoledgementRequest
        FD_ISEDITABLE,    // FIELD_destinationAddressingMode
        FD_ISEDITABLE,    // FIELD_sourceAddressingMode
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_destinationOWPANIdentifier
        FD_ISEDITABLE,    // FIELD_destinationAddress
        FD_ISEDITABLE,    // FIELD_sourceOWPANIdentifier
        FD_ISEDITABLE,    // FIELD_sourceAddress
        FD_ISEDITABLE,    // FIELD_FCS
    };
    return (field >= 0 && field < 13) ? fieldTypeFlags[field] : 0;
}

const char *MacFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "frameVersion",
        "frameType",
        "securityEnable",
        "framePending",
        "acknoledgementRequest",
        "destinationAddressingMode",
        "sourceAddressingMode",
        "sequenceNumber",
        "destinationOWPANIdentifier",
        "destinationAddress",
        "sourceOWPANIdentifier",
        "sourceAddress",
        "FCS",
    };
    return (field >= 0 && field < 13) ? fieldNames[field] : nullptr;
}

int MacFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "frameVersion") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "frameType") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "securityEnable") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "framePending") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "acknoledgementRequest") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "destinationAddressingMode") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "sourceAddressingMode") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "destinationOWPANIdentifier") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "destinationAddress") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "sourceOWPANIdentifier") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "sourceAddress") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "FCS") == 0) return baseIndex + 12;
    return base ? base->findField(fieldName) : -1;
}

const char *MacFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_frameVersion
        "frameType_t",    // FIELD_frameType
        "bool",    // FIELD_securityEnable
        "bool",    // FIELD_framePending
        "bool",    // FIELD_acknoledgementRequest
        "addressingMode_t",    // FIELD_destinationAddressingMode
        "addressingMode_t",    // FIELD_sourceAddressingMode
        "uint8_t",    // FIELD_sequenceNumber
        "uint16_t",    // FIELD_destinationOWPANIdentifier
        "uint64_t",    // FIELD_destinationAddress
        "uint16_t",    // FIELD_sourceOWPANIdentifier
        "uint64_t",    // FIELD_sourceAddress
        "uint16_t",    // FIELD_FCS
    };
    return (field >= 0 && field < 13) ? fieldTypeStrings[field] : nullptr;
}

const char **MacFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_frameType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_destinationAddressingMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_sourceAddressingMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MacFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_frameType:
            if (!strcmp(propertyName, "enum")) return "frameType_t";
            return nullptr;
        case FIELD_destinationAddressingMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        case FIELD_sourceAddressingMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        default: return nullptr;
    }
}

int MacFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MacFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacFrame'", field);
    }
}

const char *MacFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        case FIELD_frameVersion: return ulong2string(pp->getFrameVersion());
        case FIELD_frameType: return enum2string(pp->getFrameType(), "frameType_t");
        case FIELD_securityEnable: return bool2string(pp->getSecurityEnable());
        case FIELD_framePending: return bool2string(pp->getFramePending());
        case FIELD_acknoledgementRequest: return bool2string(pp->getAcknoledgementRequest());
        case FIELD_destinationAddressingMode: return enum2string(pp->getDestinationAddressingMode(), "addressingMode_t");
        case FIELD_sourceAddressingMode: return enum2string(pp->getSourceAddressingMode(), "addressingMode_t");
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_destinationOWPANIdentifier: return ulong2string(pp->getDestinationOWPANIdentifier());
        case FIELD_destinationAddress: return uint642string(pp->getDestinationAddress());
        case FIELD_sourceOWPANIdentifier: return ulong2string(pp->getSourceOWPANIdentifier());
        case FIELD_sourceAddress: return uint642string(pp->getSourceAddress());
        case FIELD_FCS: return ulong2string(pp->getFCS());
        default: return "";
    }
}

void MacFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        case FIELD_frameVersion: pp->setFrameVersion(string2ulong(value)); break;
        case FIELD_frameType: pp->setFrameType((frameType_t)string2enum(value, "frameType_t")); break;
        case FIELD_securityEnable: pp->setSecurityEnable(string2bool(value)); break;
        case FIELD_framePending: pp->setFramePending(string2bool(value)); break;
        case FIELD_acknoledgementRequest: pp->setAcknoledgementRequest(string2bool(value)); break;
        case FIELD_destinationAddressingMode: pp->setDestinationAddressingMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_sourceAddressingMode: pp->setSourceAddressingMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); break;
        case FIELD_destinationOWPANIdentifier: pp->setDestinationOWPANIdentifier(string2ulong(value)); break;
        case FIELD_destinationAddress: pp->setDestinationAddress(string2uint64(value)); break;
        case FIELD_sourceOWPANIdentifier: pp->setSourceOWPANIdentifier(string2ulong(value)); break;
        case FIELD_sourceAddress: pp->setSourceAddress(string2uint64(value)); break;
        case FIELD_FCS: pp->setFCS(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacFrame'", field);
    }
}

omnetpp::cValue MacFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        case FIELD_frameVersion: return (omnetpp::intval_t)(pp->getFrameVersion());
        case FIELD_frameType: return static_cast<int>(pp->getFrameType());
        case FIELD_securityEnable: return pp->getSecurityEnable();
        case FIELD_framePending: return pp->getFramePending();
        case FIELD_acknoledgementRequest: return pp->getAcknoledgementRequest();
        case FIELD_destinationAddressingMode: return static_cast<int>(pp->getDestinationAddressingMode());
        case FIELD_sourceAddressingMode: return static_cast<int>(pp->getSourceAddressingMode());
        case FIELD_sequenceNumber: return (omnetpp::intval_t)(pp->getSequenceNumber());
        case FIELD_destinationOWPANIdentifier: return (omnetpp::intval_t)(pp->getDestinationOWPANIdentifier());
        case FIELD_destinationAddress: return (omnetpp::intval_t)(pp->getDestinationAddress());
        case FIELD_sourceOWPANIdentifier: return (omnetpp::intval_t)(pp->getSourceOWPANIdentifier());
        case FIELD_sourceAddress: return (omnetpp::intval_t)(pp->getSourceAddress());
        case FIELD_FCS: return (omnetpp::intval_t)(pp->getFCS());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacFrame' as cValue -- field index out of range?", field);
    }
}

void MacFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        case FIELD_frameVersion: pp->setFrameVersion(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_frameType: pp->setFrameType(static_cast<frameType_t>(value.intValue())); break;
        case FIELD_securityEnable: pp->setSecurityEnable(value.boolValue()); break;
        case FIELD_framePending: pp->setFramePending(value.boolValue()); break;
        case FIELD_acknoledgementRequest: pp->setAcknoledgementRequest(value.boolValue()); break;
        case FIELD_destinationAddressingMode: pp->setDestinationAddressingMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_sourceAddressingMode: pp->setSourceAddressingMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_destinationOWPANIdentifier: pp->setDestinationOWPANIdentifier(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_destinationAddress: pp->setDestinationAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_sourceOWPANIdentifier: pp->setSourceOWPANIdentifier(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_sourceAddress: pp->setSourceAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_FCS: pp->setFCS(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacFrame'", field);
    }
}

const char *MacFrameDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MacFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MacFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MacFrame *pp = omnetpp::fromAnyPtr<MacFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacFrame'", field);
    }
}

GTSList_t::GTSList_t()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const GTSList_t& a)
{
    doParsimPacking(b,a.deviceShortAddress);
    doParsimPacking(b,a.GTSStartingSlot);
    doParsimPacking(b,a.GTSLength);
}

void __doUnpacking(omnetpp::cCommBuffer *b, GTSList_t& a)
{
    doParsimUnpacking(b,a.deviceShortAddress);
    doParsimUnpacking(b,a.GTSStartingSlot);
    doParsimUnpacking(b,a.GTSLength);
}

class GTSList_tDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deviceShortAddress,
        FIELD_GTSStartingSlot,
        FIELD_GTSLength,
    };
  public:
    GTSList_tDescriptor();
    virtual ~GTSList_tDescriptor();

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

Register_ClassDescriptor(GTSList_tDescriptor)

GTSList_tDescriptor::GTSList_tDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(GTSList_t)), "")
{
    propertyNames = nullptr;
}

GTSList_tDescriptor::~GTSList_tDescriptor()
{
    delete[] propertyNames;
}

bool GTSList_tDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GTSList_t *>(obj)!=nullptr;
}

const char **GTSList_tDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *GTSList_tDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int GTSList_tDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int GTSList_tDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_deviceShortAddress
        FD_ISEDITABLE,    // FIELD_GTSStartingSlot
        FD_ISEDITABLE,    // FIELD_GTSLength
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *GTSList_tDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deviceShortAddress",
        "GTSStartingSlot",
        "GTSLength",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int GTSList_tDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deviceShortAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "GTSStartingSlot") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "GTSLength") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *GTSList_tDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_deviceShortAddress
        "uint8_t",    // FIELD_GTSStartingSlot
        "uint8_t",    // FIELD_GTSLength
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **GTSList_tDescriptor::getFieldPropertyNames(int field) const
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

const char *GTSList_tDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int GTSList_tDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void GTSList_tDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'GTSList_t'", field);
    }
}

const char *GTSList_tDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GTSList_tDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        case FIELD_deviceShortAddress: return ulong2string(pp->deviceShortAddress);
        case FIELD_GTSStartingSlot: return ulong2string(pp->GTSStartingSlot);
        case FIELD_GTSLength: return ulong2string(pp->GTSLength);
        default: return "";
    }
}

void GTSList_tDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        case FIELD_deviceShortAddress: pp->deviceShortAddress = string2ulong(value); break;
        case FIELD_GTSStartingSlot: pp->GTSStartingSlot = string2ulong(value); break;
        case FIELD_GTSLength: pp->GTSLength = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GTSList_t'", field);
    }
}

omnetpp::cValue GTSList_tDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        case FIELD_deviceShortAddress: return (omnetpp::intval_t)(pp->deviceShortAddress);
        case FIELD_GTSStartingSlot: return (omnetpp::intval_t)(pp->GTSStartingSlot);
        case FIELD_GTSLength: return (omnetpp::intval_t)(pp->GTSLength);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'GTSList_t' as cValue -- field index out of range?", field);
    }
}

void GTSList_tDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        case FIELD_deviceShortAddress: pp->deviceShortAddress = omnetpp::checked_int_cast<uint16_t>(value.intValue()); break;
        case FIELD_GTSStartingSlot: pp->GTSStartingSlot = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_GTSLength: pp->GTSLength = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GTSList_t'", field);
    }
}

const char *GTSList_tDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr GTSList_tDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void GTSList_tDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    GTSList_t *pp = omnetpp::fromAnyPtr<GTSList_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GTSList_t'", field);
    }
}

Register_Class(MacBeaconFrame)

MacBeaconFrame::MacBeaconFrame(const char *name, short kind) : ::MacFrame(name, kind)
{
}

MacBeaconFrame::MacBeaconFrame(const MacBeaconFrame& other) : ::MacFrame(other)
{
    copy(other);
}

MacBeaconFrame::~MacBeaconFrame()
{
    delete [] this->GTSList;
    delete [] this->addressList;
    delete [] this->beaconPayload;
}

MacBeaconFrame& MacBeaconFrame::operator=(const MacBeaconFrame& other)
{
    if (this == &other) return *this;
    ::MacFrame::operator=(other);
    copy(other);
    return *this;
}

void MacBeaconFrame::copy(const MacBeaconFrame& other)
{
    this->beaconOrder = other.beaconOrder;
    this->superframeOrder = other.superframeOrder;
    this->finalCAPSlot = other.finalCAPSlot;
    this->OWPANCoordinator = other.OWPANCoordinator;
    this->associationPermit = other.associationPermit;
    this->cellSearchEn = other.cellSearchEn;
    this->GTSDescriptorCount = other.GTSDescriptorCount;
    this->GTSPermit = other.GTSPermit;
    this->GTSDirections = other.GTSDirections;
    delete [] this->GTSList;
    this->GTSList = (other.GTSList_arraysize==0) ? nullptr : new GTSList_t[other.GTSList_arraysize];
    GTSList_arraysize = other.GTSList_arraysize;
    for (size_t i = 0; i < GTSList_arraysize; i++) {
        this->GTSList[i] = other.GTSList[i];
    }
    this->numberOfShortAddressesPending = other.numberOfShortAddressesPending;
    this->numberOfExtendedAddressesPending = other.numberOfExtendedAddressesPending;
    delete [] this->addressList;
    this->addressList = (other.addressList_arraysize==0) ? nullptr : new uint64_t[other.addressList_arraysize];
    addressList_arraysize = other.addressList_arraysize;
    for (size_t i = 0; i < addressList_arraysize; i++) {
        this->addressList[i] = other.addressList[i];
    }
    delete [] this->beaconPayload;
    this->beaconPayload = (other.beaconPayload_arraysize==0) ? nullptr : new uint8_t[other.beaconPayload_arraysize];
    beaconPayload_arraysize = other.beaconPayload_arraysize;
    for (size_t i = 0; i < beaconPayload_arraysize; i++) {
        this->beaconPayload[i] = other.beaconPayload[i];
    }
}

void MacBeaconFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MacFrame::parsimPack(b);
    doParsimPacking(b,this->beaconOrder);
    doParsimPacking(b,this->superframeOrder);
    doParsimPacking(b,this->finalCAPSlot);
    doParsimPacking(b,this->OWPANCoordinator);
    doParsimPacking(b,this->associationPermit);
    doParsimPacking(b,this->cellSearchEn);
    doParsimPacking(b,this->GTSDescriptorCount);
    doParsimPacking(b,this->GTSPermit);
    doParsimPacking(b,this->GTSDirections);
    b->pack(GTSList_arraysize);
    doParsimArrayPacking(b,this->GTSList,GTSList_arraysize);
    doParsimPacking(b,this->numberOfShortAddressesPending);
    doParsimPacking(b,this->numberOfExtendedAddressesPending);
    b->pack(addressList_arraysize);
    doParsimArrayPacking(b,this->addressList,addressList_arraysize);
    b->pack(beaconPayload_arraysize);
    doParsimArrayPacking(b,this->beaconPayload,beaconPayload_arraysize);
}

void MacBeaconFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MacFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->beaconOrder);
    doParsimUnpacking(b,this->superframeOrder);
    doParsimUnpacking(b,this->finalCAPSlot);
    doParsimUnpacking(b,this->OWPANCoordinator);
    doParsimUnpacking(b,this->associationPermit);
    doParsimUnpacking(b,this->cellSearchEn);
    doParsimUnpacking(b,this->GTSDescriptorCount);
    doParsimUnpacking(b,this->GTSPermit);
    doParsimUnpacking(b,this->GTSDirections);
    delete [] this->GTSList;
    b->unpack(GTSList_arraysize);
    if (GTSList_arraysize == 0) {
        this->GTSList = nullptr;
    } else {
        this->GTSList = new GTSList_t[GTSList_arraysize];
        doParsimArrayUnpacking(b,this->GTSList,GTSList_arraysize);
    }
    doParsimUnpacking(b,this->numberOfShortAddressesPending);
    doParsimUnpacking(b,this->numberOfExtendedAddressesPending);
    delete [] this->addressList;
    b->unpack(addressList_arraysize);
    if (addressList_arraysize == 0) {
        this->addressList = nullptr;
    } else {
        this->addressList = new uint64_t[addressList_arraysize];
        doParsimArrayUnpacking(b,this->addressList,addressList_arraysize);
    }
    delete [] this->beaconPayload;
    b->unpack(beaconPayload_arraysize);
    if (beaconPayload_arraysize == 0) {
        this->beaconPayload = nullptr;
    } else {
        this->beaconPayload = new uint8_t[beaconPayload_arraysize];
        doParsimArrayUnpacking(b,this->beaconPayload,beaconPayload_arraysize);
    }
}

uint8_t MacBeaconFrame::getBeaconOrder() const
{
    return this->beaconOrder;
}

void MacBeaconFrame::setBeaconOrder(uint8_t beaconOrder)
{
    this->beaconOrder = beaconOrder;
}

uint8_t MacBeaconFrame::getSuperframeOrder() const
{
    return this->superframeOrder;
}

void MacBeaconFrame::setSuperframeOrder(uint8_t superframeOrder)
{
    this->superframeOrder = superframeOrder;
}

uint8_t MacBeaconFrame::getFinalCAPSlot() const
{
    return this->finalCAPSlot;
}

void MacBeaconFrame::setFinalCAPSlot(uint8_t finalCAPSlot)
{
    this->finalCAPSlot = finalCAPSlot;
}

bool MacBeaconFrame::getOWPANCoordinator() const
{
    return this->OWPANCoordinator;
}

void MacBeaconFrame::setOWPANCoordinator(bool OWPANCoordinator)
{
    this->OWPANCoordinator = OWPANCoordinator;
}

bool MacBeaconFrame::getAssociationPermit() const
{
    return this->associationPermit;
}

void MacBeaconFrame::setAssociationPermit(bool associationPermit)
{
    this->associationPermit = associationPermit;
}

bool MacBeaconFrame::getCellSearchEn() const
{
    return this->cellSearchEn;
}

void MacBeaconFrame::setCellSearchEn(bool cellSearchEn)
{
    this->cellSearchEn = cellSearchEn;
}

uint8_t MacBeaconFrame::getGTSDescriptorCount() const
{
    return this->GTSDescriptorCount;
}

void MacBeaconFrame::setGTSDescriptorCount(uint8_t GTSDescriptorCount)
{
    this->GTSDescriptorCount = GTSDescriptorCount;
}

bool MacBeaconFrame::getGTSPermit() const
{
    return this->GTSPermit;
}

void MacBeaconFrame::setGTSPermit(bool GTSPermit)
{
    this->GTSPermit = GTSPermit;
}

uint8_t MacBeaconFrame::getGTSDirections() const
{
    return this->GTSDirections;
}

void MacBeaconFrame::setGTSDirections(uint8_t GTSDirections)
{
    this->GTSDirections = GTSDirections;
}

size_t MacBeaconFrame::getGTSListArraySize() const
{
    return GTSList_arraysize;
}

const GTSList_t& MacBeaconFrame::getGTSList(size_t k) const
{
    if (k >= GTSList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)GTSList_arraysize, (unsigned long)k);
    return this->GTSList[k];
}

void MacBeaconFrame::setGTSListArraySize(size_t newSize)
{
    GTSList_t *GTSList2 = (newSize==0) ? nullptr : new GTSList_t[newSize];
    size_t minSize = GTSList_arraysize < newSize ? GTSList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        GTSList2[i] = this->GTSList[i];
    delete [] this->GTSList;
    this->GTSList = GTSList2;
    GTSList_arraysize = newSize;
}

void MacBeaconFrame::setGTSList(size_t k, const GTSList_t& GTSList)
{
    if (k >= GTSList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)GTSList_arraysize, (unsigned long)k);
    this->GTSList[k] = GTSList;
}

void MacBeaconFrame::insertGTSList(size_t k, const GTSList_t& GTSList)
{
    if (k > GTSList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)GTSList_arraysize, (unsigned long)k);
    size_t newSize = GTSList_arraysize + 1;
    GTSList_t *GTSList2 = new GTSList_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        GTSList2[i] = this->GTSList[i];
    GTSList2[k] = GTSList;
    for (i = k + 1; i < newSize; i++)
        GTSList2[i] = this->GTSList[i-1];
    delete [] this->GTSList;
    this->GTSList = GTSList2;
    GTSList_arraysize = newSize;
}

void MacBeaconFrame::appendGTSList(const GTSList_t& GTSList)
{
    insertGTSList(GTSList_arraysize, GTSList);
}

void MacBeaconFrame::eraseGTSList(size_t k)
{
    if (k >= GTSList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)GTSList_arraysize, (unsigned long)k);
    size_t newSize = GTSList_arraysize - 1;
    GTSList_t *GTSList2 = (newSize == 0) ? nullptr : new GTSList_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        GTSList2[i] = this->GTSList[i];
    for (i = k; i < newSize; i++)
        GTSList2[i] = this->GTSList[i+1];
    delete [] this->GTSList;
    this->GTSList = GTSList2;
    GTSList_arraysize = newSize;
}

uint8_t MacBeaconFrame::getNumberOfShortAddressesPending() const
{
    return this->numberOfShortAddressesPending;
}

void MacBeaconFrame::setNumberOfShortAddressesPending(uint8_t numberOfShortAddressesPending)
{
    this->numberOfShortAddressesPending = numberOfShortAddressesPending;
}

uint8_t MacBeaconFrame::getNumberOfExtendedAddressesPending() const
{
    return this->numberOfExtendedAddressesPending;
}

void MacBeaconFrame::setNumberOfExtendedAddressesPending(uint8_t numberOfExtendedAddressesPending)
{
    this->numberOfExtendedAddressesPending = numberOfExtendedAddressesPending;
}

size_t MacBeaconFrame::getAddressListArraySize() const
{
    return addressList_arraysize;
}

uint64_t MacBeaconFrame::getAddressList(size_t k) const
{
    if (k >= addressList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addressList_arraysize, (unsigned long)k);
    return this->addressList[k];
}

void MacBeaconFrame::setAddressListArraySize(size_t newSize)
{
    uint64_t *addressList2 = (newSize==0) ? nullptr : new uint64_t[newSize];
    size_t minSize = addressList_arraysize < newSize ? addressList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        addressList2[i] = this->addressList[i];
    for (size_t i = minSize; i < newSize; i++)
        addressList2[i] = 0;
    delete [] this->addressList;
    this->addressList = addressList2;
    addressList_arraysize = newSize;
}

void MacBeaconFrame::setAddressList(size_t k, uint64_t addressList)
{
    if (k >= addressList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addressList_arraysize, (unsigned long)k);
    this->addressList[k] = addressList;
}

void MacBeaconFrame::insertAddressList(size_t k, uint64_t addressList)
{
    if (k > addressList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addressList_arraysize, (unsigned long)k);
    size_t newSize = addressList_arraysize + 1;
    uint64_t *addressList2 = new uint64_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addressList2[i] = this->addressList[i];
    addressList2[k] = addressList;
    for (i = k + 1; i < newSize; i++)
        addressList2[i] = this->addressList[i-1];
    delete [] this->addressList;
    this->addressList = addressList2;
    addressList_arraysize = newSize;
}

void MacBeaconFrame::appendAddressList(uint64_t addressList)
{
    insertAddressList(addressList_arraysize, addressList);
}

void MacBeaconFrame::eraseAddressList(size_t k)
{
    if (k >= addressList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addressList_arraysize, (unsigned long)k);
    size_t newSize = addressList_arraysize - 1;
    uint64_t *addressList2 = (newSize == 0) ? nullptr : new uint64_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addressList2[i] = this->addressList[i];
    for (i = k; i < newSize; i++)
        addressList2[i] = this->addressList[i+1];
    delete [] this->addressList;
    this->addressList = addressList2;
    addressList_arraysize = newSize;
}

size_t MacBeaconFrame::getBeaconPayloadArraySize() const
{
    return beaconPayload_arraysize;
}

uint8_t MacBeaconFrame::getBeaconPayload(size_t k) const
{
    if (k >= beaconPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)beaconPayload_arraysize, (unsigned long)k);
    return this->beaconPayload[k];
}

void MacBeaconFrame::setBeaconPayloadArraySize(size_t newSize)
{
    uint8_t *beaconPayload2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = beaconPayload_arraysize < newSize ? beaconPayload_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        beaconPayload2[i] = this->beaconPayload[i];
    for (size_t i = minSize; i < newSize; i++)
        beaconPayload2[i] = 0;
    delete [] this->beaconPayload;
    this->beaconPayload = beaconPayload2;
    beaconPayload_arraysize = newSize;
}

void MacBeaconFrame::setBeaconPayload(size_t k, uint8_t beaconPayload)
{
    if (k >= beaconPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)beaconPayload_arraysize, (unsigned long)k);
    this->beaconPayload[k] = beaconPayload;
}

void MacBeaconFrame::insertBeaconPayload(size_t k, uint8_t beaconPayload)
{
    if (k > beaconPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)beaconPayload_arraysize, (unsigned long)k);
    size_t newSize = beaconPayload_arraysize + 1;
    uint8_t *beaconPayload2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        beaconPayload2[i] = this->beaconPayload[i];
    beaconPayload2[k] = beaconPayload;
    for (i = k + 1; i < newSize; i++)
        beaconPayload2[i] = this->beaconPayload[i-1];
    delete [] this->beaconPayload;
    this->beaconPayload = beaconPayload2;
    beaconPayload_arraysize = newSize;
}

void MacBeaconFrame::appendBeaconPayload(uint8_t beaconPayload)
{
    insertBeaconPayload(beaconPayload_arraysize, beaconPayload);
}

void MacBeaconFrame::eraseBeaconPayload(size_t k)
{
    if (k >= beaconPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)beaconPayload_arraysize, (unsigned long)k);
    size_t newSize = beaconPayload_arraysize - 1;
    uint8_t *beaconPayload2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        beaconPayload2[i] = this->beaconPayload[i];
    for (i = k; i < newSize; i++)
        beaconPayload2[i] = this->beaconPayload[i+1];
    delete [] this->beaconPayload;
    this->beaconPayload = beaconPayload2;
    beaconPayload_arraysize = newSize;
}

class MacBeaconFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_beaconOrder,
        FIELD_superframeOrder,
        FIELD_finalCAPSlot,
        FIELD_OWPANCoordinator,
        FIELD_associationPermit,
        FIELD_cellSearchEn,
        FIELD_GTSDescriptorCount,
        FIELD_GTSPermit,
        FIELD_GTSDirections,
        FIELD_GTSList,
        FIELD_numberOfShortAddressesPending,
        FIELD_numberOfExtendedAddressesPending,
        FIELD_addressList,
        FIELD_beaconPayload,
    };
  public:
    MacBeaconFrameDescriptor();
    virtual ~MacBeaconFrameDescriptor();

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

Register_ClassDescriptor(MacBeaconFrameDescriptor)

MacBeaconFrameDescriptor::MacBeaconFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MacBeaconFrame)), "MacFrame")
{
    propertyNames = nullptr;
}

MacBeaconFrameDescriptor::~MacBeaconFrameDescriptor()
{
    delete[] propertyNames;
}

bool MacBeaconFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacBeaconFrame *>(obj)!=nullptr;
}

const char **MacBeaconFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacBeaconFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacBeaconFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 14+base->getFieldCount() : 14;
}

unsigned int MacBeaconFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_beaconOrder
        FD_ISEDITABLE,    // FIELD_superframeOrder
        FD_ISEDITABLE,    // FIELD_finalCAPSlot
        FD_ISEDITABLE,    // FIELD_OWPANCoordinator
        FD_ISEDITABLE,    // FIELD_associationPermit
        FD_ISEDITABLE,    // FIELD_cellSearchEn
        FD_ISEDITABLE,    // FIELD_GTSDescriptorCount
        FD_ISEDITABLE,    // FIELD_GTSPermit
        FD_ISEDITABLE,    // FIELD_GTSDirections
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_GTSList
        FD_ISEDITABLE,    // FIELD_numberOfShortAddressesPending
        FD_ISEDITABLE,    // FIELD_numberOfExtendedAddressesPending
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_addressList
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_beaconPayload
    };
    return (field >= 0 && field < 14) ? fieldTypeFlags[field] : 0;
}

const char *MacBeaconFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "beaconOrder",
        "superframeOrder",
        "finalCAPSlot",
        "OWPANCoordinator",
        "associationPermit",
        "cellSearchEn",
        "GTSDescriptorCount",
        "GTSPermit",
        "GTSDirections",
        "GTSList",
        "numberOfShortAddressesPending",
        "numberOfExtendedAddressesPending",
        "addressList",
        "beaconPayload",
    };
    return (field >= 0 && field < 14) ? fieldNames[field] : nullptr;
}

int MacBeaconFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "beaconOrder") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "superframeOrder") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "finalCAPSlot") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "OWPANCoordinator") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "associationPermit") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "cellSearchEn") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "GTSDescriptorCount") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "GTSPermit") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "GTSDirections") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "GTSList") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "numberOfShortAddressesPending") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "numberOfExtendedAddressesPending") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "addressList") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "beaconPayload") == 0) return baseIndex + 13;
    return base ? base->findField(fieldName) : -1;
}

const char *MacBeaconFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_beaconOrder
        "uint8_t",    // FIELD_superframeOrder
        "uint8_t",    // FIELD_finalCAPSlot
        "bool",    // FIELD_OWPANCoordinator
        "bool",    // FIELD_associationPermit
        "bool",    // FIELD_cellSearchEn
        "uint8_t",    // FIELD_GTSDescriptorCount
        "bool",    // FIELD_GTSPermit
        "uint8_t",    // FIELD_GTSDirections
        "GTSList_t",    // FIELD_GTSList
        "uint8_t",    // FIELD_numberOfShortAddressesPending
        "uint8_t",    // FIELD_numberOfExtendedAddressesPending
        "uint64_t",    // FIELD_addressList
        "uint8_t",    // FIELD_beaconPayload
    };
    return (field >= 0 && field < 14) ? fieldTypeStrings[field] : nullptr;
}

const char **MacBeaconFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *MacBeaconFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MacBeaconFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        case FIELD_GTSList: return pp->getGTSListArraySize();
        case FIELD_addressList: return pp->getAddressListArraySize();
        case FIELD_beaconPayload: return pp->getBeaconPayloadArraySize();
        default: return 0;
    }
}

void MacBeaconFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        case FIELD_GTSList: pp->setGTSListArraySize(size); break;
        case FIELD_addressList: pp->setAddressListArraySize(size); break;
        case FIELD_beaconPayload: pp->setBeaconPayloadArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacBeaconFrame'", field);
    }
}

const char *MacBeaconFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacBeaconFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        case FIELD_beaconOrder: return ulong2string(pp->getBeaconOrder());
        case FIELD_superframeOrder: return ulong2string(pp->getSuperframeOrder());
        case FIELD_finalCAPSlot: return ulong2string(pp->getFinalCAPSlot());
        case FIELD_OWPANCoordinator: return bool2string(pp->getOWPANCoordinator());
        case FIELD_associationPermit: return bool2string(pp->getAssociationPermit());
        case FIELD_cellSearchEn: return bool2string(pp->getCellSearchEn());
        case FIELD_GTSDescriptorCount: return ulong2string(pp->getGTSDescriptorCount());
        case FIELD_GTSPermit: return bool2string(pp->getGTSPermit());
        case FIELD_GTSDirections: return ulong2string(pp->getGTSDirections());
        case FIELD_GTSList: return "";
        case FIELD_numberOfShortAddressesPending: return ulong2string(pp->getNumberOfShortAddressesPending());
        case FIELD_numberOfExtendedAddressesPending: return ulong2string(pp->getNumberOfExtendedAddressesPending());
        case FIELD_addressList: return uint642string(pp->getAddressList(i));
        case FIELD_beaconPayload: return ulong2string(pp->getBeaconPayload(i));
        default: return "";
    }
}

void MacBeaconFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        case FIELD_beaconOrder: pp->setBeaconOrder(string2ulong(value)); break;
        case FIELD_superframeOrder: pp->setSuperframeOrder(string2ulong(value)); break;
        case FIELD_finalCAPSlot: pp->setFinalCAPSlot(string2ulong(value)); break;
        case FIELD_OWPANCoordinator: pp->setOWPANCoordinator(string2bool(value)); break;
        case FIELD_associationPermit: pp->setAssociationPermit(string2bool(value)); break;
        case FIELD_cellSearchEn: pp->setCellSearchEn(string2bool(value)); break;
        case FIELD_GTSDescriptorCount: pp->setGTSDescriptorCount(string2ulong(value)); break;
        case FIELD_GTSPermit: pp->setGTSPermit(string2bool(value)); break;
        case FIELD_GTSDirections: pp->setGTSDirections(string2ulong(value)); break;
        case FIELD_numberOfShortAddressesPending: pp->setNumberOfShortAddressesPending(string2ulong(value)); break;
        case FIELD_numberOfExtendedAddressesPending: pp->setNumberOfExtendedAddressesPending(string2ulong(value)); break;
        case FIELD_addressList: pp->setAddressList(i,string2uint64(value)); break;
        case FIELD_beaconPayload: pp->setBeaconPayload(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacBeaconFrame'", field);
    }
}

omnetpp::cValue MacBeaconFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        case FIELD_beaconOrder: return (omnetpp::intval_t)(pp->getBeaconOrder());
        case FIELD_superframeOrder: return (omnetpp::intval_t)(pp->getSuperframeOrder());
        case FIELD_finalCAPSlot: return (omnetpp::intval_t)(pp->getFinalCAPSlot());
        case FIELD_OWPANCoordinator: return pp->getOWPANCoordinator();
        case FIELD_associationPermit: return pp->getAssociationPermit();
        case FIELD_cellSearchEn: return pp->getCellSearchEn();
        case FIELD_GTSDescriptorCount: return (omnetpp::intval_t)(pp->getGTSDescriptorCount());
        case FIELD_GTSPermit: return pp->getGTSPermit();
        case FIELD_GTSDirections: return (omnetpp::intval_t)(pp->getGTSDirections());
        case FIELD_GTSList: return omnetpp::toAnyPtr(&pp->getGTSList(i)); break;
        case FIELD_numberOfShortAddressesPending: return (omnetpp::intval_t)(pp->getNumberOfShortAddressesPending());
        case FIELD_numberOfExtendedAddressesPending: return (omnetpp::intval_t)(pp->getNumberOfExtendedAddressesPending());
        case FIELD_addressList: return (omnetpp::intval_t)(pp->getAddressList(i));
        case FIELD_beaconPayload: return (omnetpp::intval_t)(pp->getBeaconPayload(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacBeaconFrame' as cValue -- field index out of range?", field);
    }
}

void MacBeaconFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        case FIELD_beaconOrder: pp->setBeaconOrder(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_superframeOrder: pp->setSuperframeOrder(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_finalCAPSlot: pp->setFinalCAPSlot(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_OWPANCoordinator: pp->setOWPANCoordinator(value.boolValue()); break;
        case FIELD_associationPermit: pp->setAssociationPermit(value.boolValue()); break;
        case FIELD_cellSearchEn: pp->setCellSearchEn(value.boolValue()); break;
        case FIELD_GTSDescriptorCount: pp->setGTSDescriptorCount(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_GTSPermit: pp->setGTSPermit(value.boolValue()); break;
        case FIELD_GTSDirections: pp->setGTSDirections(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_numberOfShortAddressesPending: pp->setNumberOfShortAddressesPending(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_numberOfExtendedAddressesPending: pp->setNumberOfExtendedAddressesPending(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_addressList: pp->setAddressList(i,omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_beaconPayload: pp->setBeaconPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacBeaconFrame'", field);
    }
}

const char *MacBeaconFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_GTSList: return omnetpp::opp_typename(typeid(GTSList_t));
        default: return nullptr;
    };
}

omnetpp::any_ptr MacBeaconFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        case FIELD_GTSList: return omnetpp::toAnyPtr(&pp->getGTSList(i)); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MacBeaconFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MacBeaconFrame *pp = omnetpp::fromAnyPtr<MacBeaconFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacBeaconFrame'", field);
    }
}

Register_Class(MacDataFrame)

MacDataFrame::MacDataFrame(const char *name, short kind) : ::MacFrame(name, kind)
{
}

MacDataFrame::MacDataFrame(const MacDataFrame& other) : ::MacFrame(other)
{
    copy(other);
}

MacDataFrame::~MacDataFrame()
{
    delete [] this->dataPayload;
}

MacDataFrame& MacDataFrame::operator=(const MacDataFrame& other)
{
    if (this == &other) return *this;
    ::MacFrame::operator=(other);
    copy(other);
    return *this;
}

void MacDataFrame::copy(const MacDataFrame& other)
{
    this->msduType = other.msduType;
    this->numberOfPPDUs = other.numberOfPPDUs;
    delete [] this->dataPayload;
    this->dataPayload = (other.dataPayload_arraysize==0) ? nullptr : new uint8_t[other.dataPayload_arraysize];
    dataPayload_arraysize = other.dataPayload_arraysize;
    for (size_t i = 0; i < dataPayload_arraysize; i++) {
        this->dataPayload[i] = other.dataPayload[i];
    }
}

void MacDataFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MacFrame::parsimPack(b);
    doParsimPacking(b,this->msduType);
    doParsimPacking(b,this->numberOfPPDUs);
    b->pack(dataPayload_arraysize);
    doParsimArrayPacking(b,this->dataPayload,dataPayload_arraysize);
}

void MacDataFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MacFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->msduType);
    doParsimUnpacking(b,this->numberOfPPDUs);
    delete [] this->dataPayload;
    b->unpack(dataPayload_arraysize);
    if (dataPayload_arraysize == 0) {
        this->dataPayload = nullptr;
    } else {
        this->dataPayload = new uint8_t[dataPayload_arraysize];
        doParsimArrayUnpacking(b,this->dataPayload,dataPayload_arraysize);
    }
}

dataType_t MacDataFrame::getMsduType() const
{
    return this->msduType;
}

void MacDataFrame::setMsduType(dataType_t msduType)
{
    this->msduType = msduType;
}

uint8_t MacDataFrame::getNumberOfPPDUs() const
{
    return this->numberOfPPDUs;
}

void MacDataFrame::setNumberOfPPDUs(uint8_t numberOfPPDUs)
{
    this->numberOfPPDUs = numberOfPPDUs;
}

size_t MacDataFrame::getDataPayloadArraySize() const
{
    return dataPayload_arraysize;
}

uint8_t MacDataFrame::getDataPayload(size_t k) const
{
    if (k >= dataPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)dataPayload_arraysize, (unsigned long)k);
    return this->dataPayload[k];
}

void MacDataFrame::setDataPayloadArraySize(size_t newSize)
{
    uint8_t *dataPayload2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = dataPayload_arraysize < newSize ? dataPayload_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        dataPayload2[i] = this->dataPayload[i];
    for (size_t i = minSize; i < newSize; i++)
        dataPayload2[i] = 0;
    delete [] this->dataPayload;
    this->dataPayload = dataPayload2;
    dataPayload_arraysize = newSize;
}

void MacDataFrame::setDataPayload(size_t k, uint8_t dataPayload)
{
    if (k >= dataPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)dataPayload_arraysize, (unsigned long)k);
    this->dataPayload[k] = dataPayload;
}

void MacDataFrame::insertDataPayload(size_t k, uint8_t dataPayload)
{
    if (k > dataPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)dataPayload_arraysize, (unsigned long)k);
    size_t newSize = dataPayload_arraysize + 1;
    uint8_t *dataPayload2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        dataPayload2[i] = this->dataPayload[i];
    dataPayload2[k] = dataPayload;
    for (i = k + 1; i < newSize; i++)
        dataPayload2[i] = this->dataPayload[i-1];
    delete [] this->dataPayload;
    this->dataPayload = dataPayload2;
    dataPayload_arraysize = newSize;
}

void MacDataFrame::appendDataPayload(uint8_t dataPayload)
{
    insertDataPayload(dataPayload_arraysize, dataPayload);
}

void MacDataFrame::eraseDataPayload(size_t k)
{
    if (k >= dataPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)dataPayload_arraysize, (unsigned long)k);
    size_t newSize = dataPayload_arraysize - 1;
    uint8_t *dataPayload2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        dataPayload2[i] = this->dataPayload[i];
    for (i = k; i < newSize; i++)
        dataPayload2[i] = this->dataPayload[i+1];
    delete [] this->dataPayload;
    this->dataPayload = dataPayload2;
    dataPayload_arraysize = newSize;
}

class MacDataFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_msduType,
        FIELD_numberOfPPDUs,
        FIELD_dataPayload,
    };
  public:
    MacDataFrameDescriptor();
    virtual ~MacDataFrameDescriptor();

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

Register_ClassDescriptor(MacDataFrameDescriptor)

MacDataFrameDescriptor::MacDataFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MacDataFrame)), "MacFrame")
{
    propertyNames = nullptr;
}

MacDataFrameDescriptor::~MacDataFrameDescriptor()
{
    delete[] propertyNames;
}

bool MacDataFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacDataFrame *>(obj)!=nullptr;
}

const char **MacDataFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacDataFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacDataFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MacDataFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_msduType
        FD_ISEDITABLE,    // FIELD_numberOfPPDUs
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_dataPayload
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MacDataFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "msduType",
        "numberOfPPDUs",
        "dataPayload",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MacDataFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "msduType") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numberOfPPDUs") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "dataPayload") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MacDataFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "dataType_t",    // FIELD_msduType
        "uint8_t",    // FIELD_numberOfPPDUs
        "uint8_t",    // FIELD_dataPayload
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MacDataFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_msduType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MacDataFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_msduType:
            if (!strcmp(propertyName, "enum")) return "dataType_t";
            return nullptr;
        default: return nullptr;
    }
}

int MacDataFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        case FIELD_dataPayload: return pp->getDataPayloadArraySize();
        default: return 0;
    }
}

void MacDataFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        case FIELD_dataPayload: pp->setDataPayloadArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacDataFrame'", field);
    }
}

const char *MacDataFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacDataFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        case FIELD_msduType: return enum2string(pp->getMsduType(), "dataType_t");
        case FIELD_numberOfPPDUs: return ulong2string(pp->getNumberOfPPDUs());
        case FIELD_dataPayload: return ulong2string(pp->getDataPayload(i));
        default: return "";
    }
}

void MacDataFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        case FIELD_msduType: pp->setMsduType((dataType_t)string2enum(value, "dataType_t")); break;
        case FIELD_numberOfPPDUs: pp->setNumberOfPPDUs(string2ulong(value)); break;
        case FIELD_dataPayload: pp->setDataPayload(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacDataFrame'", field);
    }
}

omnetpp::cValue MacDataFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        case FIELD_msduType: return static_cast<int>(pp->getMsduType());
        case FIELD_numberOfPPDUs: return (omnetpp::intval_t)(pp->getNumberOfPPDUs());
        case FIELD_dataPayload: return (omnetpp::intval_t)(pp->getDataPayload(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacDataFrame' as cValue -- field index out of range?", field);
    }
}

void MacDataFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        case FIELD_msduType: pp->setMsduType(static_cast<dataType_t>(value.intValue())); break;
        case FIELD_numberOfPPDUs: pp->setNumberOfPPDUs(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_dataPayload: pp->setDataPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacDataFrame'", field);
    }
}

const char *MacDataFrameDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MacDataFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MacDataFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MacDataFrame *pp = omnetpp::fromAnyPtr<MacDataFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacDataFrame'", field);
    }
}

Register_Class(MacAckFrame)

MacAckFrame::MacAckFrame(const char *name, short kind) : ::MacFrame(name, kind)
{
}

MacAckFrame::MacAckFrame(const MacAckFrame& other) : ::MacFrame(other)
{
    copy(other);
}

MacAckFrame::~MacAckFrame()
{
}

MacAckFrame& MacAckFrame::operator=(const MacAckFrame& other)
{
    if (this == &other) return *this;
    ::MacFrame::operator=(other);
    copy(other);
    return *this;
}

void MacAckFrame::copy(const MacAckFrame& other)
{
    this->bufferSize = other.bufferSize;
    this->frameCount = other.frameCount;
    this->sequenceControl = other.sequenceControl;
    this->frameBitmap = other.frameBitmap;
}

void MacAckFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MacFrame::parsimPack(b);
    doParsimPacking(b,this->bufferSize);
    doParsimPacking(b,this->frameCount);
    doParsimPacking(b,this->sequenceControl);
    doParsimPacking(b,this->frameBitmap);
}

void MacAckFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MacFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->bufferSize);
    doParsimUnpacking(b,this->frameCount);
    doParsimUnpacking(b,this->sequenceControl);
    doParsimUnpacking(b,this->frameBitmap);
}

uint16_t MacAckFrame::getBufferSize() const
{
    return this->bufferSize;
}

void MacAckFrame::setBufferSize(uint16_t bufferSize)
{
    this->bufferSize = bufferSize;
}

uint8_t MacAckFrame::getFrameCount() const
{
    return this->frameCount;
}

void MacAckFrame::setFrameCount(uint8_t frameCount)
{
    this->frameCount = frameCount;
}

uint16_t MacAckFrame::getSequenceControl() const
{
    return this->sequenceControl;
}

void MacAckFrame::setSequenceControl(uint16_t sequenceControl)
{
    this->sequenceControl = sequenceControl;
}

uint16_t MacAckFrame::getFrameBitmap() const
{
    return this->frameBitmap;
}

void MacAckFrame::setFrameBitmap(uint16_t frameBitmap)
{
    this->frameBitmap = frameBitmap;
}

class MacAckFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_bufferSize,
        FIELD_frameCount,
        FIELD_sequenceControl,
        FIELD_frameBitmap,
    };
  public:
    MacAckFrameDescriptor();
    virtual ~MacAckFrameDescriptor();

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

Register_ClassDescriptor(MacAckFrameDescriptor)

MacAckFrameDescriptor::MacAckFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MacAckFrame)), "MacFrame")
{
    propertyNames = nullptr;
}

MacAckFrameDescriptor::~MacAckFrameDescriptor()
{
    delete[] propertyNames;
}

bool MacAckFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacAckFrame *>(obj)!=nullptr;
}

const char **MacAckFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacAckFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacAckFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int MacAckFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_bufferSize
        FD_ISEDITABLE,    // FIELD_frameCount
        FD_ISEDITABLE,    // FIELD_sequenceControl
        FD_ISEDITABLE,    // FIELD_frameBitmap
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MacAckFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bufferSize",
        "frameCount",
        "sequenceControl",
        "frameBitmap",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MacAckFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "bufferSize") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "frameCount") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "sequenceControl") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "frameBitmap") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *MacAckFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_bufferSize
        "uint8_t",    // FIELD_frameCount
        "uint16_t",    // FIELD_sequenceControl
        "uint16_t",    // FIELD_frameBitmap
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MacAckFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *MacAckFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MacAckFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MacAckFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacAckFrame'", field);
    }
}

const char *MacAckFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacAckFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        case FIELD_bufferSize: return ulong2string(pp->getBufferSize());
        case FIELD_frameCount: return ulong2string(pp->getFrameCount());
        case FIELD_sequenceControl: return ulong2string(pp->getSequenceControl());
        case FIELD_frameBitmap: return ulong2string(pp->getFrameBitmap());
        default: return "";
    }
}

void MacAckFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        case FIELD_bufferSize: pp->setBufferSize(string2ulong(value)); break;
        case FIELD_frameCount: pp->setFrameCount(string2ulong(value)); break;
        case FIELD_sequenceControl: pp->setSequenceControl(string2ulong(value)); break;
        case FIELD_frameBitmap: pp->setFrameBitmap(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacAckFrame'", field);
    }
}

omnetpp::cValue MacAckFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        case FIELD_bufferSize: return (omnetpp::intval_t)(pp->getBufferSize());
        case FIELD_frameCount: return (omnetpp::intval_t)(pp->getFrameCount());
        case FIELD_sequenceControl: return (omnetpp::intval_t)(pp->getSequenceControl());
        case FIELD_frameBitmap: return (omnetpp::intval_t)(pp->getFrameBitmap());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacAckFrame' as cValue -- field index out of range?", field);
    }
}

void MacAckFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        case FIELD_bufferSize: pp->setBufferSize(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_frameCount: pp->setFrameCount(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_sequenceControl: pp->setSequenceControl(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_frameBitmap: pp->setFrameBitmap(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacAckFrame'", field);
    }
}

const char *MacAckFrameDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MacAckFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MacAckFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MacAckFrame *pp = omnetpp::fromAnyPtr<MacAckFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacAckFrame'", field);
    }
}

Register_Class(MacCommandFrame)

MacCommandFrame::MacCommandFrame(const char *name, short kind) : ::MacFrame(name, kind)
{
}

MacCommandFrame::MacCommandFrame(const MacCommandFrame& other) : ::MacFrame(other)
{
    copy(other);
}

MacCommandFrame::~MacCommandFrame()
{
    delete [] this->commandPayload;
}

MacCommandFrame& MacCommandFrame::operator=(const MacCommandFrame& other)
{
    if (this == &other) return *this;
    ::MacFrame::operator=(other);
    copy(other);
    return *this;
}

void MacCommandFrame::copy(const MacCommandFrame& other)
{
    this->commandFrameIdentifier = other.commandFrameIdentifier;
    delete [] this->commandPayload;
    this->commandPayload = (other.commandPayload_arraysize==0) ? nullptr : new uint8_t[other.commandPayload_arraysize];
    commandPayload_arraysize = other.commandPayload_arraysize;
    for (size_t i = 0; i < commandPayload_arraysize; i++) {
        this->commandPayload[i] = other.commandPayload[i];
    }
}

void MacCommandFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MacFrame::parsimPack(b);
    doParsimPacking(b,this->commandFrameIdentifier);
    b->pack(commandPayload_arraysize);
    doParsimArrayPacking(b,this->commandPayload,commandPayload_arraysize);
}

void MacCommandFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MacFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->commandFrameIdentifier);
    delete [] this->commandPayload;
    b->unpack(commandPayload_arraysize);
    if (commandPayload_arraysize == 0) {
        this->commandPayload = nullptr;
    } else {
        this->commandPayload = new uint8_t[commandPayload_arraysize];
        doParsimArrayUnpacking(b,this->commandPayload,commandPayload_arraysize);
    }
}

commandFrameIdentifier_t MacCommandFrame::getCommandFrameIdentifier() const
{
    return this->commandFrameIdentifier;
}

void MacCommandFrame::setCommandFrameIdentifier(commandFrameIdentifier_t commandFrameIdentifier)
{
    this->commandFrameIdentifier = commandFrameIdentifier;
}

size_t MacCommandFrame::getCommandPayloadArraySize() const
{
    return commandPayload_arraysize;
}

uint8_t MacCommandFrame::getCommandPayload(size_t k) const
{
    if (k >= commandPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)commandPayload_arraysize, (unsigned long)k);
    return this->commandPayload[k];
}

void MacCommandFrame::setCommandPayloadArraySize(size_t newSize)
{
    uint8_t *commandPayload2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = commandPayload_arraysize < newSize ? commandPayload_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        commandPayload2[i] = this->commandPayload[i];
    for (size_t i = minSize; i < newSize; i++)
        commandPayload2[i] = 0;
    delete [] this->commandPayload;
    this->commandPayload = commandPayload2;
    commandPayload_arraysize = newSize;
}

void MacCommandFrame::setCommandPayload(size_t k, uint8_t commandPayload)
{
    if (k >= commandPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)commandPayload_arraysize, (unsigned long)k);
    this->commandPayload[k] = commandPayload;
}

void MacCommandFrame::insertCommandPayload(size_t k, uint8_t commandPayload)
{
    if (k > commandPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)commandPayload_arraysize, (unsigned long)k);
    size_t newSize = commandPayload_arraysize + 1;
    uint8_t *commandPayload2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        commandPayload2[i] = this->commandPayload[i];
    commandPayload2[k] = commandPayload;
    for (i = k + 1; i < newSize; i++)
        commandPayload2[i] = this->commandPayload[i-1];
    delete [] this->commandPayload;
    this->commandPayload = commandPayload2;
    commandPayload_arraysize = newSize;
}

void MacCommandFrame::appendCommandPayload(uint8_t commandPayload)
{
    insertCommandPayload(commandPayload_arraysize, commandPayload);
}

void MacCommandFrame::eraseCommandPayload(size_t k)
{
    if (k >= commandPayload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)commandPayload_arraysize, (unsigned long)k);
    size_t newSize = commandPayload_arraysize - 1;
    uint8_t *commandPayload2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        commandPayload2[i] = this->commandPayload[i];
    for (i = k; i < newSize; i++)
        commandPayload2[i] = this->commandPayload[i+1];
    delete [] this->commandPayload;
    this->commandPayload = commandPayload2;
    commandPayload_arraysize = newSize;
}

class MacCommandFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_commandFrameIdentifier,
        FIELD_commandPayload,
    };
  public:
    MacCommandFrameDescriptor();
    virtual ~MacCommandFrameDescriptor();

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

Register_ClassDescriptor(MacCommandFrameDescriptor)

MacCommandFrameDescriptor::MacCommandFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MacCommandFrame)), "MacFrame")
{
    propertyNames = nullptr;
}

MacCommandFrameDescriptor::~MacCommandFrameDescriptor()
{
    delete[] propertyNames;
}

bool MacCommandFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacCommandFrame *>(obj)!=nullptr;
}

const char **MacCommandFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacCommandFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacCommandFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int MacCommandFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_commandFrameIdentifier
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_commandPayload
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MacCommandFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "commandFrameIdentifier",
        "commandPayload",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MacCommandFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "commandFrameIdentifier") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "commandPayload") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *MacCommandFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "commandFrameIdentifier_t",    // FIELD_commandFrameIdentifier
        "uint8_t",    // FIELD_commandPayload
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MacCommandFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_commandFrameIdentifier: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MacCommandFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_commandFrameIdentifier:
            if (!strcmp(propertyName, "enum")) return "commandFrameIdentifier_t";
            return nullptr;
        default: return nullptr;
    }
}

int MacCommandFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        case FIELD_commandPayload: return pp->getCommandPayloadArraySize();
        default: return 0;
    }
}

void MacCommandFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        case FIELD_commandPayload: pp->setCommandPayloadArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacCommandFrame'", field);
    }
}

const char *MacCommandFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacCommandFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        case FIELD_commandFrameIdentifier: return enum2string(pp->getCommandFrameIdentifier(), "commandFrameIdentifier_t");
        case FIELD_commandPayload: return ulong2string(pp->getCommandPayload(i));
        default: return "";
    }
}

void MacCommandFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        case FIELD_commandFrameIdentifier: pp->setCommandFrameIdentifier((commandFrameIdentifier_t)string2enum(value, "commandFrameIdentifier_t")); break;
        case FIELD_commandPayload: pp->setCommandPayload(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacCommandFrame'", field);
    }
}

omnetpp::cValue MacCommandFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        case FIELD_commandFrameIdentifier: return static_cast<int>(pp->getCommandFrameIdentifier());
        case FIELD_commandPayload: return (omnetpp::intval_t)(pp->getCommandPayload(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacCommandFrame' as cValue -- field index out of range?", field);
    }
}

void MacCommandFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        case FIELD_commandFrameIdentifier: pp->setCommandFrameIdentifier(static_cast<commandFrameIdentifier_t>(value.intValue())); break;
        case FIELD_commandPayload: pp->setCommandPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacCommandFrame'", field);
    }
}

const char *MacCommandFrameDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MacCommandFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MacCommandFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MacCommandFrame *pp = omnetpp::fromAnyPtr<MacCommandFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacCommandFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

