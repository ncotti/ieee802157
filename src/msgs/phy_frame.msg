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

//
// TODO generated message class
//
packet PhyFrame {
    
    // Preamble
    uint64_t FLP = 0xaaaaaaaaaaaaaaaa; 	// 64 to 16384 bits
    uint64 TDP;	// 60 bits
    
    // PHY header
    bool burstMode;						// 1 bit
    opticalChannel_t channelNumber;		// 3 bit
    MCS_t MCSId;						// 6 bit
    uint16_t psduLength;				// 16 bit
    bool dimmedOOKExtension;			// 1 bit
    // RESERVED							// 5 bit
    
    // HCS (Header check sequence)
    uint16_t HCS;						// 16 bit CRC
    
    // Optional Fields
        // Present ONLY when transmitting with 200 kHz
        uint8_t tailBits;					// 6 bits
        
        // Present ONLY when dimmedOOKExtension == true
        uint16_t compensationLength;			// 10 bit
        uint8_t resyncLength = 15;				// 4 bit
        uint16_t subframeLength;				// 10 bit
        uint8_t OFCS;							// 8 bit, some kind of CRC
    
    
    
    // PSDU (payload)
    uint8_t payload[];
}
