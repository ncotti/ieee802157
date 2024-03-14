/*
 * mac.h
 *
 *  Created on: Mar 2, 2024
 *      Author: cotti
 */

#ifndef MAC_H_
#define MAC_H_

#include "../types.h"
#include "../bit_macros.h"
#include <omnetpp.h>

#include "../constants.h"

#include "../msgs/msgs.h"

using namespace omnetpp;

class Mac : public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    virtual void processMsgFromHigherLayer(cMessage *msg);
    //virtual void processMsgFromLowerLayer(cMessage *msg);

private:



public:

    // Timers
    cMessage* timerBackoff = nullptr;
    cMessage* timerBeaconInterval = nullptr;
    cMessage* timerOpticalClock = nullptr;
    cMessage* timerSlot = nullptr;

    // Internal variables used by several fsm
    capabilityInformation_t varCapabilities;
    uint32_t varOpticalClockDuration;

    // Used by the FSM Superframe
    uint16_t varBeaconInterval;
    uint16_t varSuperframeDuration;
    uint16_t varSlotDuration;
    uint8_t varSlotCount;

    uint8_t macSuperframeOrder              = 15;
    uint8_t macBeaconOrder                  = 15;

    cMessage* notificationBeaconEnabled = nullptr;



    // Used by the FSM RandomAccess
    uint16_t varBackoffExponent;
    uint16_t varNumberOfBackoffs;
    bool varSlottedTx;
    uint16_t varRandomDelay;
    bool varAckRequired;

    uint8_t macMinBE                        = 3;

    cMessage* notificationAckNotReceived = nullptr;
    cMessage* notificationAckReceived = nullptr;
    cMessage* notificationChannelIdle = nullptr;
    cMessage* notificationChannelBusy = nullptr;
    cMessage* notificationStartTx = nullptr;
    cMessage* notificationFinishTx = nullptr;
    cMessage* notificationTxSuccess = nullptr;
    cMessage* notificationTxFailure = nullptr;



    // All MAC PIB attributes
    int macAckWaitDuration;
    bool macAssociatedOWPANCoord            = false;
    bool macAssociationPermit               = false;
    bool macAutoRequest                     = true;
    uint8_t* macBeaconPayload               = NULL;
    int macBeaconPayloadLength              = 0;

    uint32_t macBeaconTxTime                = 0;
    uint8_t macBSN                          = 0;                 // Random value for default
    uint64_t macCoordExtendedAddress;
    uint16_t macCoordShortAddress           = 0xffff;
    uint8_t macDSN                          = 0;                 // random value for default
    bool macGTSPermit                       = true;
    uint8_t macMaxBE                        = 5;
    uint8_t macMaxCSMABackoffs              = 4;
    int macMaxFrameTotalWaitTime;
    uint8_t macMaxFrameRetries              = 3;
    uint16_t macMaxRABackoffs;              // TODO this variables is mentioned, but not in the general PIB table.

    uint16_t macMinLIFSPeriod;
    uint16_t macMinSIFSPeriod;
    uint16_t macOWPANId                     = 0xffff;
    uint8_t macResponseWaitTime             = 32;
    bool macRxOnWhenIdle                    = false;
    bool macSecurityEnabled                 = true;
    uint16_t macShortAddress                = 0xffff;

    bool macTimestampSupported;
    uint16_t macTransactionPersistenceTime  = 0x01f4;
    uint16_t macDim                         = 0;
    uint8_t macNumAcks                      = 3;
    uint8_t macLinkTimeout                  = 63;
    bool macDimOverrideRequest              = false;
    bool macDimPWMOverrideRequest           = false;
    bool macDimDataFailureIndication        = false;
    uint8_t macDuringASSOCColor             = 0;
    uint8_t macDuringDISASSOCColor          = 0;
    uint8_t macDuringSCANColor              = 0;
    uint8_t macColorReceived                = 0;
    uint8_t macColorNotReceived             = 0;
    uint8_t macCQIColorLFER                 = 0;
    uint8_t macCQIColorMFER                 = 0;
    uint8_t macCQIColorHFER                 = 0;
    uint8_t macCFAppColor                   = 0;
    colorStabilizationScheme_t macColorStabilization;
    uint32_t macColorStabilizationTimer     = 0x00400000;
    bool macUseDimmedOOKmode                = false;
    uint8_t macTimeStampOffset              = 0;
    bool macUseBlinkingNotification         = true;
    uint8_t macBlinkingNotificationFrequency = 0;
    uint8_t macLedIdAmbiguityResolution     = 0;
    uint16_t macFrameControl                = 0;
    uint8_t macSequenceNumber               = 0;
    uint16_t macDestinationOWPANIdentifier  = 0;
    uint64_t macDestinationAddress          = 0;
    uint16_t macSourceOWPANIdentifier       = 0;
    uint64_t macSourceAddress               = 0;
    uint8_t* macAcknowledgeField            = NULL;
    uint8_t* macFramePayload                = NULL;
    uint16_t macFCS                         = 0;
    uint16_t macMsduLength                  = 0;
    uint8_t macOffsetVPWMDataUsage          = 0;
    uint8_t mac2DCODETxDataType             = 0;

    void waitForConfirm();
    uint16_t formatMHR(uint8_t* frame, uint16_t i, uint16_t frameControl, uint8_t sequenceNumber,
            uint16_t destOWPANId, uint64_t destAddress, uint16_t srcOWPANId, uint64_t srcAddress);

    void beaconFrame();

    uint16_t getFrameControl(frameType_t type, bool framePending, bool ackRequest,
            addressingMode_t destinationAddressMode, addressingMode_t sourceAddressMode);

    void transmitCommandFrame(commandFrameIdentifier_t id, addressingMode_t destinationAddressMode);

    void passiveChannelScan();
    void activeChannelScan(uint8_t scanChannels);
    void randomAccess();
    void association(bool activeScan);

    // --------------- Start primitives ------------------- //

    void mcps_data_request(MCPSDataRequest* msg);
    void mcps_data_confirm(MCPSDataConfirm* msg);
    void mcps_data_indication(MCPSDataIndication* msg);

    void mlme_associate_request(MLMEAssociateRequest* msg);
    void mlme_associate_indication(MLMEAssociateIndication* msg);
    void mlme_associate_response(MLMEAssociateResponse* msg);
    void mlme_associate_confirm(MLMEAssociateConfirm* msg);

    void mlme_disassociate_request(MLMEDisassociateRequest* msg);
    void mlme_disassociate_indication(MLMEDisassociateIndication* msg);
    void mlme_disassociate_confirm(MLMEDisassociateConfirm* msg);

    void mlme_beacon_notify_indication(MLMEBeaconNotifyIndication* msg);

    void mlme_get_request(MLMEGetRequest* msg);
    void mlme_get_confirm(MLMEGetConfirm* msg);

    void mlme_gts_request(MLMEGTSRequest* msg);
    void mlme_gts_confirm(MLMEGTSConfirm* msg);

    void mlme_reset_request(MLMEResetRequest* msg);
    void mlme_reset_confirm(MLMEResetConfirm* msg);

    void mlme_rx_enable_request(MLMERxEnableRequest* msg);
    void mlme_rx_enable_confirm(MLMERxEnableConfirm* msg);

    void mlme_scan_request(MLMEScanRequest* msg);
    void mlme_scan_confirm(MLMEScanConfirm* msg);

    void mlme_comm_status_indication(MLMECommStatusIndication* msg);

    void mlme_set_request(MLMESetRequest* msg);
    void mlme_set_confirm(MLMESetConfirm* msg);

    void mlme_start_request(MLMEStartRequest* msg);
    void mlme_start_confirm(MLMEStartConfirm* msg);

    void mlme_sync_request(MLMESyncRequest* msg);
    void mlme_sync_loss_indication(MLMESyncLossIndication* msg);

    void mlme_poll_request(MLMEPollRequest* msg);
    void mlme_poll_confirm(MLMEPollConfirm* msg);

    // --------------- End primitives ------------------- //
};


#endif /* MAC_H_ */
