/**
 * basic Timer function for ESP32, 
 * including timers init, Timer setup, and Interrupt function define
*/

#include <esp32-hal-timer.h>

int IF_TIMER_INIT_0 = -1;
int IF_TIMER_INIT_1 = -1;
int IF_TIMER_INIT_2 = -1;
int IF_TIMER_INIT_3 = -1;

hw_timer_t *timer0 = NULL;
hw_timer_t *timer1 = NULL;
hw_timer_t *timer2 = NULL;
hw_timer_t *timer3 = NULL;


void init_Timer(int divide_freq, int timer_id){
    if(timer_id == -1){ return;}

    switch (timer_id)
    {
    case 0:
        if(IF_TIMER_INIT_0 == 1){
            printf("TIMER_0 HAS ALREADY BEEN INIT !");
            return;
        }
        timer0 = timerBegin(0, divide_freq, true);
        IF_TIMER_INIT_0 = 1;
        break;
    case 1:
        if(IF_TIMER_INIT_1 == 1){
            printf("TIMER_1 HAS ALREADY BEEN INIT !");
            return;
        }
        timer1 = timerBegin(1, divide_freq, true);
        IF_TIMER_INIT_1 = 1;
        break;
    case 2:
        if(IF_TIMER_INIT_2 == 1){
            printf("TIMER_2 HAS ALREADY BEEN INIT !");
            return;
        }
        timer2 = timerBegin(2, divide_freq, true);
        IF_TIMER_INIT_2 = 1;
        break;
    case 3:
        if(IF_TIMER_INIT_3 == 1){
            printf("TIMER_3 HAS ALREADY BEEN INIT !");
            return;
        }
        timer3 = timerBegin(3, divide_freq, true);
        IF_TIMER_INIT_3 = 1;
        break;
    default:
        printf("TIMER ID NOT FOUND ! \n");
        break;
    }
}


// void init_Interupt(){
//      timerAttachInterrupt(timer, &onTimer, true); // Attach the interrupt handler function
//      timerAlarmWrite(timer, 10000, true); // Set the alarm time (microseconds) and auto reload (10000 microseconds = 0.01 seconds)
//      timerAlarmEnable(timer); // Enable the timer interrupt
// }