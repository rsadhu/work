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

    mCentralWidget =  new QWidget(this);
    mGridLayout =  new QGridLayout(this);
    mCentralWidget->setLayout(mGridLayout);

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
    setCentralWidget(mCentralWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow:: mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"MainWindow::mousePressEvent::"<<event->pos().x()<<"  "<<event->pos().y()<<"\n";
    QDrag *drag =  new QDrag(this);
    QMimeData *mimeData  = new QMimeData();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    if(event->pos().x() >= width()- 250 && event->pos().x() <= width() && event->pos().y() <= 250)
    {
        qDebug()<<" MainWindow::mousePressEvent():: pressed widget2\n";
        mimeData->setData("Widget2", itemData );
    }
    else
    {
        qDebug()<<" MainWindow::mousePressEvent():: pressed widget\n";
        mimeData->setData("Widget1", itemData );
    }
    drag->setMimeData(mimeData);
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"MainWindow::dragMoveEvent::\n";
    if (event->mimeData()->hasFormat("Widget1") || event->mimeData()->hasFormat("Widget2")) {
        qDebug()<<" dragEnter accepted";
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        qDebug()<<" dragEnter ignored";
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    /*    qDebug()<<"MainWindow::dropEvent::  \n";
    QWidget *src= static_cast<QWidget*>(event->source());
   // if(src== ui->widget)
   // {

        if (event->mimeData()->hasFormat("Widget1")){
                qDebug()<<"MainWindow::dropEvent:: Widget1 \n";
            setStyleSheet("background-color: rgb(0, 255, 0);");
           ui->widget_2->setGeometry(width()-250,0,width(),250);
           //ui->layout()->removeWidget(ui->widget_2);
           ui->centralWidget->layout()->removeWidget(ui->widget_2);
            event->accept();
        }

  //  }
     //if(src == ui->widget_2)
   // {

       else if (event->mimeData()->hasFormat("Widget2")){
           qDebug()<<"MainWindow::dropEvent:: Widget2 \n";
           ui->centralWidget->layout()->removeWidget(ui->widget);
             ui->widget->setGeometry(width()-250,0,width(),250);
            setStyleSheet("background-color: rgb(255,0 , 0);");
            event->accept();
        }
        else{
              qDebug()<<"MainWindow::dropEvent:: unrecognised area\n";
            event->ignore();
        }
    //}
    /*else
    {
        qDebug()<<"MainWindow::dropEvent:: unrecognised area\n";
    }*/
}
