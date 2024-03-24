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

#include "../msgs/msgs.h"
#include "../constants.h"


using namespace omnetpp;

class Mac : public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    virtual void processMsgFromHigherLayer(cMessage *msg);
    virtual void processMsgFromLowerLayer(cMessage *msg);

private:

    void setMacMaxFrameTotalWaitTime(void);

public:

    // Timers
    cMessage* timerBackoff = nullptr;
    cMessage* timerBeaconInterval = nullptr;
    cMessage* timerOpticalClock = nullptr;
    cMessage* timerSlot = nullptr;

    cMessage* timerConfirm = nullptr;
    bool notificationTimerConfirm = false;

    // Internal variables used by several fsm
    capabilityInformation_t varCapabilities;
    uint32_t varOpticalClockDuration;
    uint8_t phyType;
    bool pdDataConfirmReceived;

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

    // Used to catch confirm events from PHY
    bool notificationConfirmReceived = false;
    phyStatus_t confirmPhyStatus;


    // Used by the reset FSM
    bool resetSetDefaultPIB;
    bool notificationResetRequest = false;

    // Used by the GET FSM
    bool notificationGetRequest = false;
    PIBAttribute_t getPIBAttribute;
    uint64_t getPHYPIBAttributeValue;

    // Used by the SET FSM
    bool notificationSetRequest = false;
    PIBAttribute_t setPIBAttribute;
    uint64_t setPIBAttributeValue;

    // Used by the SCAN FSM
    bool notificationScan = false;
    opticalChannel_t scanChannels[8];
    uint8_t scanChannelsLeft;
    cMessage* timerScanDuration = nullptr;
    uint8_t scanDuration;
    bool timerScanDurationTriggered = false;
    scanType_t scanType;

    // Used by the DATA FSM
    bool notificationRequestData = false;
    cMessage *timerAckWait;
    bool timerAckWaitTriggered = false;

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
    colorStabilizationScheme_t macColorStabilization = (colorStabilizationScheme_t) 0;
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
    bool macAcknowledgeField                = false;
    uint8_t* macFramePayload                = NULL;
    uint16_t macFCS                         = 0;
    uint16_t macMsduLength                  = 0;
    uint8_t macOffsetVPWMDataUsage          = 0;
    uint8_t mac2DCODETxDataType             = 0;

    void waitForConfirm();
    void resetPIB(void);
    void resetInternalVariables(void);

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
    void mcps_data_request(cMessage* msg);
    void mlme_associate_request(cMessage* msg);
    void mlme_disassociate_request(cMessage* msg);
    void mlme_get_request(cMessage* msg);
    void mlme_gts_request(cMessage* msg);
    void mlme_reset_request(cMessage* msg);
    void mlme_rx_enable_request(cMessage* msg);
    void mlme_scan_request(cMessage* msg);
    void mlme_set_request(cMessage* msg);
    void mlme_start_request(cMessage* msg);
    void mlme_sync_request(cMessage* msg);
    void mlme_poll_request(cMessage* msg);

    void mcps_data_confirm(uint8_t msduHandle, macStatus_t status, uint32_t timestamp);
    void mlme_associate_confirm(uint16_t assocShortAddress, macStatus_t status, colorStabilizationScheme_t capabilityNegotationResponse, uint8_t securityLevel);
    void mlme_disassociate_confirm(macStatus_t status, addressingMode_t deviceAddrMode, uint16_t deviceOWPANId, uint64_t deviceAddress);
    void mlme_get_confirm(macStatus_t status, PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex, uint64_t PIBAttributeValue);
    void mlme_gts_confirm(uint8_t GTSCharacteristics, macStatus_t status);
    void mlme_reset_confirm(macStatus_t status);
    void mlme_rx_enable_confirm(macStatus_t status);
    void mlme_scan_confirm(macStatus_t status, scanType_t scanType, uint8_t unscannedChannels, uint16_t resultListSize, uint8_t* OWPANDescriptorList);
    void mlme_set_confirm(macStatus_t status, PIBAttribute_t PIBAttribute, uint8_t PIBAttributeIndex);
    void mlme_start_confirm(macStatus_t status);
    void mlme_poll_confirm(macStatus_t status);

    void mcps_data_indication(MCPSDataIndication* msg);
    void mlme_associate_indication(MLMEAssociateIndication* msg);
    void mlme_disassociate_indication(MLMEDisassociateIndication* msg);
    void mlme_beacon_notify_indication(MLMEBeaconNotifyIndication* msg);
    void mlme_comm_status_indication(MLMECommStatusIndication* msg);
    void mlme_sync_loss_indication(MLMESyncLossIndication* msg);

    void mlme_associate_response(MLMEAssociateResponse* msg);

    // --------------- Start phy primitives ------------------- //
    void plme_cca_confirm(cMessage* msg);
    void plme_get_confirm(cMessage* msg);
    void plme_set_confirm(cMessage* msg);
    void plme_set_trx_state_confirm(cMessage* msg);
    void plme_switch_confirm(cMessage* msg);
    void pd_data_confirm(cMessage* msg);

    void plme_cca_request(void);
    void plme_get_request(PIBAttribute_t PIBAttribute);
    void plme_set_request(PIBAttribute_t PIBAttribute, uint64_t PIBAttributeValue);
    void plme_set_trx_state_request(phyStatus_t state);
    void plme_switch_request(bool* swBitMap, bool dir);
    void pd_data_request(uint16_t psduLength, uint8_t* psdu, opticalChannel_t bandplanID);
    // --------------- End phy primitives ------------------- //
};


#endif /* MAC_H_ */
