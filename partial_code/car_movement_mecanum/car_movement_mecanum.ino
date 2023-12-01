#include"mecanum_controller.h"

MecanumController controller(FL_PIN1, FL_PIN2, FR_PIN1, FR_PIN2, BL_PIN1, BL_PIN2, BR_PIN1, BR_PIN2);
controller.setPID(1.0, 0.1, 0.05, 10.0); // Example PID values and setpoint

void loop() {
    double distance = getDistance(); // Function to get distance from ultrasonic sensor
    double pidOutput = controller.calculatePID(distance);

    // add ultrasonic code
}
