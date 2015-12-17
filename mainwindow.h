#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manometer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void readData();

private:
    Ui::MainWindow *ui;

    ManoMeter           *tempMeter;
    ManoMeter           *humiMeter;
    ManoMeter           *nc;
};

#endif // MAINWINDOW_H
