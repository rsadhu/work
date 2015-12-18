#include "widgetsrc.h"

WidgetSrc::WidgetSrc(QWidget*parent):Base(parent)
{
 //setDragMode(true);
     setAcceptDrops(true);
}


void WidgetSrc::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<"WidgetSrc::dragMoveEvent\n";
}

void WidgetSrc::dragEnterEvent(QDragEnterEvent *event)
{
 qDebug()<<"WidgetSrc::dragEnterEvent\n";
}

void WidgetSrc::dragLeaveEvent(QDragLeaveEvent *event)
{
qDebug()<<"WidgetSrc::dragLeaveEvent\n";
}

void WidgetSrc ::mousePressEvent(QMouseEvent *event)
{
 qDebug()<<"WidgetSrc::mousePressEvent\n";


 if (event->button() == Qt::LeftButton
     && this->geometry().contains(event->pos())) {

     QDrag *drag = new QDrag(this);
     QMimeData *mimeData = new QMimeData;
     //mimeData->setData("",mImage->DataPtr);


      mimeData->setText("hello");
     drag->setMimeData(mimeData);
    drag->setPixmap(mPixmapItem->pixmap());

     Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
 }
}

