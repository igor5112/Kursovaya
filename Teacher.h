#ifndef TEACHER_H
#define TEACHER_H

#include <QString>

class Teacher {
public:
    Teacher(int id, const QString& firstName, const QString& lastName);

    int getId() const;
    QString getFirstName() const;
    QString getLastName() const;
    QString getFullName() const;

private:
    int m_id;
    QString m_firstName;
    QString m_lastName;
};

#endif // TEACHER_H
