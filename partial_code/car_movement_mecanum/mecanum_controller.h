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
class MecanumController
{
    private:
        int FL_PIN1;
        int FR_PIN1;
        int BL_PIN1;
        int BR_PIN1;
        int FL_PIN2;
        int FR_PIN2;
        int BL_PIN2;
        int BR_PIN2;

    public:
        //Initial the PINs
        MecanumController(int FL_PIN1, int FL_PIN2, int FR_PIN1, int FR_PIN2,
                          int BL_PIN1, int BL_PIN2, int BR_PIN1, int BR_PIN2);

        void move_forward(double speed);
        void move_backward(double speed);
        void move_right(double speed);
        void move_left(double speed);
        void turn(bool direction, double speed); // 0-left, 1-right.
}
#endif