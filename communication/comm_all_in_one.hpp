#include "html510.h"
#include "webpage.h"
#include <esp_now.h>
#include "/Users/wangshibo/Desktop/MEAM5100_Final/sensor/IR.hpp"
#include "/Users/wangshibo/Desktop/MEAM5100_Final/actuators/motor.hpp"

#define UDPPORT 2510 // For GTA 2022C game
#define teamNumber 37
#define FREQ 1 // in Hz

const char* router_ssid = "TP-Link_E0C8";
const char* router_password = "52665134";
const char* ap_ssid = "ESP32-Access-Mode";
const char* ap_password = "12345678";

MecanumController mecanumController(38, 4, 11,
                                    39, 5, 12,
                                    40, 6, 13,
                                    41, 7, 14);

HTML510Server h(80);

IPAddress ipTarget(192, 168, 1, 255); // 255 => broadcast

WiFiUDP udp;

esp_now_peer_info_t ta_esp = {
    .peer_addr = {0x68, 0x67, 0x25, 0x82, 0x41, 0xF4}, // receiver MAC address: 68:67:25:82:41:F4
    .channel = 1,
    .encrypt = false,
};

struct traget {
    int x;
    int y;
    int team;
};

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) 
{ 
    if (status == ESP_NOW_SEND_SUCCESS) Serial.println ("Success ");
    else Serial.println("Fail "); 
}

void wifi_setup()
{
    WiFi.mode(WIFI_AP_STA);

    //Setup AP
    WiFi.softAP(ap_ssid, ap_password);
    Serial.println("Access Point Started");
    Serial.print("AP IP Address: ");
    Serial.println(WiFi.softAPIP());

    //Connect to router
    WiFi.config(IPAddress(192, 168, 1, 209), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
    WiFi.begin(router_ssid, router_password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to Router, IP address: ");
    Serial.println(WiFi.localIP());

    //Start up UDP
    udp.begin(UDPPORT);
    Serial.printf("Listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), UDPPORT);

    // Initialize ESP-NOW
    if (esp_now_init() != 0) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_register_send_cb(OnDataSent); //optional send callback 
    if (esp_now_add_peer(&ta_esp) != ESP_OK) 
    { // must add peer to send
        Serial.println("Pair failed"); while (1) ; // stop 
    }

}



void handleRoot(){
  h.sendhtml(body);
}

void handleWallFollowing(){
//  digitalWrite(LEDPIN, HIGH);  // LED ON
  printf("wall following mode\n");
  h.sendhtml(body);
}

void handleTrophyFinding(){
//  digitalWrite(LEDPIN, LOW);  // LED ON
  printf("finding trophy mode\n");
  
  if (senseBeacon() == 550){
    mecanumController.move_forward(70);
  }
  else{mecanumController.turn(1,70);}
  h.sendhtml(body);
}

void handleFakeFinding(){
//  digitalWrite(LEDPIN, LOW);  // LED ON
  printf("finding fake mode\n");
  h.sendhtml(body);
}

void handleTesting(){
//  digitalWrite(LEDPIN, LOW);  // LED ON
  printf("testing mode\n");
  h.sendhtml(body);
}

void handlePush(){
//  digitalWrite(LEDPIN, LOW);  // LED ON
  printf("Push police mode\n");
  h.sendhtml(body);
}

void web_server_setup(){  
    h.begin();
    h.attachHandler("/wall",handleWallFollowing);
    h.attachHandler("/trophy",handleTrophyFinding);
    h.attachHandler("/fake",handleFakeFinding);
    h.attachHandler("/test",handleTesting);
    h.attachHandler("/push",handlePush);
    h.attachHandler("/ ",handleRoot);
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

void UdpSend(int x, int y)
{
  char udpBuffer[20];
  sprintf(udpBuffer, "%02d:%4d,%4d",teamNumber,x,y);   
                                              
  udp.beginPacket(ipTarget, UDPPORT);
  udp.println(udpBuffer);
  udp.endPacket();
  //Serial.println(udpBuffer);
}

struct traget handleUDPServer() {
  struct traget target_coordinates;
  const int UDP_PACKET_SIZE = 14; // can be up to 65535          
  uint8_t packetBuffer[UDP_PACKET_SIZE];

  int cb = udp.parsePacket(); // if there is no message cb=0
  if (cb) {
    packetBuffer[13]=0; // null terminate string

    udp.read(packetBuffer, UDP_PACKET_SIZE);
    target_coordinates.team = atoi((char *)packetBuffer+0);
    target_coordinates.x = atoi((char *)packetBuffer+3); // ##,####,#### 2nd indexed char
    target_coordinates.y = atoi((char *)packetBuffer+8); // ##,####,#### 7th indexed char
    return target_coordinates;
  }
}