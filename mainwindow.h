#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QComboBox>

#include "ScheduleManager.h"
#include "ScheduleObserver.h"
#include "ScheduleDatabase.h"
#include "Lesson.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public ScheduleObserver {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void updateSchedule() override;

private slots:
    void on_addLessonButton_clicked();
    void on_removeLessonButton_clicked();
    void on_findFreeClassroomsButton_clicked();
    void displayAllLessons(); // Обновление списка занятий
    void on_editLessonButton_clicked();
    void on_showStatsButton_clicked();


private:
    Ui::MainWindow *ui;
    ScheduleManager& m_scheduleManager;
    ScheduleDatabase m_database;


    QLineEdit* m_lessonIdInput;
    QComboBox* m_subjectComboBox;
    QComboBox* m_teacherComboBox;
    QComboBox* m_groupComboBox;
    QComboBox* m_classroomComboBox;
    QDateTimeEdit* m_startTimeEdit;
    QDateTimeEdit* m_endTimeEdit;
    QListWidget* m_scheduleListWidget;
    QListWidget* m_freeClassroomsListWidget;
    QComboBox* m_lessonTypeComboBox;
    QPushButton* m_editLessonButton;


    void setupUiElements();
    void populateComboBoxes();
    void refreshLessonList();
    void refreshFreeClassroomsList(const QList<Classroom>& classrooms);
};
#endif
