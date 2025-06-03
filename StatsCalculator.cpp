#include "StatsCalculator.h"
#include "ScheduleManager.h"
#include "Lesson.h"
#include "Classroom.h"

#include <QDateTime>

int StatsCalculator::countLessons() {

    return ScheduleManager::getInstance().getAllLessons().size();
}

int StatsCalculator::countFreeClassrooms(const QDate& date,
                                         const QTime& startTime,
                                         const QTime& endTime,
                                         const QList<Classroom>& allClassrooms)
{
    int freeCount = 0;
    QDateTime queryStart(date, startTime);
    QDateTime queryEnd(date, endTime);

    const QList<Lesson>& lessons = ScheduleManager::getInstance().getAllLessons();

    for (const Classroom& cls : allClassrooms) {
        bool occupied = false;
        for (const Lesson& lesson : lessons) {

            if (lesson.getStartTime().date() != date) {
                continue;
            }

            if (lesson.getClassroom().getId() != cls.getId()) {
                continue;
            }


            const QDateTime& ls = lesson.getStartTime();
            const QDateTime& le = lesson.getEndTime();
            if (queryStart < le && ls < queryEnd) {
                occupied = true;
                break;
            }
        }
        if (!occupied) {
            ++freeCount;
        }
    }
    return freeCount;
}
