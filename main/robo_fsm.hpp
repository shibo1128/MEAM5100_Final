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
        // 杨
        int pre_dist = 0;
        // 杨
        int at_corner1 = 0;
        enum Mission { WallFollowing, TrackingBeacon, WaitCmd, MissionComplete };
        enum state { Forward, Backward, TurnRight, TurnLeft, Move_Right, Move_left, Stop, Ready};
        state curstate;
        Mission curmission; 
        int FLPIN1 = 38; int FLPIN2 = 4; int FRPIN1 = 39; int FRPIN2 = 5;
        int BLPIN1 = 40; int BLPIN2 = 6; int BRPIN1 = 41; int BRPIN2 = 7;

        MecanumController* MC;  // not include yet
        pid* pid_ ; // not include yet

        bool wall_following_finish = false;

        double speed = 70;


        fsm(){};
        ~fsm(){};

        void initFsm(){
            curmission = WaitCmd;
            // while loop, give mission accoding to the web
            // while() receive mission
            // curmission = 
            // MC = new MecanumController(FLPIN1, FLPIN2, FRPIN1, FRPIN2,
            //                  BLPIN1, BLPIN2, BRPIN1, BRPIN2);
            MC = new MecanumController(38, 4, 11,
                                    39, 5, 12,
                                    40, 6, 13,
                                    41, 7, 14);
            pid_ = new pid(50.0, 0.0, 0.0, 0.0, 4095);
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

        // void checkyaw(){
        //     while(yaw >= 4 || yaw <= -4){
        //         MC->pwm_reset();
        //         if(yaw >= 4){
        //             MC->turn(0, speed);
        //         }
        //         if(yaw <= -4){
        //             MC->turn(1, speed);
        //         }
        //     }
        // }

        // void checkSideWall(){
        //     while(dist_2 < lower_threshold_to_side_wall){
        //         MC->pwm_reset();
        //         if(dist_2 < lower_threshold_to_side_wall){
        //             MC->move_left(speed);
        //             printf("left \n");
        //         }
        //         else{
        //             return;
        //         }
        //     }
        // }
        
 
        // void Wallfollowing_checkoffVersion(){
        //     // far away from wall
        //     //checkyaw();
        //     //checkSideWall();
        //     //checkyaw();

        //     if(!isClose1() && !isClose2()){
        //         MC->move_forward(speed);
        //         printf("forward \n");
        //         return;
        //     }

        //     // if close to front wall
        //     if(isClose1()){
        //         printf("stop \n");
        //         MC->pwm_reset();
        //         at_corner1++;
        //         //MC->turn(false, 50);
        //         //delay(1000);
        //         //if(at_corner1 == 6){
        //         delete MC;
        //         delete pid_;
        //         wall_following_finish = true;
        //         return;
        //         //}
        //     }
        // }  

};


#endif