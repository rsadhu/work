#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mView= ui->webView;
    mView->setGeometry(0,0,200,200);
    connect(mView, SIGNAL(loadFinished(bool)), SLOT(pageLoaded(bool)));
    connect(mView,SIGNAL(loadProgress(int)),SLOT(pageLoading(int)));
    connect(mView,SIGNAL(loadStarted()),SLOT(pageLoadStarted()));
}

void MainWindow::pageLoading(int percentage)
{
    qDebug()<<percentage<<endl;
    //sleep(1000);
    //QTest::qSleep ( int m

}


void MainWindow::pageLoadStarted()
{
 qDebug()<<"MainWindow::pageLoadStarted\n" ;
}

void MainWindow::pageLoaded(bool isLoaded)
{
    if(!isLoaded)
    {
        qDebug()<<" QWebPage isnt loaded\n";
    }
    else
        qDebug()<<"QWebPage loaded successfully\n";

}

void MainWindow::openPage(char *url)
{
    if(url)
        mView->load(QUrl(url));
}


MainWindow::~MainWindow()
{
    delete ui;
}
