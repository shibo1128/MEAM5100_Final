/**
 * main loop for this project
*/
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "main/robo_fsm.hpp"

// TaskHandle_t Task1, Task2, Task3;

// // thread for reading 2 ultra sensors and one imu.
// void TaskFunction1(void *pvParameters) {
//   //delay(4000);
//   //Init_IMU(-1);
//   ultra_sensors_init(-1);
//   while (1) {   
//     //getYaw();
//     getDistance1();
//     getDistance2();
//     //printf("%f : %f\n",dist_1, dist_2);
//     vTaskDelay(pdMS_TO_TICKS(5));  // 10ms延迟
//   }
// }

// // thread for printing out sensor data
// void TaskFunction2(void *pvParameters) {
//   fsm f;  
//   f.initFsm();
//   delay(2000);
//   while (1) {
//     f.Wallfollowing_checkoffVersion();
//     vTaskDelay(pdMS_TO_TICKS(5));  // 10ms延迟
//   }
// }



// void setup(){
//     Serial.begin(115200);

//     xTaskCreate(
//     TaskFunction1,   // 任务1的函数
//     "Task1",         // 任务1的名称
//     20000,            // 堆栈大小
//     NULL,            // 传递的参数
//     5,               // 任务优先级
//     &Task1           // 任务句柄
//   );

//   xTaskCreate(   
//     TaskFunction2,   // 任务2的函数
//     "Task2",         // 任务2的名称
//     30000,            // 堆栈大小
//     NULL,            // 传递的参数
//     4,               // 任务优先级
//     &Task2           // 任务句柄
//   );
// }
double speed = 70;
fsm f;   
float d1,d2,y;

/*
 * 

*/


void setup(){
  Serial.begin(115200);
  ultra_sensors_init(-1);
  Init_IMU(-1);
  f.initFsm();
  delay(200);
}


int count = 0;
void loop(){
    y = getYaw();
    if(y > 0.5){
      f.MC->move_forward(speed, 10.0, -10.0);
    }else if(y < -0.5){
      f.MC->move_forward(speed, -10.0, 10.0);
    }
    else{
       f.MC->move_forward(speed, 0.0, 0.0);
    }
    delay(10);
    count++;
    if(count >= 100000){
      count = 0;
      IMU_RESET();
    }
    printf("yaw: %f, count: %d \n", y, count);

    //pid
    // y = getYaw();
    // float del = .pid_->POS_PID(y, 0.0f);
    // f.MC->move_forward_pid(speed, del, del);
    //f.MC->move_forward(speed);
    // d1 = min(getDistance1(), 25.0f);
    // d2 = min(getDistance2(), 25.0f);
    // printf("%f : %f\n",d1, d2);


    // if(d1 > 10 && d2 < 12){
    //     f.MC->move_left(speed);
    //     printf("left \n");
    // }
            
    //  if(d1 > 10 && d2 >= 12){
    //     f.MC->move_forward(speed);
    //     printf("forward \n");
    //  }

    //   // if close to front wall
    //   if(d1 <= 10){
    //       printf("stop \n");
    //       f.MC->pwm_reset();
    //       //at_corner1++;
    //       f.MC->turn(false, speed);
    //       delay(500);
    //       //if(at_corner1 == 6){
    //       // delete MC;
    //       // delete pid_;     
    //       //wall_following_finish = true;
    //       //}
    //   }
    //   delay(5);
}