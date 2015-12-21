#include "mygraphicsviewclass.h"


MyGraphicsViewClass::MyGraphicsViewClass()
{
    qDebug()<<"MyGraphicsViewClass::MyGraphicsViewClass\n";
    setAcceptDrops(true);
}


/*
template<typename T>
void  MyGraphicsViewClass::registerYourSelf(T * obj)
{
    qDebug()<<"MyGraphicsViewClass::registerYourSelf\n";
    //mList.append(obj);
}*/



void MyGraphicsViewClass::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"MyGraphicsViewClass::mousePressEvent()\n";
}


void MyGraphicsViewClass::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"MyGraphicsViewClass::dragEnterEvent\n";
}

void MyGraphicsViewClass::dragLeaveEvent(QDragLeaveEvent *event)
{
    qDebug()<<"MyGraphicsViewClass::dragLeaveEvent\n";
}

void MyGraphicsViewClass::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<"MyGraphicsViewClass::dragMoveEvent\n";
}

void MyGraphicsViewClass::dropEvent(QDropEvent *event)
{
    qDebug()<<"MyGraphicsViewClass::dropEvent()\n";
}
