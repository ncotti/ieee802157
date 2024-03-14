//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/phy_msgs/pd.msg.
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
#include "pd_m.h"

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

Register_Class(PDDataRequest)

PDDataRequest::PDDataRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PDDataRequest::PDDataRequest(const PDDataRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PDDataRequest::~PDDataRequest()
{
    delete [] this->psdu;
}

PDDataRequest& PDDataRequest::operator=(const PDDataRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PDDataRequest::copy(const PDDataRequest& other)
{
    this->psduLength = other.psduLength;
    delete [] this->psdu;
    this->psdu = (other.psdu_arraysize==0) ? nullptr : new uint8_t[other.psdu_arraysize];
    psdu_arraysize = other.psdu_arraysize;
    for (size_t i = 0; i < psdu_arraysize; i++) {
        this->psdu[i] = other.psdu[i];
    }
    this->bandplanID = other.bandplanID;
}

void PDDataRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->psduLength);
    b->pack(psdu_arraysize);
    doParsimArrayPacking(b,this->psdu,psdu_arraysize);
    doParsimPacking(b,this->bandplanID);
}

void PDDataRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->psduLength);
    delete [] this->psdu;
    b->unpack(psdu_arraysize);
    if (psdu_arraysize == 0) {
        this->psdu = nullptr;
    } else {
        this->psdu = new uint8_t[psdu_arraysize];
        doParsimArrayUnpacking(b,this->psdu,psdu_arraysize);
    }
    doParsimUnpacking(b,this->bandplanID);
}

uint32_t PDDataRequest::getPsduLength() const
{
    return this->psduLength;
}

void PDDataRequest::setPsduLength(uint32_t psduLength)
{
    this->psduLength = psduLength;
}

size_t PDDataRequest::getPsduArraySize() const
{
    return psdu_arraysize;
}

uint8_t PDDataRequest::getPsdu(size_t k) const
{
    if (k >= psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    return this->psdu[k];
}

void PDDataRequest::setPsduArraySize(size_t newSize)
{
    uint8_t *psdu2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = psdu_arraysize < newSize ? psdu_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        psdu2[i] = this->psdu[i];
    for (size_t i = minSize; i < newSize; i++)
        psdu2[i] = 0;
    delete [] this->psdu;
    this->psdu = psdu2;
    psdu_arraysize = newSize;
}

void PDDataRequest::setPsdu(size_t k, uint8_t psdu)
{
    if (k >= psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    this->psdu[k] = psdu;
}

void PDDataRequest::insertPsdu(size_t k, uint8_t psdu)
{
    if (k > psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    size_t newSize = psdu_arraysize + 1;
    uint8_t *psdu2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        psdu2[i] = this->psdu[i];
    psdu2[k] = psdu;
    for (i = k + 1; i < newSize; i++)
        psdu2[i] = this->psdu[i-1];
    delete [] this->psdu;
    this->psdu = psdu2;
    psdu_arraysize = newSize;
}

void PDDataRequest::appendPsdu(uint8_t psdu)
{
    insertPsdu(psdu_arraysize, psdu);
}

void PDDataRequest::erasePsdu(size_t k)
{
    if (k >= psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    size_t newSize = psdu_arraysize - 1;
    uint8_t *psdu2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        psdu2[i] = this->psdu[i];
    for (i = k; i < newSize; i++)
        psdu2[i] = this->psdu[i+1];
    delete [] this->psdu;
    this->psdu = psdu2;
    psdu_arraysize = newSize;
}

uint32_t PDDataRequest::getBandplanID() const
{
    return this->bandplanID;
}

void PDDataRequest::setBandplanID(uint32_t bandplanID)
{
    this->bandplanID = bandplanID;
}

class PDDataRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_psduLength,
        FIELD_psdu,
        FIELD_bandplanID,
    };
  public:
    PDDataRequestDescriptor();
    virtual ~PDDataRequestDescriptor();

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

Register_ClassDescriptor(PDDataRequestDescriptor)

PDDataRequestDescriptor::PDDataRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PDDataRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PDDataRequestDescriptor::~PDDataRequestDescriptor()
{
    delete[] propertyNames;
}

bool PDDataRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PDDataRequest *>(obj)!=nullptr;
}

const char **PDDataRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PDDataRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PDDataRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int PDDataRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_psduLength
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_psdu
        FD_ISEDITABLE,    // FIELD_bandplanID
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *PDDataRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "psduLength",
        "psdu",
        "bandplanID",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int PDDataRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "psduLength") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "psdu") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "bandplanID") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *PDDataRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_psduLength
        "uint8_t",    // FIELD_psdu
        "uint32_t",    // FIELD_bandplanID
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **PDDataRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *PDDataRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PDDataRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_psdu: return pp->getPsduArraySize();
        default: return 0;
    }
}

void PDDataRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_psdu: pp->setPsduArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PDDataRequest'", field);
    }
}

const char *PDDataRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PDDataRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: return ulong2string(pp->getPsduLength());
        case FIELD_psdu: return ulong2string(pp->getPsdu(i));
        case FIELD_bandplanID: return ulong2string(pp->getBandplanID());
        default: return "";
    }
}

void PDDataRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: pp->setPsduLength(string2ulong(value)); break;
        case FIELD_psdu: pp->setPsdu(i,string2ulong(value)); break;
        case FIELD_bandplanID: pp->setBandplanID(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataRequest'", field);
    }
}

omnetpp::cValue PDDataRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: return (omnetpp::intval_t)(pp->getPsduLength());
        case FIELD_psdu: return (omnetpp::intval_t)(pp->getPsdu(i));
        case FIELD_bandplanID: return (omnetpp::intval_t)(pp->getBandplanID());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PDDataRequest' as cValue -- field index out of range?", field);
    }
}

void PDDataRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: pp->setPsduLength(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_psdu: pp->setPsdu(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_bandplanID: pp->setBandplanID(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataRequest'", field);
    }
}

const char *PDDataRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PDDataRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PDDataRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataRequest *pp = omnetpp::fromAnyPtr<PDDataRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataRequest'", field);
    }
}

Register_Class(PDDataConfirm)

PDDataConfirm::PDDataConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PDDataConfirm::PDDataConfirm(const PDDataConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PDDataConfirm::~PDDataConfirm()
{
}

PDDataConfirm& PDDataConfirm::operator=(const PDDataConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PDDataConfirm::copy(const PDDataConfirm& other)
{
    this->status = other.status;
}

void PDDataConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void PDDataConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

uint8_t PDDataConfirm::getStatus() const
{
    return this->status;
}

void PDDataConfirm::setStatus(uint8_t status)
{
    this->status = status;
}

class PDDataConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    PDDataConfirmDescriptor();
    virtual ~PDDataConfirmDescriptor();

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

Register_ClassDescriptor(PDDataConfirmDescriptor)

PDDataConfirmDescriptor::PDDataConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PDDataConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PDDataConfirmDescriptor::~PDDataConfirmDescriptor()
{
    delete[] propertyNames;
}

bool PDDataConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PDDataConfirm *>(obj)!=nullptr;
}

const char **PDDataConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PDDataConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PDDataConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PDDataConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PDDataConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PDDataConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PDDataConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PDDataConfirmDescriptor::getFieldPropertyNames(int field) const
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

const char *PDDataConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PDDataConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PDDataConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PDDataConfirm'", field);
    }
}

const char *PDDataConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PDDataConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return ulong2string(pp->getStatus());
        default: return "";
    }
}

void PDDataConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataConfirm'", field);
    }
}

omnetpp::cValue PDDataConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return (omnetpp::intval_t)(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PDDataConfirm' as cValue -- field index out of range?", field);
    }
}

void PDDataConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataConfirm'", field);
    }
}

const char *PDDataConfirmDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PDDataConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PDDataConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataConfirm *pp = omnetpp::fromAnyPtr<PDDataConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataConfirm'", field);
    }
}

Register_Class(PDDataIndication)

PDDataIndication::PDDataIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PDDataIndication::PDDataIndication(const PDDataIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PDDataIndication::~PDDataIndication()
{
    delete [] this->psdu;
}

PDDataIndication& PDDataIndication::operator=(const PDDataIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PDDataIndication::copy(const PDDataIndication& other)
{
    this->psduLength = other.psduLength;
    delete [] this->psdu;
    this->psdu = (other.psdu_arraysize==0) ? nullptr : new uint8_t[other.psdu_arraysize];
    psdu_arraysize = other.psdu_arraysize;
    for (size_t i = 0; i < psdu_arraysize; i++) {
        this->psdu[i] = other.psdu[i];
    }
    this->ppduLinkQuality = other.ppduLinkQuality;
}

void PDDataIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->psduLength);
    b->pack(psdu_arraysize);
    doParsimArrayPacking(b,this->psdu,psdu_arraysize);
    doParsimPacking(b,this->ppduLinkQuality);
}

void PDDataIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->psduLength);
    delete [] this->psdu;
    b->unpack(psdu_arraysize);
    if (psdu_arraysize == 0) {
        this->psdu = nullptr;
    } else {
        this->psdu = new uint8_t[psdu_arraysize];
        doParsimArrayUnpacking(b,this->psdu,psdu_arraysize);
    }
    doParsimUnpacking(b,this->ppduLinkQuality);
}

uint32_t PDDataIndication::getPsduLength() const
{
    return this->psduLength;
}

