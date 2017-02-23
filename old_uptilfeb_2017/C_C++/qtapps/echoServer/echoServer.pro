#-------------------------------------------------
#
# Project created by QtCreator 2013-08-10T18:01:11
#
#-------------------------------------------------

QT  +=  core
QT  +=  network
QT  +=  webkit


TARGET = echoServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app



SOURCES += main.cpp \
    myserver.cpp \
    mythread.cpp

HEADERS += \
    myserver.h \
    mythread.h
