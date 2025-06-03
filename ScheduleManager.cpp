#include "ScheduleManager.h"
#include "ScheduleObserver.h"
#include "ScheduleManager.h"
#include <QDateTime>
#include <QDebug>

ScheduleManager& ScheduleManager::getInstance() {
    static ScheduleManager instance;
    return instance;
}

bool ScheduleManager::addLesson(const Lesson& lesson) {


    for (const Lesson& existingLesson : m_lessons) {
        if (existingLesson.getId() == lesson.getId()) {
            qWarning() << "Ошибка: Занятие с ID " << lesson.getId() << " уже существует. addLesson returning FALSE.";
            return false;
        }
    }

    if (checkCollisions(lesson)) {
        qWarning() << "Ошибка: Обнаружены коллизии при добавлении занятия. addLesson returning FALSE.";
        return false;
    }
    m_lessons.append(lesson);

    emit scheduleChanged();
    notifyObservers();
    return true;
}

ScheduleManager::ScheduleManager()
    : QObject(nullptr)
{

}

bool ScheduleManager::removeLesson(int lessonId) {

    for (int i = 0; i < m_lessons.size(); ++i) {
        if (m_lessons[i].getId() == lessonId) {
            m_lessons.removeAt(i);

            emit scheduleChanged();
            notifyObservers();
            return true;
        }
    }

    return false;
}

QList<Lesson> ScheduleManager::getAllLessons() const {
    return m_lessons;
}

QList<Lesson> ScheduleManager::getLessonsForGroup(int groupId) const {
    QList<Lesson> groupLessons;
    for (const Lesson& lesson : m_lessons) {
        for (const Group& group : lesson.getGroups()) {
            if (group.getId() == groupId) {
                groupLessons.append(lesson);
                break;
            }
        }
    }
    return groupLessons;
}

QList<Lesson> ScheduleManager::getLessonsForTeacher(int teacherId) const {
    QList<Lesson> teacherLessons;
    for (const Lesson& lesson : m_lessons) {
        if (lesson.getTeacher().getId() == teacherId) {
            teacherLessons.append(lesson);
        }
    }
    return teacherLessons;
}




QList<Classroom> ScheduleManager::findFreeClassrooms(const QDate& date,
                                                     const QTime& startTime,
                                                     const QTime& endTime,
                                                     const QList<Classroom>& allClassrooms) const
{
    QList<Classroom> freeList;
    QDateTime queryStart(date, startTime);
    QDateTime queryEnd(date, endTime);

    for (const Classroom& cls : allClassrooms) {
        bool occupied = false;
        for (const Lesson& lesson : m_lessons) {

            if (lesson.getStartTime().date() != date) continue;

            if (lesson.getClassroom().getId() != cls.getId()) continue;


            const QDateTime& ls = lesson.getStartTime();
            const QDateTime& le = lesson.getEndTime();
            if (queryStart < le && ls < queryEnd) {
                occupied = true;
                break;
            }
        }
        if (!occupied) {
            freeList.append(cls);
        }
    }
    return freeList;
}






bool ScheduleManager::checkCollisions(const Lesson& newLesson) const {


    for (const Lesson& existingLesson : m_lessons) {

        if (newLesson.getId() == existingLesson.getId()) {

            continue;
        }


        if (!(newLesson.getStartTime() < existingLesson.getEndTime() &&
              newLesson.getEndTime() > existingLesson.getStartTime())) {

            continue;
        }



        bool isNewLecture      = (newLesson.getLessonType() == LessonType::Lecture);
        bool isExistingLecture = (existingLesson.getLessonType() == LessonType::Lecture);

        if (!isNewLecture && !isExistingLecture) {

            if ( newLesson.getClassroom().getId() == existingLesson.getClassroom().getId() ) {

                return true;
            }
        }



        if (newLesson.getLessonType() != LessonType::Lecture) {
            if (newLesson.getTeacher().getId() == existingLesson.getTeacher().getId()) {

                return true;
            }
        }

        bool hasCommonGroup = false;
        for (const Group& newGroup : newLesson.getGroups()) {
            for (const Group& existingGroup : existingLesson.getGroups()) {
                if (newGroup.getId() == existingGroup.getId()) {
                    hasCommonGroup = true;

                    break;
                }
            }
            if (hasCommonGroup) break;
        }

        if (hasCommonGroup) {

            if (isNewLecture || isExistingLecture) {

                continue;
            }



            return true;
        }


    }


    return false;
}


void ScheduleManager::addObserver(ScheduleObserver* observer) {
    m_observers.append(observer);

}

void ScheduleManager::removeObserver(ScheduleObserver* observer) {
    m_observers.removeOne(observer);

}

void ScheduleManager::notifyObservers() {

    for (ScheduleObserver* observer : m_observers) {
        if (observer) {
            observer->updateSchedule();
        }
    }
}


bool ScheduleManager::checkCollisionsForUpdate(const Lesson& lessonToCheck, int originalLessonId) const {


    for (const Lesson& existingLesson : m_lessons) {
        if (existingLesson.getId() == originalLessonId) {

            continue;
        }


        if (!(lessonToCheck.getStartTime() < existingLesson.getEndTime() &&
              lessonToCheck.getEndTime()   > existingLesson.getStartTime())) {
            continue;
        }



        bool isNewLecture      = (lessonToCheck.getLessonType() == LessonType::Lecture);
        bool isExistLecture    = (existingLesson.getLessonType()  == LessonType::Lecture);
        if (!isNewLecture && !isExistLecture) {
            if (lessonToCheck.getClassroom().getId() == existingLesson.getClassroom().getId()) {

                return true;
            }
        }


        if (lessonToCheck.getTeacher().getId() == existingLesson.getTeacher().getId()) {

            return true;
        }


        bool hasCommonGroup = false;
        for (const Group& g1 : lessonToCheck.getGroups()) {
            for (const Group& g2 : existingLesson.getGroups()) {
                if (g1.getId() == g2.getId()) {
                    hasCommonGroup = true;

                    break;
                }
            }
            if (hasCommonGroup) break;
        }
        if (hasCommonGroup) {

            if (!isNewLecture || !isExistLecture) {

                return true;
            }


        }
    }


    return false;
}



bool ScheduleManager::updateLesson(const Lesson& updatedLesson) {
    int origId = updatedLesson.getId();
    int indexToUpdate = -1;


    for (int i = 0; i < m_lessons.size(); ++i) {
        if (m_lessons[i].getId() == origId) {
            indexToUpdate = i;
            break;
        }
    }
    if (indexToUpdate < 0) {
        qWarning() << "Ошибка: Не найдено занятие с ID" << origId
                   << ". updateLesson возвращает FALSE.";
        return false;
    }


    Lesson oldLesson = m_lessons[indexToUpdate];

    m_lessons[indexToUpdate] = updatedLesson;


    if (checkCollisionsForUpdate(updatedLesson, origId)) {

        m_lessons[indexToUpdate] = oldLesson;
        qWarning() << "Ошибка: Обнаружены коллизии при обновлении занятия. updateLesson возвращает FALSE.";
        return false;
    }


    emit scheduleChanged();
    notifyObservers();
    return true;
}
