#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mDest =  new WidgetDest;
    mSrc = new WidgetSrc;

    QGraphicsScene *scene =  new QGraphicsScene;
    QImage * image = new QImage;
    image->load("C:\\Users\\rsadhu\\Desktop\\desktop.jpg");
    QGraphicsPixmapItem *item =  new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene->addItem(item);

    mDest->init(scene,item,image);


    QGraphicsScene *scene1 =  new QGraphicsScene;
    QImage * image1 = new QImage;
    image->load("C:\\Users\\rsadhu\\Desktop\shiv-shakti.jpg");
    QGraphicsPixmapItem *item1 =  new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene1->addItem(item1);

    mSrc->init(scene1,item,image);


    layout =  new QHBoxLayout(this);
    layout->addWidget(mSrc);
    layout->addWidget(mDest);
    setCentralWidget(layout);

    mSrc->show();
    mDest->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


