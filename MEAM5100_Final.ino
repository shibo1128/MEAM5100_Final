/**
 * main loop for this project
 * 
*/
/*

#include <WiFi.h>

void setup() {
  Serial.begin(115200); // Start the Serial communication
  delay(10);

  // Print the MAC address
  Serial.print("ESP32 MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // No need to put anything in the loop for this example
}

*/



#include "actuators/motor.hpp"

MecanumController mecanumController(38, 4, 11,
                                    39, 5, 12,
                                    40, 6, 13,
                                    41, 7, 14);


void setup()
{
}

void loop(){
   
    mecanumController.turn(1,100);
    delay(1000);/*
    mecanumController.move_backward(70);
    delay(1000);
    mecanumController.move_left(70);
    delay(1000);
    mecanumController.move_right(70);
    delay(1000);
    mecanumController.turn(0,70);
    delay(1000);
    mecanumController.turn(1,70);
    delay(1000);*/
    
}

