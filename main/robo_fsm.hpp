/*
 * Finite state machines to manage all the lower-levels and 
 * control the action(mission) of robot
*/

#ifndef __FSM__
#define __FSM__

#include "../sensor/ultra.hpp"
#include "../sensor/imu.hpp"
#include "../basic/UDP.hpp"
#include "../sensor/vive.hpp"
#include "../actuators/motor.hpp"
#include "../utils/pid.h"



class fsm {
    public:
        
        int at_corner1 = 0;
        enum Mission { WallFollowing, TrackingBeacon, WaitCmd, MissionComplete };
        enum state { Forward, Backward, TurnRight, TurnLeft, Move_Right, Move_left, Stop, Ready};
        state curstate;
        Mission curmission;
        int FLPIN1 = 38; int FLPIN2 = 4; int FRPIN1 = 39; int FRPIN2 = 5;
        int BLPIN1 = 40; int BLPIN2 = 6; int BRPIN1 = 41; int BRPIN2 = 7;

        MecanumController* MC = new MecanumController(FLPIN1, FLPIN2, FRPIN1, FRPIN2,
                             BLPIN1, BLPIN2, BRPIN1, BRPIN2);  // not include yet
        pid* pid_ = new pid(50.0, 0.0, 0.0, 0.0, 4095); // not include yet


        fsm(){};
        ~fsm(){};

        void initFsm(){
            curmission = WaitCmd;
            // while loop, give mission accoding to the web
            // while() receive mission
            // curmission = 
            curstate = Ready;
        }

        // void Wallfollowing(){
        //     if(curmission != WallFollowing ){return;}\

        //     switch (curstate)
        //     {
        //     case Ready: // when starting moving
        //         if(isClose1() || isClose2()){
        //             MC.pwm_reset();
        //             curstate = Stop;
        //         }
        //         else{
        //             // pid + move forward
        //             curstate = Forward;
        //         }
        //         break;
        //     case Stop: // try to escape stop state
        //         if(isClose1() && !isClose2()){
        //             // pid + backward
        //             curstate = Backward;
        //         }
        //         else if(!isClose1() && isClose2()){
        //             // pid + Move_left
        //             curstate = Backward;    
        //         }

            
        //     default:
        //         break;
        //     }
        // }
        
 
        void Wallfollowing_checkoffVersion(){
            if(!isClose1() && !isClose2()){
                MC->move_forward(60);
                return;
            }
            if(!isClose1() && isClose2()){
                MC->pwm_reset();
                MC->move_left(30);
                delay(100);
                return;
            }
            if(isClose1()){
                MC->pwm_reset();
                if(isClose2()){
                    MC->move_left(30);
                    delay(100);
                }
                at_corner1++;
                MC->turn(false, 50);
                delay(1000);
                if(at_corner1 == 6){
                    delete MC;
                    delete pid_;
                    return;
                }
            }
        }


};


#endif