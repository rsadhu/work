#-------------------------------------------------
#
# Project created by QtCreator 2015-12-17T17:19:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dragDropApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widgetsrc.cpp \
    widgetdest.cpp \
    base.cpp

HEADERS  += mainwindow.h \
    widgetsrc.h \
    widgetdest.h \
    base.h

FORMS    += mainwindow.ui
