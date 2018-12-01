#-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T13:12:20
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BasketScore
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    AutoResize.cpp \
    fourthdialog.cpp

HEADERS  += mainwindow.h \
    AutoResize.h \
    fourthdialog.h

FORMS    += mainwindow.ui \
    fourthdialog.ui

RESOURCES += \
    fonts.qrc
