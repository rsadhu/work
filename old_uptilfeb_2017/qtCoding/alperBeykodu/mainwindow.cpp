#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHBoxLayout>
#include"mydisplaywidget.h"

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
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);
    MyDisplayWidget *w1 =  new MyDisplayWidget(this);
    w1->setStyleSheet("background-color: rgb(0,0,255)");
    MyDisplayWidget *w2 =  new MyDisplayWidget(this);
    w2->setStyleSheet("background-color: rgb(0,255,0)");
    layout->addWidget(w1);
    layout->addWidget(w2);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
