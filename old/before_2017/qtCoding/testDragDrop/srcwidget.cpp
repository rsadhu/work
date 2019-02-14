#include "srcwidget.h"
#include<QDebug>
#include"destwidget.h"


SrcWidget::SrcWidget(QWidget *parent) : QWidget(parent)
{
    setAcceptDrops(true);
   /* mView =  new QGraphicsView(this);
    mScene = new QGraphicsScene(this);
    mView->setScene(mScene);
    mPixmap =  new QPixmap("C:\\Users\\rsadhu\\Desktop\\despicable.jpg");
    mScene->addPixmap(*mPixmap);
    mView->show();*/

   // mView->setAcceptDrops(true);
}

void SrcWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("image/x-puzzle-piece1"))
        event->accept();
    else
        event->ignore();
}

void SrcWidget::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<"SrcWidget::dragMoveEvent::\n";
    if (event->mimeData()->hasFormat("image/x-puzzle-piece1")) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }
}

void SrcWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    qDebug()<<"SrcWidget::dragLeaveEvent()\n";
}

void SrcWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<"SrcWidget::dropEvent";
    if(event->source()==this)
        return ;

   /* if (event->mimeData()->hasFormat("image/x-puzzle-piece1"))
    {
        QByteArray pieceData = event->mimeData()->data("image/x-puzzle-piece1");
        QDataStream dataStream(&pieceData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint location;
        dataStream >> pixmap >> location;
        event->setDropAction(Qt::MoveAction);
        event->accept();

        DestWidget *destW  =  static_cast<DestWidget*>(event->source());
        destW->receivePixMap(mPixmap);

        delete mPixmap ;

        mPixmap =  new QPixmap(pixmap);

        mScene->addPixmap(*mPixmap);
        mScene->update();
        mView->update();
        mView->show();

      // QFile file("yourFile.png");
       //file.open(QIODevice::WriteOnly);
       //pixmap.save(&file, "JPG");
//       view.show();
   }*/
}


void SrcWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"SrcWidget::mousePressEvent\n";

    /*if (!(event->buttons() & Qt::LeftButton))
        return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << *mPixmap ;//<< location;


    mimeData->setData("image/x-puzzle-piece", itemData );

    drag->setMimeData(mimeData);


    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    switch(dropAction)
    {
      case Qt::CopyAction:
        qDebug()<<"SrcWidget::copyAction\n";
        break;
      case Qt::MoveAction:
        qDebug()<<"SrcWidget::moveAcion\n";
        break;
      default:
        qDebug()<<"SrcWidget::defaultAction\n";
        break;
    }
    update();*/
}

void SrcWidget::receivePixMap(QPixmap *sentPixmap)
{
 /* qDebug()<<"SrcWidget::receivePixMap();\n";
  if(sentPixmap)
  {
    mScene->addPixmap(*sentPixmap);
    delete mPixmap;
    mPixmap =  new QPixmap(*sentPixmap);
    mView->show();
  }*/
}
