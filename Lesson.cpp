#include "Lesson.h"

Lesson::Lesson(int id, const Subject& subject, const Teacher& teacher,
               const QList<Group>& groups, const Classroom& classroom,
               const QDateTime& startTime, const QDateTime& endTime, LessonType type)
    : m_id(id), m_subject(subject), m_teacher(teacher),
    m_groups(groups), m_classroom(classroom),
    m_startTime(startTime), m_endTime(endTime),
    m_lessonType(type) {}

int Lesson::getId() const {
    return m_id;
}

Subject Lesson::getSubject() const {
    return m_subject;
}

Teacher Lesson::getTeacher() const {
    return m_teacher;
}

QList<Group> Lesson::getGroups() const {
    return m_groups;
}

Classroom Lesson::getClassroom() const {
    return m_classroom;
}

QDateTime Lesson::getStartTime() const {
    return m_startTime;
}

QDateTime Lesson::getEndTime() const {
    return m_endTime;
}

LessonType Lesson::getLessonType() const {
    return m_lessonType;
}


bool Lesson::collidesWith(const Lesson& other) const {
    // Проверка на пересечение по времени
    if (!(m_startTime < other.m_endTime && m_endTime > other.m_startTime)) {
        return false;
    }


    if (m_classroom.getId() == other.m_classroom.getId()) {
        return true;
    }


    if (m_teacher.getId() == other.m_teacher.getId()) {
        return true;
    }


    return false;
}
