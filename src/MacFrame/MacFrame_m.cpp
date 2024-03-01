//
// Generated file, do not edit! Created by opp_msgtool 6.0 from MacFrame/MacFrame.msg.
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
#include "MacFrame_m.h"

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

MacFrame_Base::MacFrame_Base(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

MacFrame_Base::MacFrame_Base(const MacFrame_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

MacFrame_Base::~MacFrame_Base()
{
    delete [] this->destinationOWPANId;
    delete [] this->destinationAddress;
    delete [] this->sourceOWPANId;
    delete [] this->sourceAddress;
    delete [] this->auxiliarySecurityHeader;
    delete [] this->payload;
}

MacFrame_Base& MacFrame_Base::operator=(const MacFrame_Base& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MacFrame_Base::copy(const MacFrame_Base& other)
{
    this->frameControl = other.frameControl;
    this->sequenceNumber = other.sequenceNumber;
    delete [] this->destinationOWPANId;
    this->destinationOWPANId = (other.destinationOWPANId_arraysize==0) ? nullptr : new uint16_t[other.destinationOWPANId_arraysize];
    destinationOWPANId_arraysize = other.destinationOWPANId_arraysize;
    for (size_t i = 0; i < destinationOWPANId_arraysize; i++) {
        this->destinationOWPANId[i] = other.destinationOWPANId[i];
    }
    delete [] this->destinationAddress;
    this->destinationAddress = (other.destinationAddress_arraysize==0) ? nullptr : new uint16_t[other.destinationAddress_arraysize];
    destinationAddress_arraysize = other.destinationAddress_arraysize;
    for (size_t i = 0; i < destinationAddress_arraysize; i++) {
        this->destinationAddress[i] = other.destinationAddress[i];
    }
    delete [] this->sourceOWPANId;
    this->sourceOWPANId = (other.sourceOWPANId_arraysize==0) ? nullptr : new uint16_t[other.sourceOWPANId_arraysize];
    sourceOWPANId_arraysize = other.sourceOWPANId_arraysize;
    for (size_t i = 0; i < sourceOWPANId_arraysize; i++) {
        this->sourceOWPANId[i] = other.sourceOWPANId[i];
    }
    delete [] this->sourceAddress;
    this->sourceAddress = (other.sourceAddress_arraysize==0) ? nullptr : new uint16_t[other.sourceAddress_arraysize];
    sourceAddress_arraysize = other.sourceAddress_arraysize;
    for (size_t i = 0; i < sourceAddress_arraysize; i++) {
        this->sourceAddress[i] = other.sourceAddress[i];
    }
    delete [] this->auxiliarySecurityHeader;
    this->auxiliarySecurityHeader = (other.auxiliarySecurityHeader_arraysize==0) ? nullptr : new uint8_t[other.auxiliarySecurityHeader_arraysize];
    auxiliarySecurityHeader_arraysize = other.auxiliarySecurityHeader_arraysize;
    for (size_t i = 0; i < auxiliarySecurityHeader_arraysize; i++) {
        this->auxiliarySecurityHeader[i] = other.auxiliarySecurityHeader[i];
    }
    delete [] this->payload;
    this->payload = (other.payload_arraysize==0) ? nullptr : new uint8_t[other.payload_arraysize];
    payload_arraysize = other.payload_arraysize;
    for (size_t i = 0; i < payload_arraysize; i++) {
        this->payload[i] = other.payload[i];
    }
    this->fcs = other.fcs;
}

void MacFrame_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->frameControl);
    doParsimPacking(b,this->sequenceNumber);
    b->pack(destinationOWPANId_arraysize);
    doParsimArrayPacking(b,this->destinationOWPANId,destinationOWPANId_arraysize);
    b->pack(destinationAddress_arraysize);
    doParsimArrayPacking(b,this->destinationAddress,destinationAddress_arraysize);
    b->pack(sourceOWPANId_arraysize);
    doParsimArrayPacking(b,this->sourceOWPANId,sourceOWPANId_arraysize);
    b->pack(sourceAddress_arraysize);
    doParsimArrayPacking(b,this->sourceAddress,sourceAddress_arraysize);
    b->pack(auxiliarySecurityHeader_arraysize);
    doParsimArrayPacking(b,this->auxiliarySecurityHeader,auxiliarySecurityHeader_arraysize);
    b->pack(payload_arraysize);
    doParsimArrayPacking(b,this->payload,payload_arraysize);
    doParsimPacking(b,this->fcs);
}

void MacFrame_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->frameControl);
    doParsimUnpacking(b,this->sequenceNumber);
    delete [] this->destinationOWPANId;
    b->unpack(destinationOWPANId_arraysize);
    if (destinationOWPANId_arraysize == 0) {
        this->destinationOWPANId = nullptr;
    } else {
        this->destinationOWPANId = new uint16_t[destinationOWPANId_arraysize];
        doParsimArrayUnpacking(b,this->destinationOWPANId,destinationOWPANId_arraysize);
    }
    delete [] this->destinationAddress;
    b->unpack(destinationAddress_arraysize);
    if (destinationAddress_arraysize == 0) {
        this->destinationAddress = nullptr;
    } else {
        this->destinationAddress = new uint16_t[destinationAddress_arraysize];
        doParsimArrayUnpacking(b,this->destinationAddress,destinationAddress_arraysize);
    }
    delete [] this->sourceOWPANId;
    b->unpack(sourceOWPANId_arraysize);
    if (sourceOWPANId_arraysize == 0) {
        this->sourceOWPANId = nullptr;
    } else {
        this->sourceOWPANId = new uint16_t[sourceOWPANId_arraysize];
        doParsimArrayUnpacking(b,this->sourceOWPANId,sourceOWPANId_arraysize);
    }
    delete [] this->sourceAddress;
    b->unpack(sourceAddress_arraysize);
    if (sourceAddress_arraysize == 0) {
        this->sourceAddress = nullptr;
    } else {
        this->sourceAddress = new uint16_t[sourceAddress_arraysize];
        doParsimArrayUnpacking(b,this->sourceAddress,sourceAddress_arraysize);
    }
    delete [] this->auxiliarySecurityHeader;
    b->unpack(auxiliarySecurityHeader_arraysize);
    if (auxiliarySecurityHeader_arraysize == 0) {
        this->auxiliarySecurityHeader = nullptr;
    } else {
        this->auxiliarySecurityHeader = new uint8_t[auxiliarySecurityHeader_arraysize];
        doParsimArrayUnpacking(b,this->auxiliarySecurityHeader,auxiliarySecurityHeader_arraysize);
    }
    delete [] this->payload;
    b->unpack(payload_arraysize);
    if (payload_arraysize == 0) {
        this->payload = nullptr;
    } else {
        this->payload = new uint8_t[payload_arraysize];
        doParsimArrayUnpacking(b,this->payload,payload_arraysize);
    }
    doParsimUnpacking(b,this->fcs);
}

