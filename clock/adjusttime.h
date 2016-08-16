#ifndef ADJUSTTIME_H
#define ADJUSTTIME_H

#include <QWidget>

#include <QDebug>

namespace Ui {
class AdjustTime;
}

class AdjustTime : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustTime(QWidget *parent = 0);
    ~AdjustTime();

    int getHour() const;
    void setHour(int value);

    int getMinute() const;
    void setMinute(int value);

    int getSecond() const;

    bool getStatus() const;

private slots:
    void sendData();

private:
    Ui::AdjustTime *ui;

    int hour;
    int minute;
    int second;

    bool status;

};

#endif // ADJUSTTIME_H
