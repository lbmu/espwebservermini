#include "NetworkManager.h"

NetworkManager::NetworkManager(const char* ssid, const char* password) {
    _ssid = ssid;
    _password = password;
    _networkTaskHandle = NULL;
}

bool NetworkManager::beginAP() {
    Serial.println("AP Initializing...");

    IPAddress local_ip(192, 168, 1, 254);
    IPAddress gateway(192, 168, 1, 254);
    IPAddress subnet(255, 255, 255, 0);
    WiFi.softAPConfig(local_ip, gateway, subnet);

    if (_networkTaskHandle != NULL) {
        Serial.println("udah jalan");
        return false;
    } 

    if (_ssid == nullptr || strlen(_ssid) == 0) {
        Serial.println("ssid kosong");
        return false;
    }

    WiFi.mode(WIFI_AP);
    if (!WiFi.softAP(_ssid, _password)) {
        Serial.println("softAP gagal");
        return false;
    }

    BaseType_t result = xTaskCreatePinnedToCore(
        NetworkManager::taskWrapper,
        "NetworkTask",
        4096,
        this,
        1,
        &_networkTaskHandle,
        1
    );

    if (result != pdPASS) {
        Serial.println("gagal init task monitor");
        return false;
    }

    Serial.println("Berhasil inisialisasi");
    return true;
}

void NetworkManager::taskWrapper(void* _this) {
    NetworkManager* instance = static_cast<NetworkManager*>(_this);
    instance->taskLoop();
}

void NetworkManager::taskLoop() {
    for(;;) {
        uint8_t clientCount = WiFi.softAPgetStationNum();
        Serial.printf("[Network Task] Klien terhubung: %d\n", clientCount);
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}

IPAddress NetworkManager::getIP() {
    return WiFi.softAPIP();
}