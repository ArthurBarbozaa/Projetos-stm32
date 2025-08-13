#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{

    QFile file("/dev/ttyACM0");

    if (!file.open(QIODevice::WriteOnly)){
        return;
    }
    QTextStream out(&file);
    out << ui->horizontalSlider->value() <<"\n";
    out.flush();

}

