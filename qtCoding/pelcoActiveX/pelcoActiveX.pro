#-------------------------------------------------
#
# Project created by QtCreator 2016-07-20T18:28:45
#
#-------------------------------------------------

QT       += core gui
QT += widgets axcontainer


TARGET = pelcoActiveX
TEMPLATE = app


 TYPELIBS = $$system(dumpcpp -getfile {D2CE0AE8-970B-479B-BDA3-D685EA590590})

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
