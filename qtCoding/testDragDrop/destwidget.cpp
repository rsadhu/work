#include "destwidget.h"
#include<QDebug>
#include<QGraphicsPixmapItem>


DestWidget::DestWidget(QWidget *parent) : QWidget(parent)
{
 setAcceptDrops(true);
 mView =  new QGraphicsView(this);
 mScene = new QGraphicsScene(this);
 mView->setScene(mScene);
 mPixmap =  new QPixmap("C:\\Users\\rsadhu\\Desktop\\shiv-shakti.jpg");
 mScene->addPixmap(*mPixmap);
 mView->show();
}


void DestWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"DestWidget::dragEnterEvent()\n";

    if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
        event->accept();
    else
        event->ignore();
}


void DestWidget::dragLeaveEvent(QDragLeaveEvent *dragLeaveEvent)
{
  qDebug()<<"DestWidget::dragLeaveEvent\n";
}

void DestWidget::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<"DestWidget::dragMoveEvent::\n";
    if (event->mimeData()->hasFormat("image/x-puzzle-piece")) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }
}

void DestWidget::dropEvent(QDropEvent *event)
{
 qDebug()<<"DestWidget::dropEvent";

 if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
 {
     QByteArray pieceData = event->mimeData()->data("image/x-puzzle-piece");
     QDataStream dataStream(&pieceData, QIODevice::ReadOnly);
     //event->pos());
     QPixmap pixmap;
     QPoint location;
     dataStream >> pixmap >> location;
     event->setDropAction(Qt::MoveAction);
     event->accept();

     QGraphicsPixmapItem *item = (QGraphicsPixmapItem *)(&event->mimeData()->imageData());

    // mScene->addPixmap(0);
     mPixmap =  &pixmap;//new QPixmap("C:\\Users\\rsadhu\\Desktop\\despicable.jpg");
     //item.rem
     mScene->addPixmap(*mPixmap);
     mScene->update();
     mView->update();
     mView->show();


    /*QFile file("yourFile.png");
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "JPG");
    view.show();*/
}
}

