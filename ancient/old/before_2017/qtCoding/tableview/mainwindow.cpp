#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    QStringList tableHeader;
    tableHeader<<"Action "<<" ShortCut"<<"description";
     ui->tableWidget->setHorizontalHeaderLabels(tableHeader);


     QTableWidgetItem *item1 = new QTableWidgetItem();
     item1->setText("zoom");

     QTableWidgetItem *item2 = new QTableWidgetItem();
     item2->setText("cntrl+mouse");

     QTableWidgetItem *item3 = new QTableWidgetItem();
     item3->setText("zooms the video ashajshjahsjhhhhh1111111111111111111111111111hjhjhjhj");
     ui->tableWidget->setItem(0,0,item1);
     ui->tableWidget->setItem(0,1,item2);
     ui->tableWidget->setItem(0,2,item3);
     ui->tableWidget->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}
