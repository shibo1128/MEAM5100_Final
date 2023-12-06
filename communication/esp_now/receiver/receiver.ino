#include <esp_now.h>
#include <WiFi.h>
// callback on receive
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) 
{ 
    Serial.print(" Data: ");
    Serial.println( (char *)data); // assume data is ascii string 
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    Serial.print("ESPNow Receiving MAC: "); Serial.println(WiFi.macAddress());
    if (esp_now_init() != ESP_OK) 
    {
        Serial.println("ESPNow Init Failed");
    }
    esp_now_register_recv_cb(OnDataRecv); 
    }

void loop() { }