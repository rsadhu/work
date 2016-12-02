#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);

     QWidget *mainWidget = new QWidget(this);
     mainWidget->setStyleSheet("background:colour=rgb(255,0,0);");
}


void MainWindow::openAnotherMenu()
{


}

MainWindow::~MainWindow()
{
    //delete ui;
}



void MainWindow::mousePressEvent(QMouseEvent *)
{
 qDebug()<<"MainWindow::mousePressEvent\n";

}

void MainWindow::moveContentToAnotherWidget()
{
  QWidget *anotherWidget =  new QWidget(this);
}
