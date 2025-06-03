#ifndef LESSON_H
#define LESSON_H

#include "Subject.h"
#include "Teacher.h"
#include "Group.h"
#include "Classroom.h"
#include <QDateTime>
#include <QList>


enum class LessonType {
    Lecture,     // Лекция
    Practical,   // Практика
    Laboratory   // Лабораторная
};

class Lesson {
public:
    Lesson(int id, const Subject& subject, const Teacher& teacher,
           const QList<Group>& groups, const Classroom& classroom,
           const QDateTime& startTime, const QDateTime& endTime, LessonType type);

    int getId() const;
    Subject getSubject() const;
    Teacher getTeacher() const;
    QList<Group> getGroups() const;
    Classroom getClassroom() const;
    QDateTime getStartTime() const;
    QDateTime getEndTime() const;

    bool collidesWith(const Lesson& other) const;
    LessonType getLessonType() const;

private:
    int m_id;
    Subject m_subject;
    Teacher m_teacher;
    QList<Group> m_groups;
    Classroom m_classroom;
    QDateTime m_startTime;
    QDateTime m_endTime;
    LessonType m_lessonType;
};

#endif // LESSON_H
