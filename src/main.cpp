#include <Arduino.h>
#include <ESPAsyncWebServer.h>

#include "secrets.h"
#include "NetworkManager.h"
#include "TaskManager.h"

NetworkManager myNetwork(ssid, password);

void setup() {
  Serial.begin(115200);
  
  if (myNetwork.beginAP()) {
    Serial.println("AP Sukses");
    Serial.print("[Network] IP Access Point: ");
    Serial.println(myNetwork.getIP());
  } 
  else Serial.println("AP Gagal");
  
}

void loop() {
  vTaskDelete(NULL);
}