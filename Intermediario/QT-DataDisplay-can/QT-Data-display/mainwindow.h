#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCanBus>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int mode = 0;
    Ui::MainWindow *ui;
    QCanBusDevice *device;
    QSerialPort *serial;
private slots:
    void showDate();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void showTime();
    void onFramesReceived();
    void updateBattery(int batteryLevel, int batteryStatus);
    void updateTemperature(int temp);
};
#endif // MAINWINDOW_H