uint16_t MacFrame_Base::getFrameControl() const
{
    return this->frameControl;
}

void MacFrame_Base::setFrameControl(uint16_t frameControl)
{
    this->frameControl = frameControl;
}

uint8_t MacFrame_Base::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void MacFrame_Base::setSequenceNumber(uint8_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

size_t MacFrame_Base::getDestinationOWPANIdArraySize() const
{
    return destinationOWPANId_arraysize;
}

uint16_t MacFrame_Base::getDestinationOWPANId(size_t k) const
{
    if (k >= destinationOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationOWPANId_arraysize, (unsigned long)k);
    return this->destinationOWPANId[k];
}

void MacFrame_Base::setDestinationOWPANIdArraySize(size_t newSize)
{
    uint16_t *destinationOWPANId2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = destinationOWPANId_arraysize < newSize ? destinationOWPANId_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        destinationOWPANId2[i] = this->destinationOWPANId[i];
    for (size_t i = minSize; i < newSize; i++)
        destinationOWPANId2[i] = 0;
    delete [] this->destinationOWPANId;
    this->destinationOWPANId = destinationOWPANId2;
    destinationOWPANId_arraysize = newSize;
}

void MacFrame_Base::setDestinationOWPANId(size_t k, uint16_t destinationOWPANId)
{
    if (k >= destinationOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationOWPANId_arraysize, (unsigned long)k);
    this->destinationOWPANId[k] = destinationOWPANId;
}

void MacFrame_Base::insertDestinationOWPANId(size_t k, uint16_t destinationOWPANId)
{
    if (k > destinationOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationOWPANId_arraysize, (unsigned long)k);
    size_t newSize = destinationOWPANId_arraysize + 1;
    uint16_t *destinationOWPANId2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        destinationOWPANId2[i] = this->destinationOWPANId[i];
    destinationOWPANId2[k] = destinationOWPANId;
    for (i = k + 1; i < newSize; i++)
        destinationOWPANId2[i] = this->destinationOWPANId[i-1];
    delete [] this->destinationOWPANId;
    this->destinationOWPANId = destinationOWPANId2;
    destinationOWPANId_arraysize = newSize;
}

void MacFrame_Base::appendDestinationOWPANId(uint16_t destinationOWPANId)
{
    insertDestinationOWPANId(destinationOWPANId_arraysize, destinationOWPANId);
}

void MacFrame_Base::eraseDestinationOWPANId(size_t k)
{
    if (k >= destinationOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationOWPANId_arraysize, (unsigned long)k);
    size_t newSize = destinationOWPANId_arraysize - 1;
    uint16_t *destinationOWPANId2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        destinationOWPANId2[i] = this->destinationOWPANId[i];
    for (i = k; i < newSize; i++)
        destinationOWPANId2[i] = this->destinationOWPANId[i+1];
    delete [] this->destinationOWPANId;
    this->destinationOWPANId = destinationOWPANId2;
    destinationOWPANId_arraysize = newSize;
}

size_t MacFrame_Base::getDestinationAddressArraySize() const
{
    return destinationAddress_arraysize;
}

uint16_t MacFrame_Base::getDestinationAddress(size_t k) const
{
    if (k >= destinationAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationAddress_arraysize, (unsigned long)k);
    return this->destinationAddress[k];
}

void MacFrame_Base::setDestinationAddressArraySize(size_t newSize)
{
    uint16_t *destinationAddress2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = destinationAddress_arraysize < newSize ? destinationAddress_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        destinationAddress2[i] = this->destinationAddress[i];
    for (size_t i = minSize; i < newSize; i++)
        destinationAddress2[i] = 0;
    delete [] this->destinationAddress;
    this->destinationAddress = destinationAddress2;
    destinationAddress_arraysize = newSize;
}

void MacFrame_Base::setDestinationAddress(size_t k, uint16_t destinationAddress)
{
    if (k >= destinationAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationAddress_arraysize, (unsigned long)k);
    this->destinationAddress[k] = destinationAddress;
}

void MacFrame_Base::insertDestinationAddress(size_t k, uint16_t destinationAddress)
{
    if (k > destinationAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationAddress_arraysize, (unsigned long)k);
    size_t newSize = destinationAddress_arraysize + 1;
    uint16_t *destinationAddress2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        destinationAddress2[i] = this->destinationAddress[i];
    destinationAddress2[k] = destinationAddress;
    for (i = k + 1; i < newSize; i++)
        destinationAddress2[i] = this->destinationAddress[i-1];
    delete [] this->destinationAddress;
    this->destinationAddress = destinationAddress2;
    destinationAddress_arraysize = newSize;
}

void MacFrame_Base::appendDestinationAddress(uint16_t destinationAddress)
{
    insertDestinationAddress(destinationAddress_arraysize, destinationAddress);
}

void MacFrame_Base::eraseDestinationAddress(size_t k)
{
    if (k >= destinationAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)destinationAddress_arraysize, (unsigned long)k);
    size_t newSize = destinationAddress_arraysize - 1;
    uint16_t *destinationAddress2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        destinationAddress2[i] = this->destinationAddress[i];
    for (i = k; i < newSize; i++)
        destinationAddress2[i] = this->destinationAddress[i+1];
    delete [] this->destinationAddress;
    this->destinationAddress = destinationAddress2;
    destinationAddress_arraysize = newSize;
}

