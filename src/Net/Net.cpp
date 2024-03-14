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
        case MLME_ASSOCIATE_CONFIRM: {
            MLMEAssociateConfirm *xMsg = check_and_cast<MLMEAssociateConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_DISASSOCIATE_CONFIRM: {
            MLMEDisassociateConfirm *xMsg = check_and_cast<MLMEDisassociateConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_GET_CONFIRM: {
            MLMEGetConfirm *xMsg = check_and_cast<MLMEGetConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_GTS_CONFIRM: {
            MLMEGTSConfirm *xMsg = check_and_cast<MLMEGTSConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_RESET_CONFIRM: {
            MLMEResetConfirm *xMsg = check_and_cast<MLMEResetConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_RX_ENABLE_CONFIRM: {
            MLMERxEnableConfirm *xMsg = check_and_cast<MLMERxEnableConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_SCAN_CONFIRM: {
            MLMEScanConfirm *xMsg = check_and_cast<MLMEScanConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_SET_CONFIRM: {
            MLMESetConfirm *xMsg = check_and_cast<MLMESetConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_START_CONFIRM: {
            MLMEStartConfirm *xMsg = check_and_cast<MLMEStartConfirm *>(msg);

            delete xMsg;
            break;
        }

        case MLME_POLL_CONFIRM: {
            MLMEPollConfirm *xMsg = check_and_cast<MLMEPollConfirm *>(msg);

            delete xMsg;
            break;
        }
    }
}



