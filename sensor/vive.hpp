#ifndef __MYVIVE__
#define __MYVIVE__

/***
 * A BIG THANKS TO MARK YIM
*/

#include "../utils/vive510.h"


#define SIGNALPIN1 1 // pin receiving signal from Vive circuit
//#define VIVE_STATE -1
volatile uint16_t xcoor, ycoor;

Vive510 vive1(SIGNALPIN1);

void VIVE_INIT(){
    vive1.begin();
}

void Getcoor(){
    if (vive1.status() == VIVE_RECEIVING) {
        xcoor = vive1.xCoord();
        ycoor = vive1.yCoord();
    }else {
        xcoor=-1;
        xcoor=-1; 
        switch (vive1.sync(5)) {
            break;
            case VIVE_SYNC_ONLY: // missing sweep pulses (signal weak)
                Serial.println("missing sweep pulses (signal weak)");
            break;
            default:
            case VIVE_NO_SIGNAL: // nothing detected     
                Serial.println("nothing detected ");
        }
    }
}

#endif