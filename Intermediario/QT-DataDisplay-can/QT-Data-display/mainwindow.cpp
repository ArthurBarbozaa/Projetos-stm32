#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QDateTime>
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,device(nullptr)
    , serial(new QSerialPort(this))
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(showTime()));
    connect(timer,SIGNAL(timeout()), this, SLOT(showDate()));
    timer->start();

    device = QCanBus::instance()->createDevice("socketcan","vcan0");

    if (device) {
        device->setConfigurationParameter(QCanBusDevice::BitRateKey, QVariant());

        connect(device,&QCanBusDevice::framesReceived, this, &MainWindow::onFramesReceived);
        device->connectDevice();
    }

       serial->setPortName("/dev/ttyACM0");
       serial->setBaudRate(QSerialPort::Baud115200);
       serial->setDataBits(QSerialPort::Data8);
       serial->setParity(QSerialPort::NoParity);
       serial->setStopBits(QSerialPort::OneStop);
       serial->setFlowControl(QSerialPort::NoFlowControl);

       serial->open(QIODevice::WriteOnly);

  }

void MainWindow::onFramesReceived()
{
    if (!device) return;
    while (device->framesAvailable()) {
        QCanBusFrame frame = device->readFrame();

        uint32_t canId = frame.frameId();
        QByteArray data = frame.payload();

        qDebug() << "Received CAN ID:" << Qt::hex << canId
                        << "Data:" << data.toHex();

        if (canId == 0x100) {
            uint8_t batteryLevel = data[0];
            uint8_t batteryStatus = data[1];

            updateBattery(batteryLevel,batteryStatus);
         }
        if (canId == 0x200) {
            uint8_t temp = data[0];

            updateTemperature(temp);

        }
    }
}
void MainWindow::updateBattery(int batteryLevel, int batteryStatus)
{
     ui->label_2->setText(QString::number(batteryLevel) + "%");
            ui->progressBar->setValue(batteryLevel);
            QString stat;

            if (batteryLevel < 75) {
                serial->write("B1\n");
                ui->label_3->setStyleSheet("color: red");
            } else {
                serial->write("B0\n");
                ui->label_3->setStyleSheet("color: rgba(164, 164, 164, 227);");
            }

            if (batteryStatus == 0) {
                stat = "Discharging";
                ui->progressBar->setStyleSheet("selection-background-color:blue");

            }
            else if (batteryStatus == 1) {
                stat = "Charging";
                ui->progressBar->setStyleSheet("selection-background-color:green");
            }else {
                stat = "Full";
                ui->progressBar->setStyleSheet("selection-background-color:yellow");
            }
            ui->label_6->setText(stat);

}

void MainWindow::updateTemperature(int temp)
{

    if (temp < 57) {

        ui->label_4->setStyleSheet("color: rgba(164, 164, 164, 227);");
        if (mode == 0) {
            ui->tempLabel->setStyleSheet("color:white");

        }
        else {
            ui->tempLabel->setStyleSheet("color:black");

        }
        serial->write("T0\n");
    } else {
        ui->tempLabel->setStyleSheet("color:red");
        ui->label_4->setStyleSheet("color:red");
        serial->write("T1\n");
    }

    ui->tempLabel->setText(QString::number(temp) + "°C");
}
void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh:mm ");
    ui->timeLabel->setText(time_text);
}

void MainWindow::showDate()
{
    QDateTime date = QDateTime::currentDateTime();
    QString date_text = date.toString("ddd d MMMM yyyy");
    ui->dateLabel->setText(date_text);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    mode = 0;
    MainWindow::setStyleSheet("background-color: rgb(15,15,15);color: rgb(255, 255, 255)");

}


void MainWindow::on_pushButton_clicked()
{
    mode = 1;
    MainWindow::setStyleSheet("color: rgb(14, 13, 13);background-color: rgb(255, 255, 255)");
}

