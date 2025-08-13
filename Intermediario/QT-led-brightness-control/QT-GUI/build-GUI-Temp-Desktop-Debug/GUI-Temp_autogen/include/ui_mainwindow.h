/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 39, 39);\n"
"color: white;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 180, 181, 41));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 220, 121, 91));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(470, 180, 31, 41));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 350, 62, 16));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 350, 62, 16));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(300, 330, 160, 16));
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(246, 245, 244);\n"
"gridline-color: rgb(255, 255, 255);\n"
"selection-color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label_2, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Luminosidade", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\360\237\222\241", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
