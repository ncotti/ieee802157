/*
 * phy_primitives.cpp
 *
 *  Created on: Mar 14, 2024
 *      Author: cotti
 */

#include "phy.h"

void Phy::plme_cca_request(PLMECCARequest* msg) {
    PLMECCAConfirm *xMsg = new PLMECCAConfirm();

    if (this->varTrxState == phyStatus_t::TRX_OFF || this->varTrxState == phyStatus_t::TX_ON) {
        xMsg->setStatus(this->varTrxState);
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
    PLMEGetConfirm *xMsg = new PLMEGetConfirm();

    xMsg->setStatus(phyStatus_t::SUCCESS_PHY);

    switch (msg->getPIBAttribute()) {
        case PIBAttribute_t::PHY_CURRENT_CHANNEL: {
            xMsg->setPIBAttributeValue(this->phyCurrentChannel);
            break;
        }
        case PIBAttribute_t::PHY_CCA_MODE: {
            xMsg->setPIBAttributeValue(this->phyCCAMode);
            break;
        }
        case PIBAttribute_t::PHY_DIM: {
            xMsg->setPIBAttributeValue(this->phyDim);
            break;
        }
        case PIBAttribute_t::PHY_USE_EXTENDED_MODE: {
            xMsg->setPIBAttributeValue(this->phyUseExtendedMode);
            break;
        }
        case PIBAttribute_t::PHY_COLOR_FUNCTION: {
            xMsg->setPIBAttributeValue(this->phyColorFunction);
            break;
        }
        case PIBAttribute_t::PHY_BLINKING_NOTIFICATION_FREQUENCY: {
            xMsg->setPIBAttributeValue(this->phyBlinkingNotificationFrequency);
            break;
        }
        case PIBAttribute_t::PHY_OCC_ENABLE: {
            xMsg->setPIBAttributeValue(this->phyOccEnable);
            break;
        }
        case PIBAttribute_t::PHY_OCC_MCS_ID: {
            xMsg->setPIBAttributeValue(this->phyOccMcsID);
            break;
        }
        case PIBAttribute_t::PHY_PSDU_LENGTH: {
            xMsg->setPIBAttributeValue(this->phyPSDULength);
            break;
        }
        default: {
            xMsg->setStatus(phyStatus_t::UNSUPPORTED_ATTRIBUTE);
            break;
        }
    }

    this->plme_get_confirm(xMsg);
    delete xMsg;
}

void Phy::plme_get_confirm(PLMEGetConfirm* msg) {
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

    PLMESetTrxStateConfirm *xMsg = new PLMESetTrxStateConfirm();

    if (msg->getState() == this->varTrxState) {
        xMsg->setStatus(this->varTrxState);
    } else if ((msg->getState() == phyStatus_t::RX_ON || msg->getState() == phyStatus_t::TRX_OFF) && this->isBusyTx) {
        xMsg->setStatus(phyStatus_t::BUSY_TX);
        this->varTrxState = (phyStatus_t) msg->getState();    // TODO defer until end of transmision
    } else if ((msg->getState() == phyStatus_t::TX_ON || msg->getState() == phyStatus_t::TRX_OFF) && this->isBusyRx) {
        xMsg->setStatus(phyStatus_t::BUSY_RX);
        this->varTrxState = (phyStatus_t) msg->getState();  // TODO defer until end of transmision
    } else if (msg->getState() == phyStatus_t::FORCE_TRX_OFF) {
        xMsg->setStatus(phyStatus_t::SUCCESS_PHY);
        this->varTrxState = (phyStatus_t) msg->getState(); // Immeadiate
    } else {
        xMsg->setStatus(phyStatus_t::SUCCESS_PHY);
    }

    this->plme_set_trx_state_confirm(xMsg);
    delete xMsg;
}

void Phy::plme_set_trx_state_confirm(PLMESetTrxStateConfirm* msg) {
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
    if (this->varTrxState == phyStatus_t::RX_ON || this->varTrxState == phyStatus_t::TRX_OFF) {
        xMsg->setStatus(this->varTrxState);
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
