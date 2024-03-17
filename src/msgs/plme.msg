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

message PLMECCARequest {
    // No parameters
};

message PLMECCAConfirm {
    phyStatus_t status;
};


message PLMEGetRequest {
    PIBAttribute_t PIBAttribute;
};

message PLMEGetConfirm {
    phyStatus_t status;
    uint8_t PIBAttribute;
    uint64_t PIBAttributeValue;
};


message PLMESetRequest {
    PIBAttribute_t PIBAttribute;
    uint64_t PIBAttributeValue;
};

message PLMESetConfirm {
    phyStatus_t status;
    PIBAttribute_t PIBAttribute;
};

message PLMESetTrxStateRequest {
    phyStatus_t state;
};

message PLMESetTrxStateConfirm {
    phyStatus_t status;
};


message PLMESwitchRequest {
    bool SWBitMap;
    bool dir;
};

message PLMESwitchConfirm {
    phyStatus_t status;
};