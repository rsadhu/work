#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setAcceptDrops(true);
    ui->setupUi(this);
    qDebug()<<"geometry :: mainWindow :: "<<this->width()<<"  "<< this->height()<<endl;

    mCentralWidget =  new QWidget();
    mGridLayout =  new QGridLayout(mCentralWidget);
    mCentralWidget->setLayout(mGridLayout);

//    test();
    display2x2Layout();
    setCentralWidget(mCentralWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::display2x2Layout()
{
    int cnt=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            mWidgets[cnt] = new QWidget(this);
            mGridLayout->addWidget(mWidgets[cnt++],i,j,1,1);
        }
    }

    mWidgets[0]->setStyleSheet("background-color: rgb(0,0,255)");
    mWidgets[1]->setStyleSheet("background-color: rgb(0,255,0)");
    mWidgets[2]->setStyleSheet("background-color: rgb(255,0,0)");
    mWidgets[3]->setStyleSheet("background-color: rgb(255,255,255)");
}



void MainWindow:: mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"MainWindow::mousePressEvent::"<<event->pos().x()<<"  "<<event->pos().y()<<"\n";
    QDrag *drag =  new QDrag(this);
    QMimeData *mimeData  = new QMimeData();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

 /*   if(event->pos().x() >= width()- 250 && event->pos().x() <= width() && event->pos().y() <= 250)
    {
        qDebug()<<" MainWindow::mousePressEvent():: pressed widget2\n";
        mimeData->setData("Widget2", itemData );
    }
    else
    {
        qDebug()<<" MainWindow::mousePressEvent():: pressed widget\n";
        mimeData->setData("Widget1", itemData );
    }*/
    drag->setMimeData(mimeData);
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    mGridLayout->removeWidget(mWidgets[1]);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{

    //if (event->mimeData()->hasFormat("Widget1") || event->mimeData()->hasFormat("Widget2")) {
        qDebug()<<" dragEnter accepted";
        event->setDropAction(Qt::MoveAction);
        event->accept();

}

void MainWindow::dropEvent(QDropEvent *event)
{

    QWidget *thisWidget = mWidgets[0];
    thisWidget->layout()->removeWidget(thisWidget);
    //QWidget *thisCentralWidget = new QWidget;
    anotherGLayout = new QGridLayout(thisWidget);
    thisWidget->setLayout(anotherGLayout);
    anotherGLayout->addWidget(mWidgets[1],0,0,1,1);

}


void MainWindow::test()
{
    QWidget *arr[9];
    int cnt=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[cnt] = new QWidget(this);
            //arr[cnt]->resize(400, 300);
            mGridLayout->addWidget(arr[cnt++],i,j,1,1);
            //qDebug()<<i*j +  j;
        }
    }

    //arr[0] =  new QWidget(this);
    arr[0]->setStyleSheet("background-color: rgb(255,  0, 0)");
    //arr[1] =  new QWidget(this);
    arr[1]->setStyleSheet("background-color: rgb(0, 255, 0)");
    //mGridLayout->addWidget(arr[0],0,0,1,1);
   // mGridLayout->addWidget(arr[1],0,1,1,1);

    arr[2]->setStyleSheet("background-color: rgb(0,0,255)");
    arr[3]->setStyleSheet("background-color: rgb(255, 255, 0)");
    arr[4]->setStyleSheet("background-color: rgb(255,0, 255)");
    arr[5]->setStyleSheet("background-color: rgb(0, 255, 255)");
    arr[6]->setStyleSheet("background-color: rgb(255, 255, 255)");
    arr[7]->setStyleSheet("background-color: rgb(0, 0, 0)");
    arr[8]->setStyleSheet("background-color: rgb(150,150,150)");
}
