/*
 * Net.h
 *
 *  Created on: Mar 6, 2024
 *      Author: cotti
 */

#ifndef NET_H_
#define NET_H_

#include <omnetpp.h>

#include "../msgs/msgs.h"
#include "../types.h"

using namespace omnetpp;

class Net : public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    virtual void processMsgFromLowerLayer(cMessage *msg);


public:

    macStatus_t macStatus;

    // Used for FSM START NET
    bool notificationStartOWPAN;
    uint16_t OWPANId;

    // Notification from mlme_xxx_confirm
    bool notificationConfirmData;
    bool notificationConfirmAssociate;
    bool notificationConfirmDisassociate;
    bool notificationConfirmGet;
    bool notificationConfirmGTS;
    bool notificationConfirmReset;
    bool notificationConfirmRxEnable;
    bool notificationConfirmScan;
    bool notificationConfirmSet;
    bool notificationConfirmStart;
    bool notificationConfirmPoll;

    // -------------------- Primitives ------------------------------------- //
    void mcps_data_request(addressingMode_t srcAddrMode,
                addressingMode_t dstAddrMode, uint16_t dstOWPANId, uint64_t dstAddr,
                uint16_t msduLength, uint8_t* msdu, uint8_t msduHandle, uint8_t txOptions,
                uint8_t securityLevel,
                MCS_t dataRate, bool burstMode,  bool colorReceived, bool colorNotReceived);

    void mlme_associate_request(opticalChannel_t logicalChannel,
                addressingMode_t coordAddrMode, uint16_t coordOWPANId,
                uint64_t coordAddress, capabilityInformation_t capabilityInformation,
                uint8_t securityLevel, bool colorAssoc);

    void mlme_disassociate_request(addressingMode_t deviceAddrMode, uint16_t deviceOWPANId,
                uint64_t deviceAddress, uint8_t disassociateReason, bool txIndirect,
                uint8_t securityLevel, bool colorDisAssoc);

    void mlme_get_request(PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex);

    void mlme_gts_request(uint8_t GTSCharacteristics, uint8_t securityLevel);

    void mlme_reset_request(bool setDefaultPIB);

    void mlme_rx_enable_request(bool deferPermit, uint32_t rxOnTime, uint32_t rxOnDuration);

    void mlme_scan_request(scanType_t scanType, uint8_t scanChannels, uint8_t scanDuration,
                uint8_t securityLevel, bool colorScan);

    void mlme_set_request(PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex, uint64_t PIBAttributeValue);

    void mlme_start_request(uint16_t OWPANId, opticalChannel_t logicalChannel,
                uint32_t startTime, uint8_t beaconOrder, uint8_t superframeOrder,
                bool OWPANCoordinator, bool coordRealignment, uint8_t coordRealingmentSecurityLevel,
                uint8_t beaconSecurityLevel);

    void mlme_sync_request(opticalChannel_t logicalChannel, bool trackBeacon);

    void mlme_poll_request(addressingMode_t coordAddrMode, uint16_t coordOWPANId,
                uint64_t coordAddress, uint8_t securityLevel);




    void mcps_data_confirm(cMessage* msg);
    void mlme_associate_confirm(cMessage* msg);
    void mlme_disassociate_confirm(cMessage* msg);
    void mlme_get_confirm(cMessage* msg);
    void mlme_gts_confirm(cMessage* msg);
    void mlme_reset_confirm(cMessage* msg);
    void mlme_rx_enable_confirm(cMessage* msg);
    void mlme_scan_confirm(cMessage* msg);
    void mlme_set_confirm(cMessage* msg);
    void mlme_start_confirm(cMessage* msg);
    void mlme_poll_confirm(cMessage* msg);


    // ------------------- End Primitives ---------------------------------- //
};



#endif /* NET_H_ */
