//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

import types;

message MLMEAssociateRequest {
    opticalChannel_t logicalChannel;
    addressingMode_t coordAddrMode;
    uint16_t coordOWPANId;
    uint64_t coordAddress;
    capabilityInformation_t capabilityInformation;
    uint8_t securityLevel;
    bool colorAssoc;
};

message MLMEAssociateConfirm {
    uint16_t assocShortAddress;
    macStatus_t status;
    colorStabilizationScheme_t capabilityNegotiationResponse;
    uint8_t securityLevel;
};

message MLMEAssociateResponse {
    uint64_t deviceAddress;
    int assocShortAddress;
    uint8_t status;
    int capabilityNegotationResponse;
    int securityLevel;
};

message MLMEAssociateIndication {
    uint64_t deviceAddress;
    uint64_t capabilityInformation;
    int securityLevel;
};



message MLMEBeaconNotifyIndication {
    int BSN;
    uint8_t OWPANDescriptor;
    uint8_t pendAddrSpec;
    uint8_t addrList[];
    int sduLength;
    uint8_t sdu[];
};



message MLMECommStatusIndication {
    int OWPANId;
    int srcAddrMode;
    uint64_t srcAddr;
    int dstAddrMode;
    uint64_t dstAddr;
    uint8_t status;
    int securityLevel;
};



message MLMEDisassociateRequest {
    addressingMode_t deviceAddrMode;
    uint16_t deviceOWPANId;
    uint64_t deviceAddress;
    uint8_t disassociateReason;
    bool txIndirect;
    uint8_t securityLevel;
    bool colorDisAssoc;
};

message MLMEDisassociateConfirm {
    macStatus_t status;
    addressingMode_t deviceAddrMode;
    uint16_t deviceOWPANId;
    uint64_t deviceAddress;
};

message MLMEDisassociateIndication {
    uint64_t deviceAddress;
    int disassociateReason;
    int securityLevel;
};



message MLMEGetRequest {
    PIBAttribute_t PIBAttribute;
    uint8_t PIBAttributeIndex;
};

message MLMEGetConfirm {
    macStatus_t status;
    PIBAttribute_t PIBAttribute;
    uint8_t PIBAttributeIndex;
    uint64_t PIBAttributeValue;
};



message MLMEGTSRequest {
    uint8_t GTSCharacteristics;
    uint8_t securityLevel;
};

message MLMEGTSConfirm {
    uint8_t GTSCharacteristics;
    macStatus_t status;
};

message MLMEGTSIndication {
    uint16_t deviceAddress;
    uint8_t GTSCharacteristics;
    int securityLevel;
};



message MLMEPollRequest {
    addressingMode_t coordAddrMode;
    uint16_t coordOWPANId;
    uint64_t coordAddress;
    uint8_t securityLevel;
};

message MLMEPollConfirm {
    macStatus_t status;
};



message MLMEResetRequest {
	bool setDefaultPIB;   
};

message MLMEResetConfirm {
    macStatus_t status;
};



message MLMERxEnableRequest {
    bool deferPermit;
    uint32_t rxOnTime;
    uint32_t rxOnDuration;
};

message MLMERxEnableConfirm {
    macStatus_t status;
};



message MLMEScanRequest {
    scanType_t scanType;
    uint8_t scanChannels;
    uint8_t scanDuration;
    uint8_t securityLevel;
    bool colorScan;
};

message MLMEScanConfirm {
    macStatus_t status;
    int scanType;
    uint8_t unscannedChannels;
    uint16_t resultListSize;
    uint8_t OWPANDescriptorList[];
};



message MLMESetRequest {
    PIBAttribute_t PIBAttribute;
    uint8_t PIBAttributeIndex;
    uint64_t PIBAttributeValue;
};

message MLMESetConfirm {
    macStatus_t status;
    PIBAttribute_t PIBAttribute;
    uint8_t PIBAttributeIndex;
};



message MLMEStartRequest {
    uint16_t OWPANId;
    opticalChannel_t logicalChannel;
    uint32_t startTime;
    uint8_t beaconOrder;
    uint8_t superframeOrder;
    bool OWPANCoordinator;
    bool coordRealignment;
    uint8_t coordRealingmentSecurityLevel;
    uint8_t coordBeaconSecurityLevel;
};

message MLMEStartConfirm {
    macStatus_t status;
};



message MLMESyncRequest {
	opticalChannel_t logicalChannel;
	bool trackBeacon;
};



message MLMESyncLossIndication{
    uint8_t lossReason;
    int OWPANId;
    int logicalChannel;
    int securityLevel;
};
