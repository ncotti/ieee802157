/*
 * states.cpp
 *
 *  Created on: Mar 11, 2024
 *      Author: cotti
 */

#include "states.h"

/******************************************************************************
 * State declarations
******************************************************************************/
const stateSuperframe_t stBeacon = {
    .st = ST_BEACON,
    .stFn = stateBeaconFn,
};

const stateSuperframe_t stCAP = {
    .st = ST_CAP,
    .stFn = stateCAPFn,
};

const stateSuperframe_t stCFP = {
    .st = ST_CFP,
    .stFn = stateCFPFn,
};

const stateSuperframe_t stInactive = {
    .st = ST_INACTIVE,
    .stFn = stateInactiveFn,
};

/******************************************************************************
 * State functions
******************************************************************************/
stateSuperframe_t stateBeaconFn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerSlot) {
        mac->varSlotCount++;
        if (mac->varSlotCount == 16) {
            return stInactive;
        }
    } else { // TODO if (received confirmation from beacon frame transmit)
        if (mac->macSuperframeOrder == 15) {
            return stInactive;
        } else {
            return stCAP;
        }
    }

    return stBeacon;
}

stateSuperframe_t stateCAPFn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerSlot) {
        mac->varSlotCount++;
        if (mac->varSlotCount == 16) {
            return stInactive;
        }
    }

    return stCAP;
}

stateSuperframe_t stateCFPFn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerSlot) {
        mac->varSlotCount++;
        if (mac->varSlotCount == 16) {
            return stInactive;
        }
    }

    return stCFP;
}

stateSuperframe_t stateInactiveFn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerBeaconInterval) {
        if (mac->macBeaconOrder == 15) {
            return stInactive;
        } else {
            return stBeacon;
        }
    }

    return stInactive;
}

