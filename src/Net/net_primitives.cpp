/*
 * net_primitives.cpp
 *
 *  Created on: Mar 16, 2024
 *      Author: cotti
 */

#include "Net.h"

void mcps_data_request(addressingMode_t srcAddrMode,
        addressingMode_t dstAddrMode, uint16_t dstOWPANId, uint64_t dstAddr,
        uint16_t msduLength, uint8_t* msdu, uint8_t msduHandle, uint8_t txOptions,
        uint8_t securityLevel,
        MCS_t dataRate, bool burstMode,  bool colorReceived, bool colorNotReceived) {
    MCPSDataRequest *msg = new MCPSDataRequest();

    msg->setSrcAddrMode(srcAddrMode);
    msg->setDstAddrMode(dstAddrMode);
    msg->setDstOWPANId(dstOWPANId);
    msg->setDstAddr(dstAddr);
    msg->setMsduLength(msduLength);

    for (uint16_t i = 0; i < msduLength; i++) {
        msg->setMsdu(i, msdu[i]);
    }

    msg->setMsduHandle(msduHandle);
    msg->setTxOptions(txOptions);
    msg->setSecurityLevel(securityLevel);
    msg->setDataRate(dataRate);
    msg->setBurstMode(burstMode);
    msg->setColorReceived(colorReceived);
    msg->setColorNotReceived(colorNotReceived);

    msg->setKind(MCPS_DATA_REQUEST);
    delete msg;
}

void Net::mlme_associate_request(opticalChannel_t logicalChannel,
        addressingMode_t coordAddrMode, uint16_t coordOWPANId,
        uint64_t coordAddress, capabilityInformation_t capabilityInformation,
        uint8_t securityLevel, bool colorAssoc) {
    MLMEAssociateRequest *msg = new MLMEAssociateRequest();

    msg->setLogicalChannel(logicalChannel);
    msg->setCoordAddrMode(coordAddrMode);
    msg->setCoordOWPANId(coordOWPANId);
    msg->setCoordAddress(coordAddress);
    msg->setCapabilityInformation(capabilityInformation);
    msg->setSecurityLevel(securityLevel);
    msg->setColorAssoc(colorAssoc);

    msg->setKind(MLME_ASSOCIATE_REQUEST);
    delete msg;
}

void Net::mlme_disassociate_request(addressingMode_t deviceAddrMode, uint16_t deviceOWPANId,
        uint64_t deviceAddress, uint8_t disassociateReason, bool txIndirect,
        uint8_t securityLevel, bool colorDisAssoc) {
    MLMEDisassociateRequest *msg = new MLMEDisassociateRequest();

    msg->setDeviceAddrMode(deviceAddrMode);
    msg->setDeviceOWPANId(deviceOWPANId);
    msg->setDeviceAddress(deviceAddress);
    msg->setDisassociateReason(disassociateReason);
    msg->setTxIndirect(txIndirect);
    msg->setSecurityLevel(securityLevel);
    msg->setColorDisAssoc(colorDisAssoc);

    msg->setKind(MLME_DISASSOCIATE_REQUEST);
    delete msg;
}

void Net::mlme_get_request(PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex) {
    MLMEGetRequest *msg = new MLMEGetRequest();

    msg->setPIBAttribute(PIBAttribute);
    msg->setPIBAttributeIndex(PIBAttributeIndex);

    msg->setKind(MLME_GET_REQUEST);
    delete msg;
}

void Net::mlme_gts_request(uint8_t GTSCharacteristics, uint8_t securityLevel) {
    MLMEGTSRequest *msg = new MLMEGTSRequest();

    msg->setGTSCharacteristics(GTSCharacteristics);
    msg->setSecurityLevel(securityLevel);

    msg->setKind(MLME_GTS_REQUEST);
    delete msg;
}

void Net::mlme_reset_request(bool setDefaultPIB) {
    MLMEResetRequest *msg = new MLMEResetRequest();

    msg->setSetDefaultPIB(setDefaultPIB);

    msg->setKind(MLME_RESET_REQUEST);
    delete msg;
}

void Net::mlme_rx_enable_request(bool deferPermit, uint32_t rxOnTime, uint32_t rxOnDuration) {
    MLMERxEnableRequest *msg = new MLMERxEnableRequest();

    msg->setDeferPermit(deferPermit);
    msg->setRxOnTime(rxOnTime);
    msg->setRxOnDuration(rxOnDuration);

    msg->setKind(MLME_RX_ENABLE_REQUEST);
    delete msg;
}

void Net::mlme_scan_request(scanType_t scanType, uint8_t scanChannels, uint8_t scanDuration,
        uint8_t securityLevel, bool colorScan) {
    MLMEScanRequest *msg = new MLMEScanRequest();

    msg->setScanType(scanType);
    msg->setScanChannels(scanChannels);
    msg->setScanDuration(scanDuration);
    msg->setSecurityLevel(securityLevel);
    msg->setColorScan(colorScan);

    msg->setKind(MLME_SCAN_REQUEST);
    delete msg;
}

void Net::mlme_set_request(PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex, uint64_t PIBAttributeValue) {
    MLMESetRequest *msg = new MLMESetRequest();

    msg->setPIBAttribute(PIBAttribute);
    msg->setPIBAttributeIndex(PIBAttributeIndex);
    msg->setPIBAttributeValue(PIBAttributeValue);

    msg->setKind(MLME_SET_REQUEST);
    delete msg;
}

void Net::mlme_start_request(uint16_t OWPANId, opticalChannel_t logicalChannel,
        uint32_t startTime, uint8_t beaconOrder, uint8_t superframeOrder,
        bool OWPANCoordinator, bool coordRealignment, uint8_t coordRealingmentSecurityLevel,
        uint8_t beaconSecurityLevel) {
    MLMEStartRequest *msg = new MLMEStartRequest();

    msg->setOWPANId(OWPANId);
    msg->setLogicalChannel(logicalChannel);
    msg->setStartTime(startTime);
    msg->setBeaconOrder(beaconOrder);
    msg->setSuperframeOrder(superframeOrder);
    msg->setOWPANCoordinator(OWPANCoordinator);
    msg->setCoordRealignment(coordRealignment);
    msg->setCoordRealingmentSecurityLevel(coordRealingmentSecurityLevel);
    msg->setCoordBeaconSecurityLevel(beaconSecurityLevel);

    msg->setKind(MLME_START_REQUEST);
    delete msg;
}

void Net::mlme_sync_request(opticalChannel_t logicalChannel, bool trackBeacon) {
    MLMESyncRequest *msg = new MLMESyncRequest();

    msg->setLogicalChannel(logicalChannel);
    msg->setTrackBeacon(trackBeacon);

    msg->setKind(MLME_SYNC_REQUEST);
    delete msg;
}

void Net::mlme_poll_request(addressingMode_t coordAddrMode, uint16_t coordOWPANId,
        uint64_t coordAddress, uint8_t securityLevel) {
    MLMEPollRequest *msg = new MLMEPollRequest();

    msg->setCoordAddrMode(coordAddrMode);
    msg->setCoordOWPANId(coordOWPANId);
    msg->setCoordAddress(coordAddress);
    msg->setSecurityLevel(securityLevel);

    msg->setKind(MLME_POLL_REQUEST);
    delete msg;
}

