#ifndef __ULTRA__
#define __ULTRA__

#define TRIG_PIN_1 3
#define ECHO_PIN_1 8
#define TRIG_PIN_2 9
#define ECHO_PIN_2 10
#define LIM_DIST 100 //cm

#define threshold_to_front_wall 10
#define upper_threshold_to_side_wall 25
#define lower_threshold_to_side_wall 15

#define ULTRA_READ_TIME_INTERVAL 10000  // 10000 micro-second -> 10ms
int IF_INIT_ULTRA = -1;

volatile double dist_1 = 0;
volatile double dist_2 = 0;


float getDistance1() {
  int count = 0;
  float sum = 0;
  while(count < 3){
    count++;
    digitalWrite(TRIG_PIN_1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_1, LOW);

    unsigned long duration = pulseIn(ECHO_PIN_1, HIGH);

    sum += (sum > LIM_DIST) ? LIM_DIST : duration * 0.034 / 2; // cm
  } 
  return sum / 3;
}


float getDistance2() {
  int count = 0;
  float sum = 0;
  while(count < 3){
    count++;
    digitalWrite(TRIG_PIN_2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_2, LOW);

    unsigned long duration = pulseIn(ECHO_PIN_2, HIGH);

    sum += (sum > LIM_DIST) ? LIM_DIST : duration * 0.034 / 2; // cm
  }
  return sum / 3;
}


int isClose1() {
  return (dist_1 < threshold_to_front_wall) ? 0 : 1;
}


int isClose2() {
  return (dist_2 < lower_threshold_to_side_wall) ? 0 : 1;
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