size_t MacFrame_Base::getSourceOWPANIdArraySize() const
{
    return sourceOWPANId_arraysize;
}

uint16_t MacFrame_Base::getSourceOWPANId(size_t k) const
{
    if (k >= sourceOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceOWPANId_arraysize, (unsigned long)k);
    return this->sourceOWPANId[k];
}

void MacFrame_Base::setSourceOWPANIdArraySize(size_t newSize)
{
    uint16_t *sourceOWPANId2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sourceOWPANId_arraysize < newSize ? sourceOWPANId_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sourceOWPANId2[i] = this->sourceOWPANId[i];
    for (size_t i = minSize; i < newSize; i++)
        sourceOWPANId2[i] = 0;
    delete [] this->sourceOWPANId;
    this->sourceOWPANId = sourceOWPANId2;
    sourceOWPANId_arraysize = newSize;
}

void MacFrame_Base::setSourceOWPANId(size_t k, uint16_t sourceOWPANId)
{
    if (k >= sourceOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceOWPANId_arraysize, (unsigned long)k);
    this->sourceOWPANId[k] = sourceOWPANId;
}

void MacFrame_Base::insertSourceOWPANId(size_t k, uint16_t sourceOWPANId)
{
    if (k > sourceOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceOWPANId_arraysize, (unsigned long)k);
    size_t newSize = sourceOWPANId_arraysize + 1;
    uint16_t *sourceOWPANId2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceOWPANId2[i] = this->sourceOWPANId[i];
    sourceOWPANId2[k] = sourceOWPANId;
    for (i = k + 1; i < newSize; i++)
        sourceOWPANId2[i] = this->sourceOWPANId[i-1];
    delete [] this->sourceOWPANId;
    this->sourceOWPANId = sourceOWPANId2;
    sourceOWPANId_arraysize = newSize;
}

