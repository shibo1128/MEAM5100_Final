#ifndef __ULTRA__
#define __ULTRA__

#define TRIG_PIN_1 4
#define ECHO_PIN_1 5
#define TRIG_PIN_2 6
#define ECHO_PIN_2 7
#define LIM_DIST 100 //cm
#define threshold_to_wall 1

volatile float dist_1 = 0.0f;
volatile float dist_2 = 0.0f;


void ultra_sensors_init(){
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(ECHO_PIN_2, INPUT);
}


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



#endif
