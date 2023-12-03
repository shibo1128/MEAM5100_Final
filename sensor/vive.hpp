#ifndef __MYVIVE__
#define __MYVIVE__

#include <vive510.h>

#define SIGNALPIN1 1 // pin receiving signal from Vive circuit
#define VIVE_STATE -1
volatile uint16_t xcoor, ycoor;

void VIVE_INIT(){
    Vive510 vive1(SIGNALPIN1);
    vive1.begin();
}

void Getcoor(){
    if (vive1.status() == VIVE_RECEIVING) {
        xcoor = vive1.xCoord();
        ycoor = vive1.yCoord();
        VIVE_STATE = 0;
    }else {
        xcoor=-1;
        xcoor=-1; 
        switch (vive1.sync(5)) {
            break;
            case VIVE_SYNC_ONLY: // missing sweep pulses (signal weak)
                VIVE_STATE = -1;
            break;
            default:
            case VIVE_NO_SIGNAL: // nothing detected     
                VIVE_STATE = -2;
        }
    }
}

#endif