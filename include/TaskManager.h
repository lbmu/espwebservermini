#pragma once

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

class TaskManager{
    private:

    static const UBaseType_t MAX_TASKS = 32;
    TaskStatus_t _taskStatusBuffer[MAX_TASKS];
    
    public:
    struct TaskInfo {
        String name;
        UBaseType_t priority;
        eTaskState state;
        uint32_t stackHighWaterMark;

    };
    
    
};