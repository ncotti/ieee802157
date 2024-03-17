#include "fsm_superframe.h"

static fsm_superframe_state_t current_state = FSM_SUPERFRAME_INITIAL_STATE;

/******************************************************************************
 * State functions
******************************************************************************/
static fsm_superframe_state_t st_beacon_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerSlot) {
        mac->varSlotCount++;
        if (mac->varSlotCount == aNumSuperframeSlots) {
            return ST_INACTIVE;
        }
    } else { // TODO if (received confirmation from beacon frame transmit)
        if (mac->macSuperframeOrder == 15) {
            return ST_INACTIVE;
        } else {
            return ST_CAP;
        }
    }

    return ST_BEACON;
}

static fsm_superframe_state_t st_CAP_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerSlot) {
        mac->varSlotCount++;
        if (mac->varSlotCount == aNumSuperframeSlots) {
            return ST_INACTIVE;
        }

        // if (GTS slot next) return stCFP;
    }

    return ST_CAP;
}

static fsm_superframe_state_t st_CFP_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerSlot) {
        mac->varSlotCount++;
        if (mac->varSlotCount == aNumSuperframeSlots) {
            return ST_INACTIVE;
        }
    }

    return ST_CFP;
}

static fsm_superframe_state_t st_inactive_fn(const cMessage* msg, Mac* mac) {
    if (msg == mac->timerBeaconInterval || msg == mac->notificationBeaconEnabled) {
        if (mac->macBeaconOrder != 15) {
            return ST_BEACON;
        }
    }

    return ST_INACTIVE;
}

/******************************************************************************
 * State function list
******************************************************************************/
static const fsm_superframe_fn_t fsm_superframe_fn_list[FSM_SUPERFRAME_STATE_QTY] = {
    st_beacon_fn,
    st_CAP_fn,
    st_CFP_fn,
    st_inactive_fn,
};

/******************************************************************************
 * FSM (Finite state machine)
******************************************************************************/
void fsm_superframe(const cMessage* msg, Mac* mac) {
    fsm_superframe_state_t new_state = fsm_superframe_fn_list[current_state](msg, mac);
    fsm_superframe_transition_t transition = fsm_superframe_transition_table[current_state][new_state];

    if (transition) {
        transition(mac);
    }

    current_state = new_state;
}

fsm_superframe_state_t fsm_superframe_get_state(void) {
    return current_state;
}
