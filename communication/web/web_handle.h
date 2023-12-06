#include "html510.h"
#include "webpage.h"

const char* ssid = "ESP32-Access-Point";
const char* password = "12345678";

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

void web_server_setup(){  
    h.begin();
    h.attachHandler("/wall",handleWallFollowing);
    h.attachHandler("/trophy",handleTrophyFinding);
    h.attachHandler("/fake",handleFakeFinding);
    h.attachHandler("/test",handleTesting);
    h.attachHandler("/ ",handleRoot);
}