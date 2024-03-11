
package ieee802157.simulations;
@license(LGPL);

simple Mac
{
    parameters:
        bool powerSource = default(false);
        int batteryInformation = default(0);	// BAT_UNKNOWN
        bool coordinatorCapability = default(false);
        bool traficSupport;
        bool broadcastSupport;
        bool peerToPeerSupport;
        bool starSupport;
        int deviceType;
        bool beaconSupport;
        bool dimmingSupport;
        bool continuousVisibilityTransmission;
        bool cvdSupport;
        bool phyISupport;
        bool phyIISupport;
        int colorStabilizationCapability;
        int maxTxClock;
        int maxRxClock;
        bool explicitClockNotificationRequest;
        bool ccaSupport;
        int numberOfOpticalSources;
        int multipleDirectionSupport;
        int numberOfCellsSupported;

    gates:
        input requestIn;
        output confirmOut;
        input responseIn;
        output indicationOut;
}

simple Phy
{
    parameters:

    gates:
        input requestIn;
        output confirmOut;
        input responseIn;
        output indicationOut;
}

simple Net
{
    parameters:
        bool sendMsgOnInit = default(false);
    gates:
        output requestOut;
        input confirmIn;
}


