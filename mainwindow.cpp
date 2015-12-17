#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <QTime>


QSerialPort serial;
QByteArray serialData;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial.setPortName("ttyUSB0");
    serial.setBaudRate(serial.Baud9600);
    serial.setDataBits(serial.Data8);
    serial.setParity(serial.NoParity);
    serial.setStopBits(serial.OneStop);
    serial.setFlowControl(serial.NoFlowControl);
    connect(&serial, SIGNAL(readyRead()), this, SLOT(readData()));
    serial.open(QIODevice::ReadWrite);



    tempMeter = new ManoMeter(this);
    humiMeter = new ManoMeter(this);
    nc        = new ManoMeter(this);
    tempMeter->setMaximum(100);
    humiMeter->setMaximum(100);
    tempMeter->setSuffix("\u00B0c");
    humiMeter->setSuffix("%");
    ui->verticalLayout->addWidget(tempMeter);
    ui->verticalLayout_3->addWidget(humiMeter);
    ui->verticalLayout_2->addWidget(nc);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readData()
{
    QByteArray tmp = serial.readAll();
        if(tmp.endsWith('\x0A')){
            serialData.append(tmp);
                QString str = serialData;
                QStringList list = str.split(",");
                if(list.length() >= 2){
                    tempMeter->setValue(list[0].toInt());
                    humiMeter->setValue(list[1].toInt());

                    serialData.clear();
                }

        }else serialData.append(tmp);
}
