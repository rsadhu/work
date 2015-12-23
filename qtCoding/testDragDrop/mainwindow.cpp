#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "wi.h"

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
   //  mCentralWidget = new QWidget(this);
   wi* w1 = new wi(0);
   wi* w2 = new wi(0);
   w1->setStyleSheet("background-color: rgb(0, 255, 0);");
   w2->setStyleSheet("background-color: rgb(255, 0, 0);");
   w1->setGeometry(0,0,300, 300);
  w2->setGeometry(300,0,300, 300);
   w1->show();
   w2->show();

  // setCentralWidget(mCentralWidget);


 // mLayout = new QHBoxLayout(mCentralWidget);

 /* mSrcWidget = new SrcWidget(mCentralWidget);

  mDestWidget = new DestWidget(mCentralWidget);*/

  //->addWidget(w1);

 // mLayout->addWidget(w2);

 /* setCentralWidget(mCentralWidget);*/
}
