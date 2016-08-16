#ifndef CLOCK_H
#define CLOCK_H

#include <QString>

#define MAX_TIME_C 59

class Clock
{
private:
    QString completeHour;

    time_t _time;
    struct tm * timeinfo;

    int hour;
    int minute;
    int second;

    void controlSecond();
    void controlMinute();
    void controlHour();
    QString format();

public:
    Clock();
    ~Clock();
    QString getHour();
    void setHour(int hour, int minute, int second);
};

#endif // CLOCK_H
