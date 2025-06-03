#ifndef SCHEDULEDATABASE_H
#define SCHEDULEDATABASE_H

#include "Subject.h"
#include "Teacher.h"
#include "Group.h"
#include "Classroom.h"
#include <QList>

#include "Lesson.h"

class ScheduleDatabase {
public:
    ScheduleDatabase();

    QList<Subject> getSubjects() const;
    QList<Teacher> getTeachers() const;
    QList<Group> getGroups() const;
    QList<Classroom> getClassrooms() const;


    void saveLessons(const QList<Lesson>& lessons);
    QList<Lesson> loadLessons();

private:
    QList<Subject> m_subjects;
    QList<Teacher> m_teachers;
    QList<Group> m_groups;
    QList<Classroom> m_classrooms;


    void loadInitialData();
};

#endif