void MacFrame_Base::appendSourceOWPANId(uint16_t sourceOWPANId)
{
    insertSourceOWPANId(sourceOWPANId_arraysize, sourceOWPANId);
}

void MacFrame_Base::eraseSourceOWPANId(size_t k)
{
    if (k >= sourceOWPANId_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceOWPANId_arraysize, (unsigned long)k);
    size_t newSize = sourceOWPANId_arraysize - 1;
    uint16_t *sourceOWPANId2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceOWPANId2[i] = this->sourceOWPANId[i];
    for (i = k; i < newSize; i++)
        sourceOWPANId2[i] = this->sourceOWPANId[i+1];
    delete [] this->sourceOWPANId;
    this->sourceOWPANId = sourceOWPANId2;
    sourceOWPANId_arraysize = newSize;
}

size_t MacFrame_Base::getSourceAddressArraySize() const
{
    return sourceAddress_arraysize;
}

uint16_t MacFrame_Base::getSourceAddress(size_t k) const
{
    if (k >= sourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceAddress_arraysize, (unsigned long)k);
    return this->sourceAddress[k];
}

void MacFrame_Base::setSourceAddressArraySize(size_t newSize)
{
    uint16_t *sourceAddress2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sourceAddress_arraysize < newSize ? sourceAddress_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sourceAddress2[i] = this->sourceAddress[i];
    for (size_t i = minSize; i < newSize; i++)
        sourceAddress2[i] = 0;
    delete [] this->sourceAddress;
    this->sourceAddress = sourceAddress2;
    sourceAddress_arraysize = newSize;
}

void MacFrame_Base::setSourceAddress(size_t k, uint16_t sourceAddress)
{
    if (k >= sourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceAddress_arraysize, (unsigned long)k);
    this->sourceAddress[k] = sourceAddress;
}

