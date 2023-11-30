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

#include"mecanum_controller.h"

MecanumController::MecanumController(int FLPIN1, int FLPIN2, int FRPIN1, int FRPIN2,
                                     int BLPIN1, int BLPIN2, int BRPIN1, int BRPIN2)
{
    FL_DIR_PIN=FLPIN1;
    FR_DIR_PIN=FRPIN1;
    BL_DIR_PIN=BLPIN1;
    BR_DIR_PIN=BRPIN1;
    FL_SPEED_PIN=FLPIN2;
    FR_SPEED_PIN=FRPIN2;
    BL_SPEED_PIN=BLPIN2;
    BR_SPEED_PIN=BRPIN2;

    //Initialize PIN mode
    pinMode(FL_PIN1,OUTPUT);
    pinMode(FL_PIN2,OUTPUT);
    pinMode(FR_PIN1,OUTPUT);
    pinMode(FR_PIN2,OUTPUT);
    pinMode(BL_PIN1,OUTPUT);
    pinMode(BL_PIN2,OUTPUT);
    pinMode(BR_PIN1,OUTPUT);
    pinMode(BR_PIN2,OUTPUT);

    

}

