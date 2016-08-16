#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>


#include "clock.h"
#include "chronometer.h"
#include "adjusttime.h"

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateClock();
    void ajdustTime();
    void getDataAdjustTime();
    void startChronometer();
    void pauseChronometer();
    void clearChronometer();

private:
    Ui::MainWindow *ui;

    QTimer * timer_clock;
    QTimer * timer_chronometer;

    Clock *clockU;

    Chronometer *chronometer;

    AdjustTime * adjustTime;

    bool chronometerInitPause;
};

#endif // MAINWINDOW_H
