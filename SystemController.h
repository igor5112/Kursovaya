#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include <vector>
#include <string>
#include "RoomSearcher.h"  // Предполагается, что этот класс есть
#include "Classroom.h"
#include "ScheduleManager.h" // Нужен для доступа к расписанию

class SystemController {
private:
    RoomSearcher roomSearcher;  // Объект поиска аудиторий
public:
    SystemController(const std::vector<Classroom>& rooms);

    // Метод для получения свободных аудиторий
    std::vector<Classroom> getFreeRooms(const std::string &date, const TimeSlot &timeSlot) const;

    // Возвращает ссылку на единственный экземпляр ScheduleManager
    ScheduleManager& getScheduleManager();
};

#endif // SYSTEMCONTROLLER_H
