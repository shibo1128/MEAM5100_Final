#include "html510.h"
#include "webpage.h"
#include "/Users/wangshibo/Desktop/MEAM5100_Final/sensor/IR.hpp"
#include "/Users/wangshibo/Desktop/MEAM5100_Final/actuators/motor.hpp"

const char* ssid = "TP-Link_E0C8";
const char* password = "52665134";

MecanumController mecanumController(38, 4, 11,
                                    39, 5, 12,
                                    40, 6, 13,
                                    41, 7, 14);

HTML510Server h(80);

void AP_setup(){
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
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