#include "NetworkManager.h"

NetworkManager::NetworkManager(const char* ssid, const char* password) {
    _ssid = ssid;
    _password = password;
}

void NetworkManager::beginAP() {

}

IPAddress NetworkManager::getIP() {
    return WiFi.softAPIP();
}