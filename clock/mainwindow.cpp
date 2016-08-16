#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_clock = new QTimer(this);
    timer_chronometer = new QTimer(this);
    clockU = new Clock();
    chronometer = new Chronometer();

    timer_clock->start(1000);
    timer_chronometer->start(1000);

    connect(timer_clock, SIGNAL(timeout()), this, SLOT(updateClock()));

    connect(ui->pbAdjustTime, SIGNAL(clicked(bool)), this, SLOT(ajdustTime()));

    connect(ui->pbStartChronometer,SIGNAL(clicked(bool)), this, SLOT(startChronometer()));
    connect(ui->pbPauseChronometer,SIGNAL(clicked(bool)), this, SLOT(pauseChronometer()));
    connect(ui->pbClearChronometer,SIGNAL(clicked(bool)), this, SLOT(clearChronometer()));

    ui->gpClock->setTitle("Relógio");

    ui->lbClock->setStyleSheet("QLabel { background-color : ; color : blue; }");

    ui->pbAdjustTime->setText("Ajustar hora");
    ui->pbStartChronometer->setStyleSheet("background-color: blue");
    ui->gpChronometer->setTitle("Cronômetro");
    ui->pbStartChronometer->setText("Iniciar");
    ui->pbStartChronometer->setStyleSheet("background-color: green");
    ui->pbPauseChronometer->setText("Pausar");
    ui->pbPauseChronometer->setStyleSheet("background-color: grey");
    ui->pbClearChronometer->setText("Limpar");
    ui->pbClearChronometer->setStyleSheet("background-color: red");


    ui->pbPauseChronometer->setVisible(false);
    clearChronometer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDataAdjustTime()
{
    int hour = adjustTime->getHour();
    int minute = adjustTime->getMinute();
    int second = adjustTime->getSecond();

    //adjustTime->hide();
    qDebug()<< "main windows";
    qDebug() << hour;
    qDebug() << minute;
    qDebug() << second;

    clockU->setHour(hour, minute, second);

}


void MainWindow::ajdustTime()
{
    adjustTime = new AdjustTime();

    adjustTime->show();

    connect(this, SIGNAL(getDataAdjustTime()), adjustTime, SIGNAL(sendData()));
}

void MainWindow::updateClock()
{
    ui->lbClock->setText(clockU->getHour());
    ui->lbChronometer->setText(chronometer->getHour());
}


void MainWindow::startChronometer()
{
    chronometer->setMode(CHRONOMETER_INIT);
    ui->pbPauseChronometer->setVisible(true);
    ui->pbStartChronometer->setVisible(false);
    timer_chronometer->start();
}

void MainWindow::pauseChronometer()
{
    chronometer->setMode(CHRONOMETER_PAUSE);
    ui->pbPauseChronometer->setVisible(false);
    ui->pbStartChronometer->setVisible(true);
    timer_chronometer->stop();
}

void MainWindow::clearChronometer()
{
    chronometer->setMode(CHRONOMETER_CLEAR);
    timer_chronometer->stop();
    ui->pbPauseChronometer->setVisible(false);
    ui->pbStartChronometer->setVisible(true);
}
