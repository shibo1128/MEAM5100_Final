#include "web_handle.h"



void setup() {
  
  Serial.begin(115200);
  AP_setup();
  web_server_setup();
}

void loop() {
  h.serve();
  delay(10);
}
