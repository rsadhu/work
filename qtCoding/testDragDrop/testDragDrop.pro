#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T11:14:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testDragDrop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    destwidget.cpp \
    srcwidget.cpp

HEADERS  += mainwindow.h \
    destwidget.h \
    srcwidget.h

FORMS    += mainwindow.ui
