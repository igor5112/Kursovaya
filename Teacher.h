#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher {
private:
    int teacherID;
    std::string name;
public:
    Teacher(int id, const std::string &name);
    int getTeacherID() const;
    std::string getName() const;
};

#endif // TEACHER_H
