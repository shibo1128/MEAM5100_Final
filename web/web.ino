#include "html510.h"
#include "webpage.h"
HTML510Server h(80);
#define LEDPIN 4

const char* ssid     = "TP-Link_05AF";
const char* password = "47543454";

void handleRoot(){
  h.sendhtml(body);
}

void handleH(){
//  digitalWrite(LEDPIN, HIGH);  // LED ON
  neopixelWrite(2,20,0,0); // Red
  h.sendhtml(body);
}

void handleL(){
//  digitalWrite(LEDPIN, LOW);  // LED ON
  neopixelWrite(2,0, 20,0); // green
  h.sendhtml(body);
}

void setup() {
  IPAddress myIP(192,168,1,6);
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin(ssid, password);
  WiFi.config(myIP,IPAddress(192,168,1,1),
             IPAddress(255,255,255,0));
  while(WiFi.status()!= WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.printf("connected to %s on",ssid); Serial.println(myIP);
  
  h.begin();
  h.attachHandler("/H",handleH);
  h.attachHandler("/L",handleL);
  h.attachHandler("/ ",handleRoot);
}

void loop() {
  h.serve();
  delay(10);
}
