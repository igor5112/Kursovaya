#include "Classroom.h"

Classroom::Classroom(int id, const QString& name, int capacity)
    : m_id(id), m_name(name), m_capacity(capacity) {}

int Classroom::getId() const {
    return m_id;
}

QString Classroom::getName() const {
    return m_name;
}

int Classroom::getCapacity() const {
    return m_capacity;
}
