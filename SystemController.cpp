#include "SystemController.h"

SystemController::SystemController(const std::vector<Classroom>& rooms)
    : roomSearcher(rooms) 
{
    
}

std::vector<Classroom> SystemController::getFreeRooms(const std::string &date, const TimeSlot &timeSlot) const {
    return roomSearcher.findFreeRooms(date, timeSlot);
}

ScheduleManager& SystemController::getScheduleManager() {
    return *ScheduleManager::getInstance();
}
