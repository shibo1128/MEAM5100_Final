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
    Serial.print("[ultra]: "); Serial.print(dist_1); Serial.print("cm");
}