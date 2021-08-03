#include "mydisplaywidget.h"


MyDisplayWidget::MyDisplayWidget(QWidget *parent):QWidget(parent)
{

}


void MyDisplayWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"MyDisplayWidget ::mousePressEvent "<<this<<endl;
    QDrag *drag =  new QDrag(this);
    QMimeData *mimeD =  new QMimeData;
    drag->setMimeData(mimeD);
    drag->exec(Qt::MoveAction | Qt::CopyAction);
}


void MyDisplayWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"MyDisplayWidget ::dragEnterEvent "<<this<<endl;
    event->accept();
}



void MyDisplayWidget ::dropEvent(QDropEvent *event)
{
    qDebug()<<"MyDisplayWidget ::dropEvent "<<this<<endl;
}




