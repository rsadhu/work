#include "srcwidget.h"
#include<QDebug>


SrcWidget::SrcWidget(QWidget *parent) : QWidget(parent)
{
    setAcceptDrops(true);
    mView =  new QGraphicsView(this);
    mScene = new QGraphicsScene(this);
    mView->setScene(mScene);
    mPixmap =  new QPixmap("C:\\Users\\rsadhu\\Desktop\\despicable.jpg");
    mPixmapItem = mScene->addPixmap(*mPixmap);
    mView->show();
}

void SrcWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
        event->accept();
    else
        event->ignore();
}

void SrcWidget::mousePressEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
        return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    QVariant extraData;
    extraData.setValue((void *)mPixmapItem);
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
   // QPoint location = event->   (Qt::UserRole+1).toPoint();
    dataStream << *mPixmap ;//<< location;


    mimeData->setData("image/x-puzzle-piece", itemData );
    mimeData->setImageData(extraData);
    drag->setMimeData(mimeData);
  //  drag->setPixmap(*mPixmap);

    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    switch(dropAction)
    {
      case Qt::CopyAction:
        qDebug()<<"copyAction\n";
        break;
      case Qt::MoveAction:
        qDebug()<<"moveAcion\n";
        break;
      default:
        qDebug()<<"defaultAction\n";
        break;
    }
}
