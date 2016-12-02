
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    centralWidget = new QWidget(this);

    layout =  new QHBoxLayout(centralWidget);
    oneWidget =  new QWidget(centralWidget);
    oneWidget->setStyleSheet("background-color:rgb(255,0,0);");

    //setLayout(layout);

    layout->addWidget(oneWidget);
    //layout->addWidget(secondWidget);
    setCentralWidget(centralWidget);

    QPushButton *btn  = new QPushButton(this);
    layout->addWidget(btn);
    connect(btn,SIGNAL(clicked(bool)), this , SLOT(transferContent()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::transferContent()
{
    //QWidget *secondWidget  =  new QWidget(centralWidget);
    QWidget *newWid        = new      QWidget(centralWidget);
    *newWid = *oneWidget;
    layout->addWidget(newWid);

}
