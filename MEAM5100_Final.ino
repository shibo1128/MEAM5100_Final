/**
 * main loop for this project
*/
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "sensor/ultra.hpp"
#include "sensor/imu.hpp"

TaskHandle_t Task1, Task2, Task3;

// thread for reading 2 ultra sensors and one imu.
void TaskFunction1(void *pvParameters) {
  Init_IMU(-1);
  ultra_sensors_init(-1);
  while (1) {
    getYaw();
    getDistance1();
    vTaskDelay(pdMS_TO_TICKS(10));  // 10ms延迟
  }
}

// thread for printing out sensor data
void TaskFunction2(void *pvParameters) {
  while (1) {
    Serial.print(yaw); Serial.print(":"); Serial.println(dist_1); 
    vTaskDelay(pdMS_TO_TICKS(200));  // 10ms延迟
  }
}

// process WHATEVER
void TaskFunction3(void *pvParameters) {
  while (1) {
    if(dist_1 <= 3){
      Serial.println("TOO CLOSE -------- !");
    }
    if(yaw >= 20 || yaw <= -20){
      Serial.println("BIG ROTATING  -------- !");
    }

    vTaskDelay(pdMS_TO_TICKS(50));  // 10ms延迟
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
    1000,            // 堆栈大小
    NULL,            // 传递的参数
    3,               // 任务优先级
    &Task2           // 任务句柄
  );

  xTaskCreate(
    TaskFunction3,   // 任务2的函数
    "Task3",         // 任务2的名称
    2000,            // 堆栈大小
    NULL,            // 传递的参数
    4,               // 任务优先级
    &Task3           // 任务句柄
  );
}


void loop(){
 // Serial.println(yaw);
}