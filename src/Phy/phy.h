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
        uint8_t phyColorFunction;   //TODO wrong type
        uint8_t phyBlinkingNotificationFrequency;
        bool phyOccEnable;
        uint8_t phyOccMcsID;
        uint16_t phyPSDULength;


        // PLME-SET-TRX and transmitter
        phyStatus_t trxState = phyStatus_t::TRX_OFF;
        phyStatus_t futureTrxState;
        bool notificationChangeTrx = false; // TODO when finishing a RX or TX, change trxState to this value
        bool isBusyTx = false; // Whether a transmission is ongoing or not (PPDU transmit).
        bool isBusyRx = false;



        MCS_t varMCS;

        topology_t topology;


    public:

        // FSM TX
        uint8_t* psdu;
        bool notificationStartTx = false;

        /*---------------- Start primitives -------------------------------*/
        void plme_cca_request(PLMECCARequest* msg);
        void plme_cca_confirm(phyStatus_t status);

        void plme_get_request(PLMEGetRequest* msg);
        void plme_get_confirm(phyStatus_t status, PIBAttribute_t PIBAttribute, uint64_t PIBAttributeValue);

        void plme_set_request(PLMESetRequest* msg);
        void plme_set_confirm(phyStatus_t status, PIBAttribute_t PIBAttribute);

        void plme_set_trx_state_request(PLMESetTrxStateRequest* msg);
        void plme_set_trx_state_confirm(phyStatus_t status);

        void plme_switch_request(PLMESwitchRequest* msg);
        void plme_switch_confirm(PLMESwitchConfirm* msg);

        void pd_data_request(PDDataRequest* msg);
        void pd_data_confirm(phyStatus_t status);
        void pd_data_indication(PDDataIndication* msg);
        /*---------------- End primitives -------------------------------*/

        void transmitToChannel();
};


#endif /* PHY_H_ */
