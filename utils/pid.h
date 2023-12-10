/*
 *  header file for implementing position PID controller
 *
*/

class pid
{
    private:
        float kp, ki, kd;
        float target;
        int PWM, max_pwm; // output
        float cur_err, prev_err, cur_integral;

    public:
        pid(float pid_kp, float pid_ki, float pid_kd, float tar, int mp);
        ~pid();   // remember to kill in the end
        
        void set_param(float pid_kp, float pid_ki, float pid_kd, float tar){
            kp = pid_kp;
            ki = pid_ki;
            kd = pid_kd;
            target = tar;
        }
        void set_target(float tar){target = tar;}
        int get_output(){return PWM;}
        float get_kp(){return kp;}
        float get_ki(){return ki;}
        float get_kd(){return kd;}

        int POS_PID(float fb, float target1);
        void pid_reset(){
          target = 0;
          cur_err=0; prev_err=0; cur_integral=0;
        }
        int get_integral(){return cur_integral;}
};


// init controller
pid::pid(float pid_kp, float pid_ki, float pid_kd, float tar, int mp)
{
    kp = pid_kp;
    ki = pid_ki;
    kd = pid_kd;
    target = tar;
    PWM = 0;
    cur_err = 0;
    prev_err = 0;
    cur_integral = 0;
    max_pwm = mp;
}


pid::~pid(){}


// calculate the control input, put it in a loop with feedback update
int pid::POS_PID(float fb, float target1){
    cur_err = target1 - fb;
    cur_integral += cur_err;
    PWM = kp * cur_err + ki * cur_integral + kd * (cur_err - prev_err);
    prev_err = cur_err;
    PWM = (PWM > max_pwm) ? max_pwm:PWM;
    PWM = (PWM < -max_pwm) ? -max_pwm:PWM;
    return PWM;
}



