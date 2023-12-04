/**
 * main loop for this project
 * 
*/
#include "actuators/motor.hpp"

MecanumController mecanumController(38, 4, 39, 5, 40, 6, 41, 7);


void setup()
{
}

void loop(){
  
    mecanumController.move_forward(70);
    delay(1000);
    mecanumController.move_backward(70);
    delay(1000);
    mecanumController.move_left(70);
    delay(1000);
    mecanumController.move_right(70);
    delay(1000);
    mecanumController.turn(0,70);
    delay(1000);
    mecanumController.turn(1,70);
    delay(1000);
    
}