#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QList>

class Group {
public:
    Group(int id, const QString& name, int studentCount);

    int getId() const;
    QString getName() const;
    int getStudentCount() const;

private:
    int m_id;
    QString m_name;
    int m_studentCount;
};

#endif // GROUP_H
