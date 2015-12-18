QT += core
QT -= gui

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    obj.cpp \
    testing.cpp \
    mystring.cpp \
    graphs.cpp

HEADERS += \
    obj.h \
    mystring.h \
    graphs.h

