/*
 * Net.cpp
 *
 *  Created on: Mar 6, 2024
 *      Author: cotti
 */

#include "Net.h"

Define_Module(Net);

void Net::initialize() {
    if (par("sendMsgOnInit").boolValue()) {
        cMessage *msg = new cMessage("");
        EV << "Sending initial message\n";
        send(msg, "requestOut");
    }

}

void Net::handleMessage(cMessage *msg) {

}



