#include "TaskRoutes.h"

void registerTaskRoutes(AsyncWebServer& server, TaskManager& taskManager) {
    server.on("/api/tasks", HTTP_GET, [&taskManager](AsyncWebServerRequest *request) {
        request->send(200, "application/json", taskManager.toJson());
    });
}