/**
 * main loop for this project
*/
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "main/robo_fsm.hpp"

TaskHandle_t Task1, Task2, Task3;

// thread for reading 2 ultra sensors and one imu.
void TaskFunction1(void *pvParameters) {
  Init_IMU(-1);
  ultra_sensors_init(-1);
  VIVE_INIT();

  while (1) {   
    getYaw();
    getDistance1();
    getDistance2();
    //Getcoor();
    vTaskDelay(pdMS_TO_TICKS(5));  // 10ms延迟
  }
}

// thread for printing out sensor data
void TaskFunction2(void *pvParameters) {
  fsm f;
  delay(5000);
  while (1) {
    //Serial.print(xcoor); Serial.print(":"); Serial.println(ycoor); 
    f.Wallfollowing_checkoffVersion();
    vTaskDelay(pdMS_TO_TICKS(5));  // 10ms延迟
  }
}



void setup(){
    Serial.begin(115200);

    xTaskCreate(
    TaskFunction1,   // 任务1的函数
    "Task1",         // 任务1的名称
    15000,            // 堆栈大小
    NULL,            // 传递的参数
    5,               // 任务优先级
    &Task1           // 任务句柄
  );

  xTaskCreate(
    TaskFunction2,   // 任务2的函数
    "Task2",         // 任务2的名称
    10000,            // 堆栈大小
    NULL,            // 传递的参数
    5,               // 任务优先级
    &Task2           // 任务句柄
  );
}


void loop(){
 // Serial.println(yaw);
}