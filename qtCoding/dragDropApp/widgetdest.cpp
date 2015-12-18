#include "widgetdest.h"

WidgetDest::WidgetDest(QWidget*parent):Base(parent)
{
    //setDragMode(true);
     setAcceptDrops(true);
}


void WidgetDest::dragMoveEvent(QDragMoveEvent *event)
{
qDebug()<<"WidgetDest::dragMoveEvent\n";
}

void WidgetDest::dragEnterEvent(QDragEnterEvent *event)
{
 qDebug()<<"WidgetDest::dragEnterEvent\n";
 if(event)
 {
   qDebug()<<event->mimeData()->text()<<"\n";
 }
}

void WidgetDest::dragLeaveEvent(QDragLeaveEvent *event)
{
 qDebug()<<"WidgetDest::dragLeaveEvent\n";
}


void WidgetDest::mousePressEvent(QMouseEvent *event)
{
 qDebug()<<"WidgetDest::mousePressEvent\n";
}
