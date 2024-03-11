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

using namespace omnetpp;

class Mac : public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

private:



public:

    // Timers
    cMessage* timerBackoff = nullptr;
    cMessage* timerBeaconInterval = nullptr;
    cMessage* timerOpticalClock = nullptr;
    cMessage* timerSlot = nullptr;

    // Internal variables
    capabilityInformation_t varCapabilities;
    uint32_t varOpticalClockDuration;

    uint16_t varBeaconInterval;
    uint16_t varSuperframeDuration;
    uint16_t varSlotDuration;
    uint8_t varSlotCount;

    // All MAC PIB attributes
    int macAckWaitDuration;
    bool macAssociatedOWPANCoord            = false;
    bool macAssociationPermit               = false;
    bool macAutoRequest                     = true;
    uint8_t* macBeaconPayload               = NULL;
    int macBeaconPayloadLength              = 0;
    uint8_t macBeaconOrder                  = 15;
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
    uint8_t macMinBE                        = 3;
    uint16_t macMinLIFSPeriod;
    uint16_t macMinSIFSPeriod;
    uint16_t macOWPANId                     = 0xffff;
    uint8_t macResponseWaitTime             = 32;
    bool macRxOnWhenIdle                    = false;
    bool macSecurityEnabled                 = true;
    uint16_t macShortAddress                = 0xffff;
    uint16_t macSuperframeOrder             = 15;
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

    void mcps_data_request(addressingMode_t srcAddrMode,
            addressingMode_t dstAddrMode, uint16_t dstOWPANId, uint64_t dstAddr,
            uint64_t msduLength, uint8_t* msdu, uint8_t msduHandle, uint8_t txOptions,
            security_t security,
            dataRate_t dataRate, bool burstMode,  bool colorReceived, bool colorNotReceived);
    void mcps_data_confirm(uint8_t msduHandle,
            macStatus_t status,
            uint32_t timestamp);
    void mcps_data_indication(addressingMode_t dstAddrMode, uint16_t dstOWPANId,
            uint64_t dstAddr, uint64_t msduLength, uint8_t* msdu, uint8_t mpduLinkQuality,
            uint8_t dsn, uint32_t timestamp, security_t security,
            dataRate_t dataRate, bool burstMode, bool colorReceived, bool colorNotReceived);

    void mlme_associate_request(opticalChannel_t logicalChannel,
            addressingMode_t coordAddrMode, uint16_t coordOWPANId,
            uint64_t coordAddress, capabilityInformation_t capabilityInformation,
            security_t security, bool colorAssoc);
    void mlme_associate_indication(uint64_t deviceAddress, capabilityInformation_t capabilityInformation,
            security_t security);
    void mlme_associate_response(uint64_t deviceAddress, uint16_t assocShortAddress,
            macStatus_t status, colorStabilizationScheme_t capabilityNegotiationResponse,
            security_t security);
    void mlme_associate_confirm(uint16_t assocShortAddress, macStatus_t status,
            colorStabilizationScheme_t capabilityNegotationResponse,
            security_t security);

    void mlme_disassociate_request(addressingMode_t deviceAddrMode, uint16_t deviceOWPANId,
            uint64_t deviceAddress, uint8_t disassociateReason, bool txIndirect,
            security_t security, bool colorDisAssoc);
    void mlme_disassociate_indication(uint64_t deviceAddress, uint8_t disassociateReason,
            security_t security);
    void mlme_disassociate_confirm(macStatus_t statis, addressingMode_t deviceAddrMode,
            uint16_t deviceOWPANId, uint64_t deviceAddress);

    void mlme_beacon_notify_indication(uint8_t bsn, OWPANDescritpor_t OWPANDescriptor,
            uint8_t pendAddrSpec, uint64_t* addrList, int sduLength, uint8_t* sdu);

    void mlme_get_request(int PIBAttribute, int PIBAttributeIndex);
    void mlme_get_confirm(macStatus_t status, int PIBAttribute,
            int PIBAttributeIndex, uint64_t PIBAttributeValue);

    void mlme_gts_request(uint8_t GTSCharacteristics,
            security_t security);
    void mlme_gts_confirm(uint8_t GTSCharacteristics, macStatus_t status);

    void mlme_reset_request(bool setDefaultPIB);
    void mlme_reset_confirm(macStatus_t status);

    void mlme_rx_enable_request(bool deferPermit, uint32_t rxOnTime, uint32_t rxOnDuration);
    void mlme_rx_enable_confirm(macStatus_t status);

    void mlme_scan_request(scanType_t scanType, uint8_t scanChannels, uint8_t scanDuration,
            security_t security, bool colorScan);
    void mlme_scan_confirm(macStatus_t status, uint8_t scanType, uint8_t unscannedChannels,
            int resultListSize, uint8_t* OWPANDescriptorList);

    void mlme_comm_status_indication(uint16_t OWPANId, addressingMode_t srcAddrMode,
            uint64_t srcAddr, addressingMode_t dstAddrMode, uint64_t dstAddr, macStatus_t status,
            security_t security);

    void mlme_set_request(int PIBAttribute, int PIBAttributeIndex, int PIBAttributeValue);
    void mlme_set_confirm(macStatus_t status, int PIBAttribute, int PIBAttributeIndex);

    void mlme_start_request(uint16_t OWPANId, opticalChannel_t logicalChannel,
            uint32_t startTime, uint8_t beaconOrder, uint8_t superframeOrder,
            bool OWPANCoordinator, bool coordRealignment, security_t coordSecurity,
            security_t beaconSecurity);
    void mlme_start_confirm(macStatus_t status);

    void mlme_sync_request(opticalChannel_t logicalChannel, bool trackBeacon);
    void mlme_sync_loss_indication(uint8_t lossReason, uint16_t OWPANId,
            opticalChannel_t logicalChannel, security_t security);

    void mlme_poll_request(addressingMode_t coordAddrMode, uint16_t coordOWPANId,
            uint64_t coordAddress, security_t security);
    void mlme_poll_confirm(macStatus_t status);

    // --------------- End primitives ------------------- //
};


#endif /* MAC_H_ */
