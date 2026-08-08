#pragma once

#include <WiFi.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

class NetworkManager {
    private:
    const char* _ssid;
    const char* _password;

    TaskHandle_t _networkTaskHandle;

    static void taskWrapper(void* _this);
    void taskLoop();

    public:
    NetworkManager(const char* ssid, const char* password);
    
    bool beginAP();
    IPAddress getIP(); // harusnya pake const, nanti cek lagi

};