void MacFrame_Base::insertSourceAddress(size_t k, uint16_t sourceAddress)
{
    if (k > sourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceAddress_arraysize, (unsigned long)k);
    size_t newSize = sourceAddress_arraysize + 1;
    uint16_t *sourceAddress2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceAddress2[i] = this->sourceAddress[i];
    sourceAddress2[k] = sourceAddress;
    for (i = k + 1; i < newSize; i++)
        sourceAddress2[i] = this->sourceAddress[i-1];
    delete [] this->sourceAddress;
    this->sourceAddress = sourceAddress2;
    sourceAddress_arraysize = newSize;
}

void MacFrame_Base::appendSourceAddress(uint16_t sourceAddress)
{
    insertSourceAddress(sourceAddress_arraysize, sourceAddress);
}

void MacFrame_Base::eraseSourceAddress(size_t k)
{
    if (k >= sourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sourceAddress_arraysize, (unsigned long)k);
    size_t newSize = sourceAddress_arraysize - 1;
    uint16_t *sourceAddress2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceAddress2[i] = this->sourceAddress[i];
    for (i = k; i < newSize; i++)
        sourceAddress2[i] = this->sourceAddress[i+1];
    delete [] this->sourceAddress;
    this->sourceAddress = sourceAddress2;
    sourceAddress_arraysize = newSize;
}

size_t MacFrame_Base::getAuxiliarySecurityHeaderArraySize() const
{
    return auxiliarySecurityHeader_arraysize;
}

uint8_t MacFrame_Base::getAuxiliarySecurityHeader(size_t k) const
{
    if (k >= auxiliarySecurityHeader_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)auxiliarySecurityHeader_arraysize, (unsigned long)k);
    return this->auxiliarySecurityHeader[k];
}

void MacFrame_Base::setAuxiliarySecurityHeaderArraySize(size_t newSize)
{
    uint8_t *auxiliarySecurityHeader2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = auxiliarySecurityHeader_arraysize < newSize ? auxiliarySecurityHeader_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        auxiliarySecurityHeader2[i] = this->auxiliarySecurityHeader[i];
    for (size_t i = minSize; i < newSize; i++)
        auxiliarySecurityHeader2[i] = 0;
    delete [] this->auxiliarySecurityHeader;
    this->auxiliarySecurityHeader = auxiliarySecurityHeader2;
    auxiliarySecurityHeader_arraysize = newSize;
}

void MacFrame_Base::setAuxiliarySecurityHeader(size_t k, uint8_t auxiliarySecurityHeader)
{
    if (k >= auxiliarySecurityHeader_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)auxiliarySecurityHeader_arraysize, (unsigned long)k);
    this->auxiliarySecurityHeader[k] = auxiliarySecurityHeader;
}

void MacFrame_Base::insertAuxiliarySecurityHeader(size_t k, uint8_t auxiliarySecurityHeader)
{
    if (k > auxiliarySecurityHeader_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)auxiliarySecurityHeader_arraysize, (unsigned long)k);
    size_t newSize = auxiliarySecurityHeader_arraysize + 1;
    uint8_t *auxiliarySecurityHeader2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        auxiliarySecurityHeader2[i] = this->auxiliarySecurityHeader[i];
    auxiliarySecurityHeader2[k] = auxiliarySecurityHeader;
    for (i = k + 1; i < newSize; i++)
        auxiliarySecurityHeader2[i] = this->auxiliarySecurityHeader[i-1];
    delete [] this->auxiliarySecurityHeader;
    this->auxiliarySecurityHeader = auxiliarySecurityHeader2;
    auxiliarySecurityHeader_arraysize = newSize;
}

void MacFrame_Base::appendAuxiliarySecurityHeader(uint8_t auxiliarySecurityHeader)
{
    insertAuxiliarySecurityHeader(auxiliarySecurityHeader_arraysize, auxiliarySecurityHeader);
}

