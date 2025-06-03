#ifndef SCHEDULEMANAGER_H
#define SCHEDULEMANAGER_H

#include <QObject>
#include <QList>
#include <QDate>
#include <QTime>
#include "Lesson.h"
#include "Classroom.h"

class ScheduleObserver;

class ScheduleManager : public QObject {
    Q_OBJECT

public:
    static ScheduleManager& getInstance();

    bool addLesson(const Lesson& lesson);
    bool removeLesson(int lessonId);
    QList<Lesson> getAllLessons() const;


    QList<Classroom> findFreeClassrooms(const QDate& date,
                                        const QTime& startTime,
                                        const QTime& endTime,
                                        const QList<Classroom>& allClassrooms) const;
    QList<Lesson> getLessonsForGroup(int groupId) const;
    QList<Lesson> getLessonsForTeacher(int teacherId) const ;

    bool updateLesson(const Lesson& updatedLesson);

    void addObserver(ScheduleObserver* observer);
    void removeObserver(ScheduleObserver* observer);

signals:
    void scheduleChanged();

private:
    ScheduleManager();
    void notifyObservers();

    bool checkCollisions(const Lesson& newLesson) const;
    bool checkCollisionsForUpdate(const Lesson& lessonToCheck, int originalLessonId) const;

    QList<Lesson> m_lessons;
    QList<ScheduleObserver*> m_observers;
};

#endif
