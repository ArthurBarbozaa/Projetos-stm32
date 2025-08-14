#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>
#include <QFile>
#include <QSerialPort>
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serial(new QSerialPort(this))
{
    ui->setupUi(this);

    serial->setPortName("/dev/ttyACM0");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    serial->open(QIODevice::ReadOnly);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::updateGear);

}

void MainWindow::updateGear()
{
    QByteArray data = serial->readLine().trimmed();
    if (QString(data) == "R") {
        ui->gearIndicator->setText(QString(data));
        ui->gearIndicator->setStyleSheet("color:red; background-color: rgba(191, 64, 64, 0);");
    } else {
    ui->gearIndicator->setText(QString(data));
    ui->gearIndicator->setStyleSheet("color:white; background-color: rgba(191, 64, 64, 0);");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


