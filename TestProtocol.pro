#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T10:10:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestProtocol
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    uart.cpp

HEADERS  += mainwindow.h \
    uart.h

FORMS    += mainwindow.ui
