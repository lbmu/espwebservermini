#include <vector>
#include "TaskManager.h"

std::vector<TaskInfo> TaskManager::getAllTasks() {
    /* pakai buffer statis (_taskStatusBuffer) yang sudah
     * disediakan sebagai member, dipakai ulang tiap panggilan — 
     * menghindari alokasi heap berulang tiap kali endpoint /api/tasks 
     * di-poll dari frontend.
     * 
     * Alternatif "murni dinamis" (Strategi A) kalau nanti mau dicoba:
     * panggil uxTaskGetNumberOfTasks() dulu untuk tahu jumlah task
     * saat ini, lalu alokasikan array/vector persis seukuran itu
     * (misal via std::vector<TaskStatus_t> yang di-resize()).
     * Trade-off: alokasi ulang tiap request, tapi ukuran array
     * selalu pas dengan jumlah task aktual.
     */

    UBaseType_t taskCount = uxTaskGetSystemState(
    _taskStatusBuffer,
    MAX_TASKS,
    NULL
    );

    
    
}