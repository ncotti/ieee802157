/*
 * Net.h
 *
 *  Created on: Mar 6, 2024
 *      Author: cotti
 */

#ifndef NET_H_
#define NET_H_

#include <omnetpp.h>

using namespace omnetpp;

class Net : public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

public:

};



#endif /* NET_H_ */