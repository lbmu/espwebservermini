#pragma once
#include <WiFi.h>

class NetworkManager {
    private:
    const char* _ssid;
    const char* _password;

    public:
    NetworkManager(const char* ssid, const char* password);
    
    void beginAP();
    IPAddress getIP();

};