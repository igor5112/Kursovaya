#include "Group.h"

Group::Group(int id, const QString& name, int studentCount)
    : m_id(id), m_name(name), m_studentCount(studentCount) {}

int Group::getId() const {
    return m_id;
}

QString Group::getName() const {
    return m_name;
}

int Group::getStudentCount() const {
    return m_studentCount;
}
