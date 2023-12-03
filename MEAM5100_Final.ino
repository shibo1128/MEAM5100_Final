/**
 * main loop for this project
*/
#include "sensor/ultra.hpp"

void setup(){
    Serial.begin(115200);
    ultra_sensors_init();
}

void loop(){
    getDistance1();
    printf("1 \n");
    delay(100); 
}