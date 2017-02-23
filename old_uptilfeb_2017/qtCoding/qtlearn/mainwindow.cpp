#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QEvent>
#include<QMouseEvent>
#include<QDrag>
#include<QDropEvent>
#include<QMimeData>
#include<QLabel>
#include<QPixMap>
#include<QGraphicsEllipseItem>
#include<QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
  ui->setupUi(this);
  connect(ui->pushButton,SIGNAL(clicked(bool)),SLOT(slotSwapDisplays()));
  init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    try{
    mImage1 = mImage2 =0;


    mImage1  = new QImage ();
    mImage1->load("C:\\Users\\rsadhu\\Desktop\\desktop.jpg");
    mImage2 = new QImage ();
    mImage2->load("C:\\Users\\rsadhu\\Desktop\\shiv-shakti.jpg");

    if(!mImage1 || !mImage2){
        throw "images aint  found";
    }

    scene1 = new QGraphicsScene(this);
    scene2 = new QGraphicsScene(this);

    QPixmap *pMap1 =  new QPixmap();
    pMap1->fromImage(*mImage1);

    QGraphicsPixmapItem *item1= new QGraphicsPixmapItem(*pMap1);
    scene1->addItem(item1);



    QPixmap *pMap2 =  new QPixmap();
    pMap2->fromImage(*mImage2);
    QGraphicsPixmapItem *item2= new QGraphicsPixmapItem(*pMap2);
    scene2->addItem(item2);


    ui->graphicsView->setScene(scene1);
    ui->graphicsView_2->setScene(scene2);



    /*QGraphicsEllipseItem *item = new QGraphicsEllipseItem;
    item->setRect( -50.0, -50.0, 100.0, 100.0 );

    scene1->addItem(item);*/
    ui->graphicsView->show();
    ui->graphicsView_2->show();

    }catch(...)
    {
            qApp->closeAllWindows();
    }
}

void MainWindow::slotSwapDisplays()
{

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


