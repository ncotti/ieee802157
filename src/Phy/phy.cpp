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
    EV << "Received message " << msg->getName() << " , sending it out again\n";
    send(msg, "indicationOut"); // send out the message
}

void Phy::plme_cca_request() {

}

void Phy::plme_cca_confirm(phyStatus_t status) {

}

void Phy::plme_get_request(uint8_t PIBAttribute) {

}

void Phy::plme_get_confirm(phyStatus_t status, uint8_t PIBAttribute,
        uint64_t PIBAttributeValue) {

}

void Phy::plme_set_request(phyPIBAtrribute_t PIBAttribute, uint64_t PIBAttributeValue) {

}

void Phy::plme_set_confirm(phyStatus_t status, phyPIBAtrribute_t PIBAttribute) {

}

void Phy::plme_set_trx_state_request(phyStatus_t state) {

    if (state == this->phyStatus) {
        this->plme_set_trx_state_confirm(state);
    }

    switch(state) {
        case phyStatus_t::RX_ON: {
            if(this->isBusyTx) {
                this->plme_set_trx_state_confirm(phyStatus_t::BUSY_TX);
                // wait until not busy
                this->phyStatus = state;
            } else {
                this->plme_set_trx_state_confirm(phyStatus_t::SUCCESS_PHY);
            }
            break;
        }

        case phyStatus_t::TRX_OFF: {
            if(this->isBusyTx) {
                this->plme_set_trx_state_confirm(phyStatus_t::BUSY_TX);
                // wait until not busy
                this->phyStatus = state;
            } else if(this->phyStatus == phyStatus_t::RX_ON && this->isBusyRx) {
                this->plme_set_trx_state_confirm(phyStatus_t::BUSY_RX);
                // wait until not busy
                this->phyStatus = state;
            } else {
                this->plme_set_trx_state_confirm(phyStatus_t::SUCCESS_PHY);
            }


            break;
        }

        case phyStatus_t::FORCE_TRX_OFF: {
            // maybe some abort RX or TX
            this->phyStatus = phyStatus_t::TRX_OFF;
            this->plme_set_trx_state_confirm(phyStatus_t::SUCCESS_PHY);
            break;
        }

        case phyStatus_t::TX_ON: {
            if(this->phyStatus == phyStatus_t::RX_ON && this->isBusyRx) {
                this->plme_set_trx_state_confirm(phyStatus_t::BUSY_RX);
                // wait until not busy
                this->phyStatus = state;
            } else {
                this->plme_set_trx_state_confirm(phyStatus_t::SUCCESS_PHY);
            }
            break;
        }

        default: {
            break;
        }
    }
}

void Phy::plme_set_trx_state_confirm(phyStatus_t status) {
    // send confirm to MLME
}

void Phy::plme_switch_request(bool* swBitMap, bool dir) {

}

void Phy::plme_switch_confirm(phyStatus_t status) {

}

void Phy::pd_data_request(uint64_t psduLength, uint8_t* psdu, uint8_t bandplanID) {

}

void Phy::pd_data_confirm(phyStatus_t status) {

}

void Phy::pd_data_indication(uint64_t psduLength, uint8_t* psdu, uint8_t ppduLinkQuality) {

}




