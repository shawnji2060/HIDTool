#-------------------------------------------------
#
# Project created by QtCreator 2013-05-10T22:49:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = usb_windows_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    libusb.h

FORMS    += mainwindow.ui


LIBS += -L$$PWD/ -lusb-1.0

RESOURCES += \
    resources.qrc



