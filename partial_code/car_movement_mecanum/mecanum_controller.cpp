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
    FL_PIN1=FLPIN1;
    FR_PIN1=FRPIN1;
    BL_PIN1=BLPIN1;
    BR_PIN1=BRPIN1;
    FL_PIN2=FLPIN2;
    FR_PIN2=FRPIN2;
    BL_PIN2=BLPIN2;
    BR_PIN2=BRPIN2;

    //Initialize PIN mode
    pinMode(FL_PIN1,OUTPUT);
    

}

