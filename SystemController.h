#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include <vector>
#include <string>
#include "RoomSearcher.h"  
#include "Classroom.h"
#include "ScheduleManager.h" 

class SystemController {
private:
    RoomSearcher roomSearcher; 
public:
    SystemController(const std::vector<Classroom>& rooms);

   
    std::vector<Classroom> getFreeRooms(const std::string &date, const TimeSlot &timeSlot) const;

    
    ScheduleManager& getScheduleManager();
};

#endif 
