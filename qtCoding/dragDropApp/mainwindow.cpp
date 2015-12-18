#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *centralWidget = new  QWidget(this);

    mDest =  new WidgetDest(this);
    mSrc = new WidgetSrc(this);

    QGraphicsScene *scene =  new QGraphicsScene(this);
    QImage * image = new QImage;
    image->load("/home/rsadhu/Desktop/chick.jpg");
    QGraphicsPixmapItem *item =  new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene->addItem(item);

    mDest->init(scene,item,image);


    QGraphicsScene *scene1 =  new QGraphicsScene;
    QImage * image1 = new QImage;
    image->load("/home/rsadhu/Desktop/horse.jpg");
    QGraphicsPixmapItem *item1 =  new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene1->addItem(item1);

    mSrc->init(scene1,item,image);




    setCentralWidget(centralWidget);
    layout =  new QHBoxLayout(centralWidget);
    layout->addWidget(mSrc);
    layout->addWidget(mDest);
    QPushButton *button = new QPushButton(this);
    connect(button, SIGNAL(clicked(bool)),this,SLOT(slotButtonPressed()));
    layout->addWidget(button);


    mSrc->show();
    mDest->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

static bool toggle=false;

void MainWindow::slotButtonPressed()
{
  if(layout->direction() == QBoxLayout::LeftToRight)
      layout->setDirection(QBoxLayout::RightToLeft);
  else
      layout->setDirection(QBoxLayout::LeftToRight);
}
