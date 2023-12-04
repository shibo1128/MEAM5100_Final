/**
 * main loop for this project
*/
#include "sensor/ultra.hpp"

#define ULTRA_TIMER 0

void setup(){
    Serial.begin(115200);
    ultra_sensors_init(ULTRA_TIMER);
}


void loop(){
  Serial.println(dist_1);
}