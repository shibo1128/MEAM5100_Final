#include "comm_all_in_one.hpp"



void setup() {
  Serial.begin(115200);
  wifi_setup();
  web_server_setup();
}

void loop() {
  static long int ms = millis();
  h.serve();
  delay(10);
  send_via_esp_now("test");


  if (millis()-ms>1000/FREQ) {
    //ms = millis();
    //x = (x_front + x_back)/2;
    //y = (y_front + y_back)/2;
    //if (WiFi.status()==WL_CONNECTED)
    //    neopixelWrite(RGBLED,255,255,255);  // full white
    UdpSend(1, 1);
  }


  traget target_coordinates = handleUDPServer();
  int target_x = target_coordinates.x;
  int target_y = target_coordinates.y;
  int team_number = target_coordinates.team;
  if (target_x != 0 && target_y != 0)
  {
    Serial.println("team_number");
    Serial.println(team_number);
    Serial.println("target_x");
    Serial.println(target_x);
    Serial.println("target_y");
    Serial.println(target_y);
  }
}
