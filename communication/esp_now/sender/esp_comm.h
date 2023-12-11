#include <esp_now.h>
#include <WiFi.h>

esp_now_peer_info_t ta_esp = {
    .peer_addr = {0x68, 0x67, 0x25, 0x82, 0x41, 0xF4}, // receiver MAC address: 68:67:25:82:41:F4
    .channel = 1,
    .encrypt = false,
};

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) 
{ 
    if (status == ESP_NOW_SEND_SUCCESS) Serial.println ("Success ");
    else Serial.println("Fail "); 
}

void setup_esp_now(){
    WiFi.mode(WIFI_AP_STA);
    Serial.print("STA MAC: "); 
    Serial.println(WiFi.macAddress()); 

    if (esp_now_init() != ESP_OK) {
        Serial.println("init failed"); while (1) ; // stop 
    }
    esp_now_register_send_cb(OnDataSent); //optional send callback 
    if (esp_now_add_peer(&ta_esp) != ESP_OK) 
    { // must add peer to send
        Serial.println("Pair failed"); while (1) ; // stop 
    }
}

void send_via_esp_now(char *msg){
    uint8_t message[200];
    sprintf((char *) message, msg);
    if (esp_now_send(ta_esp.peer_addr, message, sizeof(message))==ESP_OK) 
    {
      Serial.printf("Sent '%s' to %x:%x:%x:%x:%x:%x \n", 
                    message,ta_esp.peer_addr[0],ta_esp.peer_addr[1],
                    ta_esp.peer_addr[2],ta_esp.peer_addr[3],ta_esp.peer_addr[4],ta_esp.peer_addr[5]);
    }
    else Serial.println("Send failed"); 
}