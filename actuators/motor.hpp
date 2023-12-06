/**
 * TT MOTOR , robot basic action + L298N 
*/

/*
                    .-"""-.
                   / .===. \
                  \/ -, -,\/
                   (  _|_  )
  ____________ooo__\/___/_/________________________
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

    public:
        //Initial the PINs


        // void move_forward(double speed);
        // void move_backward(double speed);
        // void move_right(double speed);
        // void move_left(double speed);
        // void turn(bool direction, double speed); // 0-left, 1-right.

        MecanumController(int FLPIN1, int FLPIN2, int FRPIN1, int FRPIN2,
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
            pinMode(FL_DIR_PIN,OUTPUT);
            pinMode(FR_DIR_PIN,OUTPUT);
            pinMode(BL_DIR_PIN,OUTPUT);
            pinMode(BR_DIR_PIN,OUTPUT);

            ledcSetup(FL_CHANNEL,frequency,resolution);
            ledcAttachPin(FL_SPEED_PIN,FL_CHANNEL);
            ledcSetup(FR_CHANNEL,frequency,resolution);
            ledcAttachPin(FR_SPEED_PIN,FR_CHANNEL);
            ledcSetup(BL_CHANNEL,frequency,resolution);
            ledcAttachPin(BL_SPEED_PIN,BL_CHANNEL);
            ledcSetup(BR_CHANNEL,frequency,resolution);
            ledcAttachPin(BR_SPEED_PIN,BR_CHANNEL);
        }

        ~MecanumController(){};

        void move_forward(double speed)
        {
            // Convert speed to PWM value (assuming speed is given in percentage)
            int pwmValue = map(speed, 0, 100, 0, 4095);

            // Set the direction of all wheels to forward
            digitalWrite(FL_DIR_PIN, HIGH);
            digitalWrite(FR_DIR_PIN, HIGH);
            digitalWrite(BL_DIR_PIN, HIGH);
            digitalWrite(BR_DIR_PIN, HIGH);

            // Set the speed of all wheels
            ledcWrite(FL_CHANNEL, pwmValue);
            ledcWrite(FR_CHANNEL, pwmValue);
            ledcWrite(BL_CHANNEL, pwmValue);
            ledcWrite(BR_CHANNEL, pwmValue);
        }

        void move_backward(double speed)
        {
            // Convert speed to PWM value (assuming speed is given in percentage)
            int pwmValue = map(speed, 0, 100, 0, 4095);

            // Set the direction of all wheels to forward
            digitalWrite(FL_DIR_PIN, LOW);
            digitalWrite(FR_DIR_PIN, LOW);
            digitalWrite(BL_DIR_PIN, LOW);
            digitalWrite(BR_DIR_PIN, LOW);

            // Set the speed of all wheels
            ledcWrite(FL_CHANNEL, pwmValue);
            ledcWrite(FR_CHANNEL, pwmValue);
            ledcWrite(BL_CHANNEL, pwmValue);
            ledcWrite(BR_CHANNEL, pwmValue);
        }

        void move_right(double speed)
        {
            // Convert speed to PWM value (assuming speed is given in percentage)
            int pwmValue = map(speed, 0, 100, 0, 4095);

            // Set the direction of all wheels to forward
            pwm_reset();
            digitalWrite(FL_DIR_PIN, HIGH);
            digitalWrite(FR_DIR_PIN, LOW);
            digitalWrite(BL_DIR_PIN, LOW);
            digitalWrite(BR_DIR_PIN, HIGH);

            // Set the speed of all wheels
            ledcWrite(FL_CHANNEL, pwmValue);
            ledcWrite(FR_CHANNEL, pwmValue);
            ledcWrite(BL_CHANNEL, pwmValue);
            ledcWrite(BR_CHANNEL, pwmValue);
        }

        void move_left(double speed)
        {
            // Convert speed to PWM value (assuming speed is given in percentage)
            int pwmValue = map(speed, 0, 100, 0, 4095);

            // Set the direction of all wheels to forward
            digitalWrite(FL_DIR_PIN, LOW);
            digitalWrite(FR_DIR_PIN, HIGH);
            digitalWrite(BL_DIR_PIN, HIGH);
            digitalWrite(BR_DIR_PIN, LOW);

            // Set the speed of all wheels
            ledcWrite(FL_CHANNEL, pwmValue);
            ledcWrite(FR_CHANNEL, pwmValue);
            ledcWrite(BL_CHANNEL, pwmValue);
            ledcWrite(BR_CHANNEL, pwmValue);
        }

        void turn(bool direction, double speed)
        {
            // Convert speed to PWM value (assuming speed is given in percentage)
            int pwmValue = map(speed, 0, 100, 0, 4095);
            if (direction)
            {    
                digitalWrite(FL_DIR_PIN, HIGH);
                digitalWrite(FR_DIR_PIN, LOW);
                digitalWrite(BL_DIR_PIN, HIGH);
                digitalWrite(BR_DIR_PIN, LOW);
            }
            else
            {
                digitalWrite(FL_DIR_PIN, LOW);
                digitalWrite(FR_DIR_PIN, HIGH);
                digitalWrite(BL_DIR_PIN, LOW);
                digitalWrite(BR_DIR_PIN, HIGH);
            }
            // Set the direction of all wheels to forward
           
            // Set the speed of all wheels

            ledcWrite(FL_CHANNEL, pwmValue);
            ledcWrite(FR_CHANNEL, pwmValue);
            ledcWrite(BL_CHANNEL, pwmValue);
            ledcWrite(BR_CHANNEL, pwmValue);
        } 
        
        void pwm_reset()
        {
            ledcWrite(FL_CHANNEL, 0);
            ledcWrite(FR_CHANNEL, 0);
            ledcWrite(BL_CHANNEL, 0);
            ledcWrite(BR_CHANNEL, 0);
        }

};
#endif