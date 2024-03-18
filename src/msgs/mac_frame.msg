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

packet MacFrame {
    // Frame control
    uint8_t frameVersion = 1;	// IEEE 802.15.7 - 2018 compatible
    frameType_t frameType;
    bool securityEnable = 0;
    bool framePending;
    bool acknoledgementRequest;
    addressingMode_t destinationAddressingMode;
    addressingMode_t sourceAddressingMode;
    
    uint8_t sequenceNumber;
    
    // Addressing fields. Some of these are not mandatory, depending on the
    // addressing modes and frame type.
    uint16_t destinationOWPANIdentifier;
    uint64_t destinationAddress;
    uint16_t sourceOWPANIdentifier;
    uint64_t sourceAddress;
    
    // There'll never be a security header, by design.
    
    // Forward Error correction (FCS = Forward error correction)
    uint16_t FCS;
};

struct GTSList_t {
    uint16_t deviceShortAddress;
    uint8_t GTSStartingSlot;
    uint8_t GTSLength;
};

packet MacBeaconFrame extends MacFrame {
    // Superframe specification field
    uint8_t beaconOrder;		// -> macBeaconOrder
    uint8_t superframeOrder;	// -> macSuperframeOrder
    uint8_t finalCAPSlot;		// How many slots are used for CAP from the aNumSuperframeSlots (16).
    bool OWPANCoordinator;		// "true" if being transmitted by the coordinator
    bool associationPermit;		// Related to macAssociationPermit
    bool cellSearchEn;
    
    // GTS fields
    	// GTSSpecification
    	uint8_t GTSDescriptorCount;
    	bool GTSPermit;
    uint8_t GTSDirections;
    GTSList_t GTSList[];
    
    // Pending address fields
    	// Pending address specification
    	uint8_t numberOfShortAddressesPending;
    	uint8_t numberOfExtendedAddressesPending;
    uint64_t addressList[];
    
    uint8_t beaconPayload[];	// Related to macBeaconPayload
    
};


packet MacDataFrame extends MacFrame {
    // MSDU field
    dataType_t msduType;
    uint8_t numberOfPPDUs;
    uint8_t dataPayload[];
};

packet MacAckFrame extends MacFrame {
    uint16_t bufferSize;
    uint8_t frameCount;
    uint16_t sequenceControl;
    uint16_t frameBitmap;
};

packet MacCommandFrame extends MacFrame {
	commandFrameIdentifier_t commandFrameIdentifier;
	uint8_t commandPayload[];
};
