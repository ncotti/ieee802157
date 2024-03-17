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

message MCPSDataRequest {
  	addressingMode_t srcAddrMode;
  	addressingMode_t dstAddrMode;
  	uint16_t dstOWPANId;
  	uint64_t dstAddr;
  	uint16_t msduLength;
  	uint8_t msdu[];
  	uint8_t msduHandle;
  	uint8_t txOptions;
  	uint8_t securityLevel;
  	MCS_t dataRate;
  	bool burstMode;
  	bool colorReceived;
  	bool colorNotReceived;  
};

message MCPSDataConfirm {
    uint8_t msduHandle;
    macStatus_t status;
    uint32_t timestamp;
};

message MCPSDataIndication {
  	int srcAddrMode;
  	int srcOWPANId;
  	uint64_t srcAddr;
  	int dstAddrMode;
  	int dstOWPANId;
  	uint64_t dstAddr;
  	int msduLength;
  	uint8_t msdu[];
  	int mpduLinkQuality;
  	int DSN;
  	int timestamp;
  	int securityLevel;
  	uint8_t dataRate;
  	bool burstMode;
  	bool colorReceived;
  	bool colorNotReceived;  
};