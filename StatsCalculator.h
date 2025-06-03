#ifndef STATSCALCULATOR_H
#define STATSCALCULATOR_H

#include <QList>
#include <QDate>
#include <QTime>

class Lesson;
class Classroom;


class StatsCalculator {
public:

    static int countLessons();

    static int countFreeClassrooms(const QDate& date,
                                   const QTime& startTime,
                                   const QTime& endTime,
                                   const QList<Classroom>& allClassrooms);
};

#endif // STATSCALCULATOR_H
