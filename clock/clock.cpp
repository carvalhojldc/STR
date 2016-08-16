#include "clock.h"


Clock::Clock()
{
    time(&_time);
    timeinfo = localtime (&_time);

    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    second = timeinfo->tm_sec;
}

Clock::~Clock()
{

}

void Clock::controlHour()
{
    if(this->minute==0 && this->minute == 0)
    {
        if(this->hour >= 23)
        {
            this->hour == 0;
        }
        else
        {
            this->hour += 1;
        }
    }
}

void Clock::controlMinute()
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

void Clock::controlSecond()
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

QString Clock::format()
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

QString Clock::getHour()
{
    controlSecond();
    controlMinute();
    controlHour();

    return format();
}

void Clock::setHour(int hour, int minute, int second)
{
    this->second = second;
    this->minute = minute;
    this->hour = hour;
}
