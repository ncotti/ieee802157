/*
 * phy_primitives.cpp
 *
 *  Created on: Mar 14, 2024
 *      Author: cotti
 */

#include "phy.h"

void Phy::plme_cca_request(PLMECCARequest* msg) {
    PLMECCAConfirm *xMsg = new PLMECCAConfirm();

    if (this->trxState == phyStatus_t::TRX_OFF || this->trxState == phyStatus_t::TX_ON) {
        xMsg->setStatus(this->trxState);
    } else {
        if (this->phyCCAMode & 0b1) {
            // Energy above threshold
        } else if (this->phyCCAMode & 0b10) {
            // Carrier sense
        } else {
            // Carrier sense with energy above threshold
        }

        xMsg->setStatus(this->CCA);
    }

    this->plme_cca_confirm(xMsg);
    delete xMsg;
}

void Phy::plme_cca_confirm(PLMECCAConfirm* msg) {
    msg->setKind(PLME_CCA_CONFIRM);
    send(msg, "confirmOut");
}

void Phy::plme_get_request(PLMEGetRequest* msg) {
    phyStatus_t status = phyStatus_t::SUCCESS_PHY;
    uint64_t value = 0;

    switch (msg->getPIBAttribute()) {
        case PIBAttribute_t::PHY_CURRENT_CHANNEL: {
            value = this->phyCurrentChannel;
            break;
        }
        case PIBAttribute_t::PHY_CCA_MODE: {
            value = this->phyCCAMode;
            break;
        }
        case PIBAttribute_t::PHY_DIM: {
            value = this->phyDim;
            break;
        }
        case PIBAttribute_t::PHY_USE_EXTENDED_MODE: {
            value = this->phyUseExtendedMode;
            break;
        }
        case PIBAttribute_t::PHY_COLOR_FUNCTION: {
            //value = this->phyColorFunction;
            // TODO matrix value
            break;
        }
        case PIBAttribute_t::PHY_BLINKING_NOTIFICATION_FREQUENCY: {
            value = this->phyBlinkingNotificationFrequency;
            break;
        }
        case PIBAttribute_t::PHY_OCC_ENABLE: {
            value = this->phyOccEnable;
            break;
        }
        case PIBAttribute_t::PHY_OCC_MCS_ID: {
            value = this->phyOccMcsID;
            break;
        }
        case PIBAttribute_t::PHY_PSDU_LENGTH: {
            value = this->phyPSDULength;
            break;
        }
        default: {
            status = phyStatus_t::UNSUPPORTED_ATTRIBUTE;
            break;
        }
    }

    this->plme_get_confirm(status, msg->getPIBAttribute(), value);
}

void Phy::plme_get_confirm(phyStatus_t status, PIBAttribute_t PIBAttribute, uint64_t PIBAttributeValue) {
    PLMEGetConfirm *msg = new PLMEGetConfirm();

    msg->setStatus(status);
    msg->setPIBAttribute(PIBAttribute);
    msg->setPIBAttributeValue(PIBAttributeValue);

    msg->setKind(PLME_GET_CONFIRM);
    send(msg, "confirmOut");
}

