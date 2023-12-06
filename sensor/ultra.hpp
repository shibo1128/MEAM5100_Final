#ifndef __ULTRA__
#define __ULTRA__

#define TRIG_PIN_1 4
#define ECHO_PIN_1 5
#define TRIG_PIN_2 6
#define ECHO_PIN_2 7
#define LIM_DIST 100 //cm
#define threshold_to_wall 3
#define ULTRA_READ_TIME_INTERVAL 10000  // 10000 micro-second -> 10ms
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
  return (dist_1 < threshold_to_wall) ? 0 : 1;
}


int isClose2() {
  return (dist_2 < threshold_to_wall) ? 0 : 1;
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
}



#endif
