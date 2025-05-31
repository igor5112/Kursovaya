#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject {
private:
    int subjectID;
    std::string title;
public:
    Subject(int id, const std::string &title);
    int getSubjectID() const;
    std::string getTitle() const;

};

#endif // SUBJECT_H
