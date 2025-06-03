#include "Teacher.h"

Teacher::Teacher(int id, const QString& firstName, const QString& lastName)
    : m_id(id), m_firstName(firstName), m_lastName(lastName) {}

int Teacher::getId() const {
    return m_id;
}

QString Teacher::getFirstName() const {
    return m_firstName;
}

QString Teacher::getLastName() const {
    return m_lastName;
}

QString Teacher::getFullName() const {
    return m_firstName + " " + m_lastName;
}
