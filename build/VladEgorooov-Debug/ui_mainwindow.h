/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *scheduleTableWidget;
    QPushButton *addLessonButton;
    QPushButton *deleteLessonButton;
    QPushButton *searchFreeRoomsButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scheduleTableWidget = new QTableWidget(centralwidget);
        scheduleTableWidget->setObjectName("scheduleTableWidget");
        scheduleTableWidget->setGeometry(QRect(0, 0, 511, 321));
        addLessonButton = new QPushButton(centralwidget);
        addLessonButton->setObjectName("addLessonButton");
        addLessonButton->setGeometry(QRect(0, 360, 121, 24));
        deleteLessonButton = new QPushButton(centralwidget);
        deleteLessonButton->setObjectName("deleteLessonButton");
        deleteLessonButton->setGeometry(QRect(140, 360, 151, 24));
        searchFreeRoomsButton = new QPushButton(centralwidget);
        searchFreeRoomsButton->setObjectName("searchFreeRoomsButton");
        searchFreeRoomsButton->setGeometry(QRect(330, 360, 161, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addLessonButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", nullptr));
        deleteLessonButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", nullptr));
        searchFreeRoomsButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\320\276\320\261\320\276\320\264\320\275\321\213\320\265 \320\260\321\203\320\264\320\270\321\202\320\276\321\200\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
