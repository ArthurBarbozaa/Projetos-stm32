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

    connect(serial, &QSerialPort::readyRead, this, &MainWindow::updateBattery);

    QByteArray data = serial->readLine().trimmed();


}

void MainWindow::updateBattery()
{
    QByteArray data = serial->readLine().trimmed();
    int val = atoi(data);
    if (QString(val) < 75 ) {
        ui->progressBar->setValue(val);
        ui->progressBar->setStyleSheet("selection-background-color: rgb(192, 28, 40)");
    } else {
        ui->progressBar->setValue(val);
        ui->progressBar->setStyleSheet("selection-background-color: rgb(53, 132, 228)");
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


