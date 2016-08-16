#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <QString>

#define MAX_TIME_C 59
#define CHRONOMETER_CLEAR 0
#define CHRONOMETER_INIT 1
#define CHRONOMETER_PAUSE 2

class Chronometer
{
public:
    Chronometer();
    QString clear();
    QString getHour();
    void setMode(int mode);

private:
    QString completeHour;
    int hour;
    int minute;
    int second;

    void controlHour();
    void controlMinute();
    void controlSecond();
    QString format();

    int mode;
};

#endif // CHRONOMETER_H
