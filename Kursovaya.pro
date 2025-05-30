QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddLessonDialog.cpp \
    Classroom.cpp \
    Group.cpp \
    Lesson.cpp \
    RoomSearcher.cpp \
    Schedule.cpp \
    ScheduleManager.cpp \
    Subject.cpp \
    SystemController.cpp \
    Teacher.cpp \
    TimeSlot.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AddLessonDialog.h \
    Classroom.h \
    Group.h \
    Lesson.h \
    RoomSearcher.h \
    RoomSearcher_копия.h \
    Schedule.h \
    ScheduleManager.h \
    Subject.h \
    SystemController.h \
    Teacher.h \
    TimeSlot.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
