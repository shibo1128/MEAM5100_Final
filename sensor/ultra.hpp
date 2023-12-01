#ifndef __ULTRA__
#define __ULTRA__

#include "Arduino.h"
#define TRIG_PIN_1 4
#define ECHO_PIN_1 5
#define TRIG_PIN_2 4
#define ECHO_PIN_2 5
#define LIM_DIST 100 //cm

volatile float dist_1 = 0;
volatile float dist_2 = 0;


unsigned int UltrasonicSensor::getDistance() {
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);

  unsigned long duration = pulseIn(ECHO_PIN_1, HIGH);

 dist_1 = duration * 0.034 / 2;
}


#endif
