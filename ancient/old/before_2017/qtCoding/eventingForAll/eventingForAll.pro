#-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T11:49:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = eventingForAll
TEMPLATE = app


SOURCES += main.cpp\       
    mainwindow.cpp \
    pieceslist.cpp \
    puzzlewidget.cpp
#  dragwidget.cpp \
HEADERS  += mainwindow.h \
    pieceslist.h \
    puzzlewidget.h
    #dragwidget.h \

RESOURCES   =  puzzle.qrc




# install
target.path =  C:\\Users\rsadhu\\Desktop\\work\\qtCoding\\dragdropExample
INSTALLS += target



DISTFILES += \
    example.jpg
