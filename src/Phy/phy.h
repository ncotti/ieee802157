/*
 * phy.h
 *
 *  Created on: Mar 2, 2024
 *      Author: cotti
 */

#ifndef PHY_H_
#define PHY_H_

#include "../types.h"
#include <omnetpp.h>

using namespace omnetpp;





class Phy : public cSimpleModule {
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;


    private:
        // PHY PIB attributes
        opticalChannel_t phyCurrentChannel;
        uint8_t phyCCAMode;
        uint16_t phyDim;
        bool phyUseExtendedMode;
        uint8_t phyColorFunction;   // wrong type
        uint8_t phyBlinkingNotificationFrequency;
        bool phyOccEnable;
        uint8_t phyOccMcsID;
        uint16_t phyPSDULength;

        // PHY custom variables
        phyStatus_t phyStatus = phyStatus_t::TRX_OFF;
        bool isBusyTx = false; // Wheter a transmission is ongoing or not (PPDU transmit).
        bool isBusyRx = false;


    public:

        void plme_cca_request(void);

        void plme_cca_confirm(phyStatus_t status);

        void plme_get_request(uint8_t PIBAttribute);

        void plme_get_confirm(phyStatus_t status, uint8_t PIBAttribute,
                uint64_t PIBAttributeValue);

        void plme_set_request(phyPIBAtrribute_t PIBAttribute, uint64_t PIBAttributeValue);

        void plme_set_confirm(phyStatus_t status, phyPIBAtrribute_t PIBAttribute);

        void plme_set_trx_state_request(phyStatus_t state);

        void plme_set_trx_state_confirm(phyStatus_t status);

        void plme_switch_request(bool* swBitMap, bool dir);

        void plme_switch_confirm(phyStatus_t status);

        void pd_data_request(uint64_t psduLength, uint8_t* psdu, uint8_t bandplanID);

        void pd_data_confirm(phyStatus_t status);

        void pd_data_indication(uint64_t psduLength, uint8_t* psdu, uint8_t ppduLinkQuality);
};


#endif /* PHY_H_ */