void MacFrame_Base::eraseAuxiliarySecurityHeader(size_t k)
{
    if (k >= auxiliarySecurityHeader_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)auxiliarySecurityHeader_arraysize, (unsigned long)k);
    size_t newSize = auxiliarySecurityHeader_arraysize - 1;
    uint8_t *auxiliarySecurityHeader2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        auxiliarySecurityHeader2[i] = this->auxiliarySecurityHeader[i];
    for (i = k; i < newSize; i++)
        auxiliarySecurityHeader2[i] = this->auxiliarySecurityHeader[i+1];
    delete [] this->auxiliarySecurityHeader;
    this->auxiliarySecurityHeader = auxiliarySecurityHeader2;
    auxiliarySecurityHeader_arraysize = newSize;
}

size_t MacFrame_Base::getPayloadArraySize() const
{
    return payload_arraysize;
}

uint8_t MacFrame_Base::getPayload(size_t k) const
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    return this->payload[k];
}

void MacFrame_Base::setPayloadArraySize(size_t newSize)
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

void MacFrame_Base::setPayload(size_t k, uint8_t payload)
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    this->payload[k] = payload;
}

void MacFrame_Base::insertPayload(size_t k, uint8_t payload)
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

void MacFrame_Base::appendPayload(uint8_t payload)
{
    insertPayload(payload_arraysize, payload);
}

void MacFrame_Base::erasePayload(size_t k)
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

uint16_t MacFrame_Base::getFcs() const
{
    return this->fcs;
}

void MacFrame_Base::setFcs(uint16_t fcs)
{
    this->fcs = fcs;
}

class MacFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_frameControl,
        FIELD_sequenceNumber,
        FIELD_destinationOWPANId,
        FIELD_destinationAddress,
        FIELD_sourceOWPANId,
        FIELD_sourceAddress,
        FIELD_auxiliarySecurityHeader,
        FIELD_payload,
        FIELD_fcs,
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

MacFrameDescriptor::MacFrameDescriptor() : omnetpp::cClassDescriptor("MacFrame", "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

MacFrameDescriptor::~MacFrameDescriptor()
{
    delete[] propertyNames;
}

bool MacFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacFrame_Base *>(obj)!=nullptr;
}