void Phy::plme_set_request(PLMESetRequest* msg) {
    PLMESetConfirm *xMsg = new PLMESetConfirm();

    xMsg->setStatus(phyStatus_t::SUCCESS_PHY);
    xMsg->setPIBAttribute(msg->getPIBAttribute());

    switch (msg->getPIBAttribute()) {
        case PIBAttribute_t::PHY_CURRENT_CHANNEL: {
            if (msg->getPIBAttributeValue() >= 0 && msg->getPIBAttributeValue() <= 7) {
                this->phyCurrentChannel = (opticalChannel_t) msg->getPIBAttributeValue();
            } else {
                xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
            }
            break;
        }

        case PIBAttribute_t::PHY_CCA_MODE: {
            this->phyCCAMode = (uint8_t) msg->getPIBAttributeValue();
            break;
        }

        case PIBAttribute_t::PHY_DIM: {
            if (msg->getPIBAttributeValue() >= 0 && msg->getPIBAttributeValue() <= 1000) {
                this->phyDim = msg->getPIBAttributeValue();
            } else {
                xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
            }
            break;
        }

        case PIBAttribute_t::PHY_USE_EXTENDED_MODE: {
            if (msg->getPIBAttributeValue() >= 0 && msg->getPIBAttributeValue() <= 1) {
                this->phyUseExtendedMode = msg->getPIBAttributeValue();
            } else {
                xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
            }
            break;
        }

        case PIBAttribute_t::PHY_COLOR_FUNCTION: {
            // TODO matrix
//                if (msg->getPIBAttributeValue(0) >= 0 && msg->getPIBAttributeValue(0) <= 7) {
//                    this->phyCurrentChannel = msg->getPIBAttributeValue(0);
//                } else {
//                    xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
//                }
            break;
        }

        case PIBAttribute_t::PHY_BLINKING_NOTIFICATION_FREQUENCY: {
            if (msg->getPIBAttributeValue() >= 0 && msg->getPIBAttributeValue() <= 10) {
                this->phyBlinkingNotificationFrequency = msg->getPIBAttributeValue();
            } else {
                xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
            }
            break;
        }

        case PIBAttribute_t::PHY_OCC_ENABLE: {
            if (msg->getPIBAttributeValue() >= 0 && msg->getPIBAttributeValue() <= 1) {
                this->phyOccEnable = msg->getPIBAttributeValue();
            } else {
                xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
            }
            break;
        }

        case PIBAttribute_t::PHY_OCC_MCS_ID: {
            if (msg->getPIBAttributeValue() >= 0 && msg->getPIBAttributeValue() <= 15) {
                this->phyOccMcsID = msg->getPIBAttributeValue();
            } else {
                xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
            }
            break;
        }

        case PIBAttribute_t::PHY_PSDU_LENGTH: {
            if (msg->getPIBAttributeValue() >= 0 && msg->getPIBAttributeValue() <= 0xffff) {
                this->phyPSDULength = msg->getPIBAttributeValue();
            } else {
                xMsg->setStatus(phyStatus_t::INVALID_PARAMETER_PHY);
            }
            break;
        }

        default: {
            xMsg->setStatus(phyStatus_t::UNSUPPORTED_ATTRIBUTE);
           break;
        }
    }

    this->plme_set_confirm(xMsg);
    delete xMsg;
}

void Phy::plme_set_confirm(PLMESetConfirm* msg) {
    msg->setKind(PLME_SET_CONFIRM);
    send(msg, "confirmOut");
}

void Phy::plme_set_trx_state_request(PLMESetTrxStateRequest* msg) {
    phyStatus_t futureState = msg->getState();
    phyStatus_t msgState;

    if (futureState == this->trxState) {
        msgState = futureState;

    } else if ((futureState == phyStatus_t::RX_ON || futureState == phyStatus_t::TRX_OFF) && this->isBusyTx) {
        msgState = phyStatus_t::BUSY_TX;
        this->notificationChangeTrx = true;
        this->futureTrxState = futureState;

    } else if ((futureState == phyStatus_t::TX_ON || futureState == phyStatus_t::TRX_OFF) && this->isBusyRx) {
        msgState = phyStatus_t::BUSY_RX;
        this->notificationChangeTrx = true;
        this->futureTrxState = futureState;

    } else if (futureState == phyStatus_t::FORCE_TRX_OFF) {
        msgState = phyStatus_t::SUCCESS_PHY;
        this->trxState = phyStatus_t::TRX_OFF;

    } else {
        msgState = phyStatus_t::SUCCESS_PHY;
    }

    this->plme_set_trx_state_confirm(msgState);
}

void Phy::plme_set_trx_state_confirm(phyStatus_t status) {
    PLMESetTrxStateConfirm *msg = new PLMESetTrxStateConfirm();

    msg->setStatus(status);

    msg->setKind(PLME_SET_TRX_STATE_CONFIRM);
    send(msg, "confirmOut");
}

void Phy::plme_switch_request(PLMESwitchRequest* msg) {
    // TODO used by the DME
}

void Phy::plme_switch_confirm(PLMESwitchConfirm* msg) {
    // TODO used by the DME
}

void Phy::pd_data_request(PDDataRequest* msg) {
    PDDataConfirm* xMsg = new PDDataConfirm();
    if (this->trxState == phyStatus_t::RX_ON || this->trxState == phyStatus_t::TRX_OFF) {
        xMsg->setStatus(this->trxState);
    } else {
        // TODO transmit data
        xMsg->setStatus(phyStatus_t::SUCCESS_PHY);
    }
}

void Phy::pd_data_confirm(PDDataConfirm* msg) {
    msg->setKind(PD_DATA_CONFIRM);
    send(msg, "confirmOut");
}

void Phy::pd_data_indication(PDDataIndication* msg) {

}
