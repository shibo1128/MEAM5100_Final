#ifndef __ULTRA__
#define __ULTRA__

#include "../basic/Timer.hpp"

#define TRIG_PIN_1 4
#define ECHO_PIN_1 5
#define TRIG_PIN_2 6
#define ECHO_PIN_2 7
#define LIM_DIST 100 //cm
#define threshold_to_wall 3
#define READ_TIME_INTERVAL 10000  // 10000 micro-second -> 10ms
int IF_INIT_ULTRA = -1;

volatile double dist_1 = 0;
volatile double dist_2 = 0;


void getDistance1() {
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);

  unsigned long duration = pulseIn(ECHO_PIN_1, HIGH);

  dist_1 = (dist_1 > LIM_DIST) ? LIM_DIST : duration * 0.034 / 2; // cm
}


void getDistance2() {
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);

  unsigned long duration = pulseIn(ECHO_PIN_2, HIGH);

  dist_2 = (dist_2 > LIM_DIST) ? LIM_DIST : duration * 0.034 / 2; // cm
}


int isClose1() {
  return (dist_1 < threshold_to_wall) ? 1 : 0;
}


int isClose2() {
  return (dist_2 < threshold_to_wall) ? 1 : 0;
}


// don't do too much in callback
void IRAM_ATTR ultra_callback(){
  getDistance1();
}


// Timer_id set to -1 if don't use interupt
void ultra_sensors_init(int Timer_id){
  if(IF_INIT_ULTRA == 1){
    printf("ULTRA HAS ALREADY BEEN INIT, RETURN");
    return;
  }
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(ECHO_PIN_2, INPUT);

  IF_INIT_ULTRA = 1;

  // open the reading interupt
  if(Timer_id >= 0){
    init_Timer(80,  Timer_id);
  }
  switch (Timer_id)
    {
    case 0:
        timerAttachInterrupt(timer0, &ultra_callback, true);
        timerAlarmWrite(timer0, READ_TIME_INTERVAL, true);
        timerAlarmEnable(timer0);
        break;
    case 1:
        timerAttachInterrupt(timer1, &ultra_callback, true);
        timerAlarmWrite(timer1, READ_TIME_INTERVAL, true);
        timerAlarmEnable(timer1);
        break;
    case 2:
        timerAttachInterrupt(timer2, &ultra_callback, true);
        timerAlarmWrite(timer2, READ_TIME_INTERVAL, true);
        timerAlarmEnable(timer2);
        break;
    case 3:
        timerAttachInterrupt(timer3, &ultra_callback, true);
        timerAlarmWrite(timer3, READ_TIME_INTERVAL, true);
        timerAlarmEnable(timer3);
        break;
    default:
        printf("TIMER ID FOR ULTRA INTERRUPT NOT FOUND ! \n");
        break;
    }
}



#endif
