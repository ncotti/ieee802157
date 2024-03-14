/*
 * phy.cpp
 *
 *  Created on: Mar 2, 2024
 *      Author: cotti
 */

#include "phy.h"
#include <omnetpp.h>

using namespace omnetpp;

Define_Module(Phy);

void Phy::initialize() {

}

void Phy::handleMessage(cMessage *msg) {
//    EV << "Received message " << msg->getName() << " , sending it out again\n";
//    send(msg, "indicationOut"); // send out the message
    if (msg->arrivedOn("requestIn")) {
        this->processMsgFromHigherLayer(msg);
    }

}

void Phy::processMsgFromHigherLayer(cMessage* msg) {
    switch (msg->getKind()) {
        case PD_DATA_REQUEST: {
            PDDataRequest *xMsg = check_and_cast<PDDataRequest *>(msg);
            this->pd_data_request(xMsg);
            delete xMsg;
            break;
        }

        case PLME_CCA_REQUEST: {
            PLMECCARequest *xMsg = check_and_cast<PLMECCARequest *>(msg);
            this->plme_cca_request(xMsg);
            delete xMsg;
            break;
        }

        case PLME_GET_REQUEST: {
            PLMEGetRequest *xMsg = check_and_cast<PLMEGetRequest *>(msg);
            this->plme_get_request(xMsg);
            delete xMsg;
            break;
        }

        case PLME_SET_REQUEST: {
            PLMESetRequest *xMsg = check_and_cast<PLMESetRequest *>(msg);
            this->plme_set_request(xMsg);
            delete xMsg;
            break;
        }

        case PLME_SET_TRX_STATE_REQUEST: {
            PLMESetTrxStateRequest *xMsg = check_and_cast<PLMESetTrxStateRequest *>(msg);
            this->plme_set_trx_state_request(xMsg);
            delete xMsg;
            break;
        }

        case PLME_SWITCH_REQUEST: {
            PLMESwitchRequest *xMsg = check_and_cast<PLMESwitchRequest *>(msg);
            this->plme_switch_request(xMsg);
            delete xMsg;
            break;
        }
    }
}

void Phy::transmitToChannel(uint8_t* payload, size_t payloadLength) {
    // Add FLP
    uint64_t FLP = 0xaaaaaaaaaaaaaaaa;
    uint64_t TDP;

    if (this->varTopology == 1) {
        TDP = (TDP_VISIBILITY_P1) | ((~TDP_VISIBILITY_P1) << 15) | (TDP_VISIBILITY_P1 << 30) | ((~TDP_VISIBILITY_P1) << 45);
    } else if (this->varTopology == 2) {
        TDP = (TDP_PEER_TO_PEER_P2) | ((~TDP_PEER_TO_PEER_P2) << 15) | (TDP_PEER_TO_PEER_P2 << 30) | ((~TDP_PEER_TO_PEER_P2) << 45);
    } else if (this->varTopology == 3) {
        TDP = (TDP_STAR_P3) | ((~TDP_STAR_P3) << 15) | (TDP_STAR_P3 << 30) | ((~TDP_STAR_P3) << 45);
    } else if (this->varTopology == 4) {
        TDP = (TDP_BROADCAST_P4) | ((~TDP_BROADCAST_P4) << 15) | (TDP_BROADCAST_P4 << 30) | ((~TDP_BROADCAST_P4) << 45);
    }

    uint32_t phyHeader;
    // phyHeader |= burstMode << 0;
    phyHeader |= this->phyCurrentChannel << 1;
    phyHeader |= this->varMCS << 4;
    phyHeader |= this->phyPSDULength << 10;
    //phyHeader |= dimmed ook extension << 26;

}






