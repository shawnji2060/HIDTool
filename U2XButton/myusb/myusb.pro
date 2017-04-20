#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T14:08:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myusb
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    u2xbtneventmonitor.cpp \
    u2x_thread.cpp

HEADERS  += mywidget.h \
    lusb0_usb.h \
    u2xbtneventmonitor.h \
    u2x_thread.h

FORMS    += mywidget.ui
LIBS += "C:\Users\jiche\Desktop\U2XButton\myusb\libusb.a"
