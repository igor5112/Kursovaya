#ifndef SCHEDULEOBSERVER_H
#define SCHEDULEOBSERVER_H

class ScheduleObserver {
public:
    virtual ~ScheduleObserver() = default;
    virtual void updateSchedule() = 0;
};

#endif
