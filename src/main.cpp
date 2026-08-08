#include <Arduino.h>
#include <ESPAsyncWebServer.h>

#include "secrets.h"
#include "NetworkManager.h"

NetworkManager myNetwork(ssid, password);
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  myNetwork.beginAP();
  Serial.print("[Network] IP Access Point: ");
  Serial.println(myNetwork.getIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hello OOP World! Infrastruktur kode ini sudah solid.");
  });

  server.begin();
  Serial.println("[Server] HTTP Server berjalan di latar belakang.");
  
}

void loop() {
  
}