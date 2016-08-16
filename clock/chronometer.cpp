#include "chronometer.h"

Chronometer::Chronometer()
{
    clear();
    mode = 0;
}

QString Chronometer::clear()
{
    this->hour = 0;
    this->minute = 0;
    this->second = 0;

    return "00:00:00";
}

void Chronometer::controlHour()
{
    if(this->minute==MAX_TIME_C && this->minute == MAX_TIME_C)
    {
       this->hour += 1;
    }
}

void Chronometer::controlMinute()
{
    if(this->second==0)
    {
        if(this->minute>=0)
        {
            this->minute += 1;
        }
        else if(this->minute==MAX_TIME_C)
        {
            this->minute == 0;
        }
    }
}

void Chronometer::controlSecond()
{
    if(this->second>=MAX_TIME_C)
    {
        this->second = 0;
    }
    else if(this->second<0)
    {
        this->second = 0;
    }
    else
    {
        this->second += 1;
    }
}

QString Chronometer::format()
{
    // hh::mm::ss
    QString h, m, s;

    if(this->hour<10)
        h = "0" + QString::number(this->hour) + ":";
    else
        h = QString::number(this->hour) + ":";

    if(this->minute<10)
        m = "0" + QString::number(this->minute) + ":";
    else
        m = QString::number(this->minute) + ":";

    if(this->second<10)
        s = "0" + QString::number(this->second);
    else
        s = QString::number(this->second);

    return  h + m + s;
}

void Chronometer::setMode(int mode)
{
    this->mode = mode;
}

QString Chronometer::getHour()
{
    if(mode == CHRONOMETER_CLEAR)
    {
        return clear();
    }
    else if(mode == CHRONOMETER_INIT)
    {
        completeHour.clear();
        controlSecond();
        controlMinute();
        controlHour();
        completeHour = format();
        return completeHour;
    }
    else if(mode == CHRONOMETER_PAUSE)
    {
        return completeHour;
    }
}

