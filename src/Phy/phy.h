/*
 * phy.h
 *
 *  Created on: Mar 2, 2024
 *      Author: cotti
 */

#ifndef PHY_H_

#include "../types.h"
#include <omnetpp.h>
#include "../msgs/msgs.h"
#include "../constants.h"

#define PHY_MAX_ENUM_ATTRIBUTE 0x08

using namespace omnetpp;

class Phy : public cSimpleModule {
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;

        virtual void processMsgFromHigherLayer(cMessage *msg);


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
        phyStatus_t varTrxState = phyStatus_t::TRX_OFF;
        bool isBusyTx = false; // Wheter a transmission is ongoing or not (PPDU transmit).
        bool isBusyRx = false;
        MCS_t varMCS;

        phyStatus_t CCA;   // BUSY or IDLE

        uint8_t varTopology = 1; // 1 == P1, 2 == P2 ...


    public:

        /*---------------- Start primitives -------------------------------*/
        void plme_cca_request(PLMECCARequest* msg);
        void plme_cca_confirm(PLMECCAConfirm* msg);

        void plme_get_request(PLMEGetRequest* msg);
        void plme_get_confirm(PLMEGetConfirm* msg);

        void plme_set_request(PLMESetRequest* msg);
        void plme_set_confirm(PLMESetConfirm* msg);

        void plme_set_trx_state_request(PLMESetTrxStateRequest* msg);
        void plme_set_trx_state_confirm(PLMESetTrxStateConfirm* msg);

        void plme_switch_request(PLMESwitchRequest* msg);
        void plme_switch_confirm(PLMESwitchConfirm* msg);

        void pd_data_request(PDDataRequest* msg);
        void pd_data_confirm(PDDataConfirm* msg);
        void pd_data_indication(PDDataIndication* msg);
        /*---------------- End primitives -------------------------------*/

        void transmitToChannel(uint8_t* payload, size_t payloadLength);
};


#endif /* PHY_H_ */
