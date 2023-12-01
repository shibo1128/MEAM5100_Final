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
    pinMode(FL_DIR_PIN,OUTPUT);
    pinMode(FR_DIR_PIN,OUTPUT);
    pinMode(BL_DIR_PIN,OUTPUT);
    pinMode(BR_DIR_PIN,OUTPUT);

    ledcSetup(FL_CHANNEL,frequency,resolution);
    ledcAttachPin(FL_DIR_PIN,FL_CHANNEL);
    ledcSetup(FR_CHANNEL,frequency,resolution);
    ledcAttachPin(FR_DIR_PIN,FR_CHANNEL);
    ledcSetup(BL_CHANNEL,frequency,resolution);
    ledcAttachPin(BL_DIR_PIN,BL_CHANNEL);
    ledcSetup(BR_CHANNEL,frequency,resolution);
    ledcAttachPin(BR_DIR_PIN,BR_CHANNEL);
}

void MecanumController::move_forward(double speed)
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

void MecanumController::move_backward(double speed)
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

void MecanumController::move_right(double speed)
{
    // Convert speed to PWM value (assuming speed is given in percentage)
    int pwmValue = map(speed, 0, 100, 0, 4095);

    // Set the direction of all wheels to forward
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

void MecanumController::move_left(double speed)
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

void MecanumController::turn(bool direction, double speed)
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

void MecanumController::setPID(double Kp, double Ki, double Kd, double setpoint) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->setpoint = setpoint;
    integral = 0.0;
    last_error = 0.0;
}

double MecanumController::calculatePID(double current_distance) {
    double error = setpoint - current_distance;
    integral += error;
    double derivative = error - last_error;
    double output = Kp * error + Ki * integral + Kd * derivative;
    last_error = error;
    return output;
}