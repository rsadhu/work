#include "mainwindow.h"
#include "ui_mainwindow.h"

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
  mCentralWidget = new QWidget(this);

  mLayout = new QHBoxLayout(mCentralWidget);

  mSrcWidget = new SrcWidget(mCentralWidget);

  mDestWidget = new DestWidget(mCentralWidget);

  mLayout->addWidget(mSrcWidget);

  mLayout->addWidget(mDestWidget);

  setCentralWidget(mCentralWidget);
}
