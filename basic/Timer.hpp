/**
 * basic Timer function for ESP32, 
 * including timers init, Timer setup, and Interrupt function define
*/

#include <esp32-hal-timer.h>

hw_timer_t *timer0 = NULL;
hw_timer_t *timer1 = NULL;
hw_timer_t *timer2 = NULL;
hw_timer_t *timer3 = NULL;

#define EN_TIMER_ID -1

void init_Timer(int divide_freq){
    switch (EN_TIMER_ID)
    {
    case 0:
        timer0 = timerBegin(0, divide_freq, true);
        break;
    case 1:
        timer1 = timerBegin(1, divide_freq, true);
        break;
    case 2:
        timer2 = timerBegin(2, divide_freq, true);
        break;
    case 3:
        timer3 = timerBegin(3, divide_freq, true);
        break;
    default:
        printf("TIMER ID NOT FOUND ! \n");
        break;
    }
}


void init_Interupt(){
    
}