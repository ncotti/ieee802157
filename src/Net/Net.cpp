/*
 * Net.cpp
 *
 *  Created on: Mar 6, 2024
 *      Author: cotti
 */

#include "Net.h"

Define_Module(Net);

void Net::initialize() {
    if (par("sendMsgOnInit").boolValue()) {
        MLMEScanRequest *msg = new MLMEScanRequest("Scan request", MLME_SCAN_REQUEST);
        EV << "Sending initial message\n";
        send(msg, "requestOut");
    }
}

void Net::handleMessage(cMessage *msg) {
    if (msg->arrivedOn("ConfirmIn")) {
        this->processMsgFromLowerLayer(msg);
    }

}

void Net::processMsgFromLowerLayer(cMessage* msg) {
    switch (msg->getKind()) {
        case MCPS_DATA_CONFIRM: {
            mcps_data_confirm(msg);
            break;
        }
        case MLME_ASSOCIATE_CONFIRM: {
            mlme_associate_confirm(msg);
            break;
        }

        case MLME_DISASSOCIATE_CONFIRM: {
            mlme_disassociate_confirm(msg);
            break;
        }

        case MLME_GET_CONFIRM: {
            mlme_get_confirm(msg);
            break;
        }

        case MLME_GTS_CONFIRM: {
            mlme_gts_confirm(msg);
            break;
        }

        case MLME_RESET_CONFIRM: {
            mlme_reset_confirm(msg);
            break;
        }

        case MLME_RX_ENABLE_CONFIRM: {
            mlme_rx_enable_confirm(msg);
            break;
        }

        case MLME_SCAN_CONFIRM: {
            mlme_scan_confirm(msg);
            break;
        }

        case MLME_SET_CONFIRM: {
            mlme_set_confirm(msg);
            break;
        }

        case MLME_START_CONFIRM: {
            mlme_start_confirm(msg);
            break;
        }

        case MLME_POLL_CONFIRM: {
            mlme_poll_confirm(msg);
            break;
        }
    }
}



