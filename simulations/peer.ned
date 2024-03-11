//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 
package ieee802157.simulations;
import ieee802157.simulations.Mac;
import ieee802157.simulations.Phy;
import ieee802157.simulations.Net;

//
// TODO auto-generated type
//
module Peer
{
    
    parameters:
   	    @display("bgb=330,250");
   	    bool sendMsgOnInit = default(false); 
    
   	gates:
   	    output indicationOut;
   	    input responseIn; 
    
    submodules:
        macPeer: Mac {
            parameters:
                // TODO set parameters for client
                powerSource = true;
                batteryInformation = 3;		// batteryInformation_t::BAT_CONNECTED
                coordinatorCapability = true;
                traficSupport = true;
                broadcastSupport = true;
                peerToPeerSupport = true;
                starSupport = true;
                deviceType = 0;		// deviceType_t::INFRASTRUCTURE
                beaconSupport = true;
                dimmingSupport = true;
                continuousVisibilityTransmission = true;
                cvdSupport = false;
                phyISupport = true;
                phyIISupport = true;
                colorStabilizationCapability = 0;
                maxTxClock = 100; // <= 15M
                maxRxClock = 100; // <= 15M
                ccaSupport = true;
                numberOfOpticalSources = 1;
                multipleDirectionSupport = 1;
                numberOfCellsSupported = 1;
                @display("p=150,113");
        }

        phyPeer: Phy {
            parameters:
                @display("p=150,195");
        }

        netPeer: Net {
            parameters:
            	@display("p=150,33");
            	sendMsgOnInit = parent.sendMsgOnInit;
        }

    connections:
        netPeer.requestOut --> {  delay = 100ms; } --> macPeer.requestIn;
        netPeer.confirmIn <-- {  delay = 100ms; } <-- macPeer.confirmOut;

        macPeer.indicationOut --> {  delay = 100ms; } --> phyPeer.requestIn;
        macPeer.responseIn <-- {  delay = 100ms; } <-- phyPeer.confirmOut;
        
        phyPeer.indicationOut --> indicationOut;
        phyPeer.responseIn <-- responseIn;
}