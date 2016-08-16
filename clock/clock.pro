#-------------------------------------------------
#
# Project created by QtCreator 2016-08-16T00:32:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clock.cpp \
    chronometer.cpp \
    adjusttime.cpp

HEADERS  += mainwindow.h \
    clock.h \
    chronometer.h \
    adjusttime.h

FORMS    += mainwindow.ui \
    adjusttime.ui