const char **MacFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacFrameDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "customize")) return "true";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 9+base->getFieldCount() : 9;
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
        FD_ISEDITABLE,    // FIELD_frameControl
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_destinationOWPANId
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_destinationAddress
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_sourceOWPANId
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_sourceAddress
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_auxiliarySecurityHeader
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_payload
        FD_ISEDITABLE,    // FIELD_fcs
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
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
        "frameControl",
        "sequenceNumber",
        "destinationOWPANId",
        "destinationAddress",
        "sourceOWPANId",
        "sourceAddress",
        "auxiliarySecurityHeader",
        "payload",
        "fcs",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int MacFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "frameControl") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "destinationOWPANId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "destinationAddress") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sourceOWPANId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "sourceAddress") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "auxiliarySecurityHeader") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "fcs") == 0) return baseIndex + 8;
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
        "uint16_t",    // FIELD_frameControl
        "uint8_t",    // FIELD_sequenceNumber
        "uint16_t",    // FIELD_destinationOWPANId
        "uint16_t",    // FIELD_destinationAddress
        "uint16_t",    // FIELD_sourceOWPANId
        "uint16_t",    // FIELD_sourceAddress
        "uint8_t",    // FIELD_auxiliarySecurityHeader
        "uint8_t",    // FIELD_payload
        "uint16_t",    // FIELD_fcs
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
    switch (field) {
        case FIELD_destinationOWPANId: return pp->getDestinationOWPANIdArraySize();
        case FIELD_destinationAddress: return pp->getDestinationAddressArraySize();
        case FIELD_sourceOWPANId: return pp->getSourceOWPANIdArraySize();
        case FIELD_sourceAddress: return pp->getSourceAddressArraySize();
        case FIELD_auxiliarySecurityHeader: return pp->getAuxiliarySecurityHeaderArraySize();
        case FIELD_payload: return pp->getPayloadArraySize();
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
    switch (field) {
        case FIELD_destinationOWPANId: pp->setDestinationOWPANIdArraySize(size); break;
        case FIELD_destinationAddress: pp->setDestinationAddressArraySize(size); break;
        case FIELD_sourceOWPANId: pp->setSourceOWPANIdArraySize(size); break;
        case FIELD_sourceAddress: pp->setSourceAddressArraySize(size); break;
        case FIELD_auxiliarySecurityHeader: pp->setAuxiliarySecurityHeaderArraySize(size); break;
        case FIELD_payload: pp->setPayloadArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacFrame_Base'", field);
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
    switch (field) {
        case FIELD_frameControl: return ulong2string(pp->getFrameControl());
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_destinationOWPANId: return ulong2string(pp->getDestinationOWPANId(i));
        case FIELD_destinationAddress: return ulong2string(pp->getDestinationAddress(i));
        case FIELD_sourceOWPANId: return ulong2string(pp->getSourceOWPANId(i));
        case FIELD_sourceAddress: return ulong2string(pp->getSourceAddress(i));
        case FIELD_auxiliarySecurityHeader: return ulong2string(pp->getAuxiliarySecurityHeader(i));
        case FIELD_payload: return ulong2string(pp->getPayload(i));
        case FIELD_fcs: return ulong2string(pp->getFcs());
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
    switch (field) {
        case FIELD_frameControl: pp->setFrameControl(string2ulong(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); break;
        case FIELD_destinationOWPANId: pp->setDestinationOWPANId(i,string2ulong(value)); break;
        case FIELD_destinationAddress: pp->setDestinationAddress(i,string2ulong(value)); break;
        case FIELD_sourceOWPANId: pp->setSourceOWPANId(i,string2ulong(value)); break;
        case FIELD_sourceAddress: pp->setSourceAddress(i,string2ulong(value)); break;
        case FIELD_auxiliarySecurityHeader: pp->setAuxiliarySecurityHeader(i,string2ulong(value)); break;
        case FIELD_payload: pp->setPayload(i,string2ulong(value)); break;
        case FIELD_fcs: pp->setFcs(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacFrame_Base'", field);
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
    switch (field) {
        case FIELD_frameControl: return (omnetpp::intval_t)(pp->getFrameControl());
        case FIELD_sequenceNumber: return (omnetpp::intval_t)(pp->getSequenceNumber());
        case FIELD_destinationOWPANId: return (omnetpp::intval_t)(pp->getDestinationOWPANId(i));
        case FIELD_destinationAddress: return (omnetpp::intval_t)(pp->getDestinationAddress(i));
        case FIELD_sourceOWPANId: return (omnetpp::intval_t)(pp->getSourceOWPANId(i));
        case FIELD_sourceAddress: return (omnetpp::intval_t)(pp->getSourceAddress(i));
        case FIELD_auxiliarySecurityHeader: return (omnetpp::intval_t)(pp->getAuxiliarySecurityHeader(i));
        case FIELD_payload: return (omnetpp::intval_t)(pp->getPayload(i));
        case FIELD_fcs: return (omnetpp::intval_t)(pp->getFcs());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacFrame_Base' as cValue -- field index out of range?", field);
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
    switch (field) {
        case FIELD_frameControl: pp->setFrameControl(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_destinationOWPANId: pp->setDestinationOWPANId(i,omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_destinationAddress: pp->setDestinationAddress(i,omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_sourceOWPANId: pp->setSourceOWPANId(i,omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_sourceAddress: pp->setSourceAddress(i,omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_auxiliarySecurityHeader: pp->setAuxiliarySecurityHeader(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_payload: pp->setPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_fcs: pp->setFcs(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacFrame_Base'", field);
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
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
    MacFrame_Base *pp = omnetpp::fromAnyPtr<MacFrame_Base>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacFrame_Base'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