void PDDataIndication::setPsduLength(uint32_t psduLength)
{
    this->psduLength = psduLength;
}

size_t PDDataIndication::getPsduArraySize() const
{
    return psdu_arraysize;
}

uint8_t PDDataIndication::getPsdu(size_t k) const
{
    if (k >= psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    return this->psdu[k];
}

void PDDataIndication::setPsduArraySize(size_t newSize)
{
    uint8_t *psdu2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = psdu_arraysize < newSize ? psdu_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        psdu2[i] = this->psdu[i];
    for (size_t i = minSize; i < newSize; i++)
        psdu2[i] = 0;
    delete [] this->psdu;
    this->psdu = psdu2;
    psdu_arraysize = newSize;
}

void PDDataIndication::setPsdu(size_t k, uint8_t psdu)
{
    if (k >= psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    this->psdu[k] = psdu;
}

void PDDataIndication::insertPsdu(size_t k, uint8_t psdu)
{
    if (k > psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    size_t newSize = psdu_arraysize + 1;
    uint8_t *psdu2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        psdu2[i] = this->psdu[i];
    psdu2[k] = psdu;
    for (i = k + 1; i < newSize; i++)
        psdu2[i] = this->psdu[i-1];
    delete [] this->psdu;
    this->psdu = psdu2;
    psdu_arraysize = newSize;
}

void PDDataIndication::appendPsdu(uint8_t psdu)
{
    insertPsdu(psdu_arraysize, psdu);
}

void PDDataIndication::erasePsdu(size_t k)
{
    if (k >= psdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)psdu_arraysize, (unsigned long)k);
    size_t newSize = psdu_arraysize - 1;
    uint8_t *psdu2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        psdu2[i] = this->psdu[i];
    for (i = k; i < newSize; i++)
        psdu2[i] = this->psdu[i+1];
    delete [] this->psdu;
    this->psdu = psdu2;
    psdu_arraysize = newSize;
}

uint32_t PDDataIndication::getPpduLinkQuality() const
{
    return this->ppduLinkQuality;
}

void PDDataIndication::setPpduLinkQuality(uint32_t ppduLinkQuality)
{
    this->ppduLinkQuality = ppduLinkQuality;
}

class PDDataIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_psduLength,
        FIELD_psdu,
        FIELD_ppduLinkQuality,
    };
  public:
    PDDataIndicationDescriptor();
    virtual ~PDDataIndicationDescriptor();

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

Register_ClassDescriptor(PDDataIndicationDescriptor)

PDDataIndicationDescriptor::PDDataIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PDDataIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PDDataIndicationDescriptor::~PDDataIndicationDescriptor()
{
    delete[] propertyNames;
}

bool PDDataIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PDDataIndication *>(obj)!=nullptr;
}

const char **PDDataIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PDDataIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PDDataIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int PDDataIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_psduLength
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_psdu
        FD_ISEDITABLE,    // FIELD_ppduLinkQuality
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *PDDataIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "psduLength",
        "psdu",
        "ppduLinkQuality",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int PDDataIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "psduLength") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "psdu") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ppduLinkQuality") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *PDDataIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_psduLength
        "uint8_t",    // FIELD_psdu
        "uint32_t",    // FIELD_ppduLinkQuality
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **PDDataIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *PDDataIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PDDataIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_psdu: return pp->getPsduArraySize();
        default: return 0;
    }
}

void PDDataIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_psdu: pp->setPsduArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PDDataIndication'", field);
    }
}

const char *PDDataIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PDDataIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: return ulong2string(pp->getPsduLength());
        case FIELD_psdu: return ulong2string(pp->getPsdu(i));
        case FIELD_ppduLinkQuality: return ulong2string(pp->getPpduLinkQuality());
        default: return "";
    }
}

void PDDataIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: pp->setPsduLength(string2ulong(value)); break;
        case FIELD_psdu: pp->setPsdu(i,string2ulong(value)); break;
        case FIELD_ppduLinkQuality: pp->setPpduLinkQuality(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataIndication'", field);
    }
}

omnetpp::cValue PDDataIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: return (omnetpp::intval_t)(pp->getPsduLength());
        case FIELD_psdu: return (omnetpp::intval_t)(pp->getPsdu(i));
        case FIELD_ppduLinkQuality: return (omnetpp::intval_t)(pp->getPpduLinkQuality());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PDDataIndication' as cValue -- field index out of range?", field);
    }
}

void PDDataIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_psduLength: pp->setPsduLength(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_psdu: pp->setPsdu(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_ppduLinkQuality: pp->setPpduLinkQuality(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataIndication'", field);
    }
}

const char *PDDataIndicationDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PDDataIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PDDataIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PDDataIndication *pp = omnetpp::fromAnyPtr<PDDataIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PDDataIndication'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

