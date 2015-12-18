QT += core network
QT -= gui

TARGET = MyServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp

HEADERS += \
    myserver.h

