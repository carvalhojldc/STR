#include "adjusttime.h"
#include "ui_adjusttime.h"

AdjustTime::AdjustTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdjustTime)
{
    ui->setupUi(this);

    connect(ui->pbSendNewTime, SIGNAL(clicked(bool)), this, SLOT(sendData()));

    ui->pbSendNewTime->setText("Atualizar horário");

    this->status = false;
}

AdjustTime::~AdjustTime()
{
    delete ui;
}


void AdjustTime::sendData()
{
    this->hour = ui->sbHour->value();
    this->minute = ui->sbMinute->value();
    this->second = ui->sbSecond->value();

    this->status=true;

    qDebug() << "classe";
    qDebug() << hour;
    qDebug() << minute;
    qDebug() << second;
}

bool AdjustTime::getStatus() const
{
    return status;
}

int AdjustTime::getHour() const
{
    return hour;
}

void AdjustTime::setHour(int value)
{
    hour = value;
}

int AdjustTime::getMinute() const
{
    return minute;
}

void AdjustTime::setMinute(int value)
{
    minute = value;
}

int AdjustTime::getSecond() const
{
    return second;
}
