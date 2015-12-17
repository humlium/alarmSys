#-------------------------------------------------
#
# Project created by QtCreator 2015-12-17T22:39:37
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alarmSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    abstractmeter.cpp \
    functions.cpp \
    manometer.cpp \
    widgetwithbackground.cpp

HEADERS  += mainwindow.h \
    abstractmeter.h \
    functions.h \
    manometer.h \
    widgetwithbackground.h

FORMS    += mainwindow.ui
