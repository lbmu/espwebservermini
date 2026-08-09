#pragma once
#include <ESPAsyncWebServer.h>

#include "TaskManager.h"

void registerTaskRoutes(AsyncWebServer& server, TaskManager& taskManager);
