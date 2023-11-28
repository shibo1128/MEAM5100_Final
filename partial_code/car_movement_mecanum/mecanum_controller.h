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
        MecanumController(int FL_PIN1, int flSpeedPin, int frDirPin, int frSpeedPin,
                           int rlDirPin, int rlSpeedPin, int rrDirPin, int rrSpeedPin);
        void move_forward(double speed);
}




#endif