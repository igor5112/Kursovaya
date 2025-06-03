#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <QString>

class Classroom {
public:
    Classroom(int id, const QString& name, int capacity);

    int getId() const;
    QString getName() const;
    int getCapacity() const;

private:
    int m_id;
    QString m_name;
    int m_capacity;
};

#endif // CLASSROOM_H
