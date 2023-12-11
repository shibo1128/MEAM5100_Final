#include "esp_comm.h"





void setup() 
{ 
    Serial.begin(115200);
    // channel can be 1 to 14, channel 0 means current channel.
    setup_esp_now();
}

void loop() {
    send_via_esp_now("test");
    delay(100);
}
