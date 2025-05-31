#include "Teacher.h"

Teacher::Teacher(int id, const std::string &name)
    : teacherID(id), name(name)
{}

int Teacher::getTeacherID() const {
    return teacherID;
}

std::string Teacher::getName() const {
    return name;
}
