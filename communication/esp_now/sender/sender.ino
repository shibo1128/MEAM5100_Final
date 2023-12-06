#include "esp_comm.h"

esp_now_peer_info_t peer1 = {
    .peer_addr = {0x68, 0x67, 0x25, 0x82, 0x41, 0xF4}, // receiver MAC address: 68:67:25:82:41:F4
    .channel = 1,
    .encrypt = false,
};



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
