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

message PLMECCARequest {
    // No parameters
};

message PLMECCAConfirm {
    uint8_t status;
};



message PLMEGetRequest {
    uint8_t PIBAttribute;
};

message PLMEGetConfirm {
    uint8_t status;
    uint8_t PIBAttribute;
    int PIBAttributeValue[];
};


message PLMESetRequest {
    uint8_t PIBAttribute;
    int PIBAttributeValue[];
};

message PLMESetConfirm {
    uint8_t status;
    uint8_t PIBAttribute;
};



message PLMESetTrxStateRequest {
    uint8_t state;
};

message PLMESetTrxStateConfirm {
    uint8_t status;
};


message PLMESwitchRequest {
    bool SWBitMap;
    bool dir;
};

message PLMESwitchConfirm {
    uint8_t status;
};