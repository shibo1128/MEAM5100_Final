/*
                    .-"""-.
                   / .===. \
                   \/ 6 6 \/
                   ( \___/ )
  _____________ooo__\_____/________________________
 /      Author: Shibo Wang                         \
 |      Function: Mecanum Wheels car control       |
 \_____________________________ooo_________________/ 
                    |  |  |
                    |_ | _|
                    |  |  |
                    |__|__|
                    /-'Y'-\
                   (__/ \__)
*/

#ifndef MECANUM_CONTROLLER_H
#define MECANUM_CONTROLLER_H

#define FL_CHANNEL 0
#define FR_CHANNEL 1
#define BL_CHANNEL 2
#define BR_CHANNEL 3

const int frequency=3000;
const int resolution=12;

class MecanumController
{
    private:
    // Direction pin will be digital output, which with a NOT gate to control 2 directions ports on L298N.
        int FL_DIR_PIN;
        int FR_DIR_PIN;
        int BL_DIR_PIN;
        int BR_DIR_PIN;
        int FL_SPEED_PIN;
        int FR_SPEED_PIN;
        int BL_SPEED_PIN;
        int BR_SPEED_PIN;

        // PID control variables
        double Kp, Ki, Kd; // PID coefficients
        double setpoint; // Desired distance from the wall
        double integral, last_error;

    public:
        //Initial the PINs
        MecanumController(int FL_PIN1, int FL_PIN2, int FR_PIN1, int FR_PIN2,
                          int BL_PIN1, int BL_PIN2, int BR_PIN1, int BR_PIN2);

        void move_forward(double speed);
        void move_backward(double speed);
        void move_right(double speed);
        void move_left(double speed);
        void turn(bool direction, double speed); // 0-left, 1-right.

        // PID methods
        void setPID(double Kp, double Ki, double Kd, double setpoint);
        double calculatePID(double current_distance);

}
#endif