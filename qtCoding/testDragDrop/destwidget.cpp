#include "destwidget.h"
#include<QDebug>
#include<QGraphicsPixmapItem>
#include"srcwidget.h"
#include<QDrag>
#include<QMimeType>


DestWidget::DestWidget(QWidget *parent) : QWidget(parent)
{

 /*mView =  new QGraphicsView(this);
 mScene = new QGraphicsScene(this);
 mView->setScene(mScene);
 mPixmap =  new QPixmap("C:\\Users\\rsadhu\\Desktop\\shiv-shakti.jpg");
 mScene->addPixmap(*mPixmap);
 mView->show();

 mView->setAcceptDrops(true);*/
 this->setAcceptDrops(true);
}


void DestWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"DestWidget::dragEnterEvent()\n";
    if (event->mimeData()->hasFormat("image/x-puzzle-piece")){
        event->accept();
    }
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
 if(event->source()== this)
     return ;

/* if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
 {
     QByteArray pieceData = event->mimeData()->data("image/x-puzzle-piece");
     QDataStream dataStream(&pieceData, QIODevice::ReadOnly);

     QPixmap pixmap;
     QPoint location;
     dataStream >> pixmap >> location;
     event->setDropAction(Qt::MoveAction);
     event->accept();

     SrcWidget *srcW  =  static_cast<SrcWidget*>(event->source());
     srcW->receivePixMap(mPixmap);

     delete mPixmap;
     mPixmap =  new QPixmap(pixmap);
     mScene->addPixmap(*mPixmap);
     mScene->update();
     mView->update();
     mView->show();

    //QFile file("yourFile.png");
   // file.open(QIODevice::WriteOnly);
    //pixmap.save(&file, "JPG");
    //view.show();
}*/
}

void DestWidget ::receivePixMap(QPixmap *pixmap)
{
  qDebug()<<"DestWidget::receivePixMap();\n";
 /* if(pixmap)
  {
        mScene->addPixmap(*pixmap);
        delete mPixmap;
        mPixmap = new QPixmap(*pixmap);
        mView->show();
  }*/
}

void DestWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"DestWidget::mouseReleaseEvent\n";
    if (!(event->buttons() & Qt::LeftButton))
        return;

  /*  QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;


    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << *mPixmap ;//<< location;


    mimeData->setData("image/x-puzzle-piece1", itemData );

    drag->setMimeData(mimeData);


    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    switch(dropAction)
    {
      case Qt::CopyAction:
        qDebug()<<"DestWidget::copyAction\n";
        break;
      case Qt::MoveAction:
        qDebug()<<"DestWidget::moveAcion\n";
        break;
      default:
        qDebug()<<"DestWidget::defaultAction\n";
        break;
    }
    //update();
    */
}

