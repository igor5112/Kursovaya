#include "Subject.h"

Subject::Subject(int id, const std::string &title)
    : subjectID(id), title(title)
{}

int Subject::getSubjectID() const {
    return subjectID;
}

std::string Subject::getTitle() const {
    return title;
}

