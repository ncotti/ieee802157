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

message MLMEAssociateRequest {
    int logicalChannel;
    int coordAddrMode;
    int coordOWPANId;
    int coordAddress;
    uint64_t capabilityInformation;
    int securityLevel;
    bool colorAssoc;
};

message MLMEAssociateConfirm {
    int assoShortAddress;
    uint8_t status;
    int capabilityNegotationResponse;
    int securityLevel;
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
    int deviceAddrMode;
    int deviceOWPANId;
    uint64_t deviceAddress;
    int disassociateReason;
    bool txIndirect;
    int securityLevel;
    bool colorDisAssoc;
};

message MLMEDisassociateConfirm {
    uint8_t status;
    int deviceAddrMode;
    int deviceOWPANId;
    uint64_t deviceAddress;
};

message MLMEDisassociateIndication {
    uint64_t deviceAddress;
    int disassociateReason;
    int securityLevel;
};



message MLMEGetRequest {
    int PIBAttribute;
    int PIBAttributeIndex;
};

message MLMEGetConfirm {
    uint8_t status;
    int PIBAttribute;
    int PIBAttributeIndex;
    int PIBAttributeValue;
};



message MLMEGTSRequest {
    uint8_t GTSCharacteristics;
    int securityLevel;
};

message MLMEGTSConfirm {
    uint8_t GTSCharacteristics;
    uint8_t status;
};

message MLMEGTSIndication {
    uint16_t deviceAddress;
    uint8_t GTSCharacteristics;
    int securityLevel;
};



message MLMEPollRequest {
    int coordAddrMode;
    int coordOWPANId;
    uint64_t coordAddress;
    int securityLevel;
};

message MLMEPollConfirm {
    uint8_t status;
};



message MLMEResetRequest {
	bool setDefaultPIB;   
};

message MLMEResetConfirm {
    uint8_t status;
};



message MLMERxEnableRequest {
    bool deferPermit;
    int rxOnTime;
    int rxOnDuration;
};

message MLMERxEnableConfirm {
    uint8_t status;
};



message MLMEScanRequest {
    int scanType;
    uint8_t scanChannels;
    int scanDuration;
    int securityLevel;
    bool colorScan;
};

message MLMEScanConfirm {
    uint8_t status;
    int scanType;
    uint8_t unscannedChannels;
    int resultListSize;
    uint8_t OWPANDescriptorList;
};



message MLMESetRequest {
    int PIBAttribute;
    int PIBAttributeIndex;
    uint64_t PIBAttributeValue;
};

message MLMESetConfirm {
    uint8_t status;
    int PIBAttribute;
    int PIBAttributeIndex;
};



message MLMEStartRequest {
    int OWPANId;
    int logicalChannel;
    int startTime;
    int beaconOrder;
    int superframeOrder;
    bool OWPANCoordinator;
    bool coordRealignment;
    int coordRealingmentSecurityLevel;
    int beaconSecurityLevel;
};

message MLMEStartConfirm {
    uint8_t status;
};



message MLMESyncRequest {
	int logicalChannel;
	bool trackBeacon;
};



message MLMESyncLossIndication{
    uint8_t lossReason;
    int OWPANId;
    int logicalChannel;
    int securityLevel;
};
