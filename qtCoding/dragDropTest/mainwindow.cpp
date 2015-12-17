#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init()
{
 for(int i=0;i<NPICS;i++)
 {
     mImages[i] = new QImage;
     mScene[i]= new QGraphicsScene;
 }

 mImages[0]->load("C:\\Users\\rsadhu\\Desktop\\desktop.jpg");
 mImages[1]->load("C:\\Users\\rsadhu\\Desktop\\shiv-shakti.jpg");

 for(int i=0;i<NPICS;i++)
 {
   mPixmapItems[i] = new QGraphicsPixmapItem(QPixmap::fromImage(*mImages[i]));
   mScene[i]->addItem(mPixmapItems[i]);
   mScene[i]->setSceneRect(mScene[i]->sceneRect());
 }

 ui->graphicsView->setScene(mScene[0]);
 ui->graphicsView->fitInView(mPixmapItems[0], Qt::KeepAspectRatio);
 ui->graphicsView_2->setScene(mScene[1]);
  ui->graphicsView_2->fitInView(mPixmapItems[1], Qt::KeepAspectRatio);
 ui->graphicsView->show();
 ui->graphicsView_2->show();
}

static int i;
void MainWindow::mousePressEvent(QMouseEvent *mEvent)
{
    qDebug()<<"MousePressevent"<<i++<<"\n";
    if (mEvent->button() == Qt::MouseButton::LeftButton   && ui->centralWidget->geometry().contains(mEvent->pos()))
    {
          qDebug()<<" it was leftbutton pressed\n";
          QDrag *drag = new QDrag(this);

          QMimeData *mimeData = new QMimeData;
          QString mimeType("srcWidget");
          QByteArray *data = new QByteArray;
          data->setRawData("this is testing exercise",30);
          mimeData->setData(mimeType,*data);
          drag->setMimeData(mimeData);
          Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *mEvent)
{
 qDebug()<<"MainWindow::mouseMoveEvent\n";
}

void MainWindow::dragMoveEvent(QDragMoveEvent *dragmoveEvent)
{
 qDebug()<<"dragMoveEvent";
}
void MainWindow::dropEvent(QDropEvent *dropEvent)
{
qDebug()<<"dropEvent\n";
}

