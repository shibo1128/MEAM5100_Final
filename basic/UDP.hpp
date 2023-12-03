/**
 * basic UDP function for ESP32, 
 * including UDP init, UDP setup, and parameter, function define
*/

#ifndef __UDP__
#define __UDP__

#include <WiFi.h>
#include <WiFiUdp.h>

#define teamNumber = 37
#define UDPPORT 2510 // For GTA 2022C game, change to 2023 port
#define STUDENTIP 123 // choose a teammembers assigned IP numbers
#define FREQ 1

// change to your own
const char* ssid     = "TP-Link_05AF";
const char* password = "47543454";
WiFiUDP UDPTestServer;
IPAddress ipTarget(192, 168, 1, 255); // 255 => broadcast


void INIT_UDP(){
    int i = 0;
    WiFi.mode(WIFI_AP_STA);
    WiFi.config(IPAddress(192, 168, 1, STUDENTIP), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
    WiFi.begin(ssid, password);

    Serial.printf("team  #%d ", teamNumber); 
    Serial.print("Connecting to ");  Serial.println(ssid);
    while(WiFi.status()!=WL_CONNECTED && i++ < 20){
        delay(500);   Serial.print(".");
    }
    if (i<19) {
        Serial.println("WiFi connected as "); Serial.print(WiFi.localIP());
    } else {
        Serial.printf("Could not connect err: %d ",i); 
    }
    
    UDPTestServer.begin(UDPPORT);
}


void UdpSendCoor(int x, int y)
{
  char udpBuffer[20];
  sprintf(udpBuffer, "%02d:%4d,%4d",teamNumber,x,y);   
                                              
  UDPTestServer.beginPacket(ipTarget, UDPPORT);
  UDPTestServer.println(udpBuffer);
  UDPTestServer.endPacket();
  Serial.println(udpBuffer);
}

// receive the car coordinate
void UdpRevCoor(){

}


#endif