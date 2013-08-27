#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUi();
    webview = new QWebView(this);
    connect(webview,SIGNAL(loadStarted()),this,SLOT(loadStarted()));
    connect(webview,SIGNAL(loadFinished(bool)), this,SLOT(loadFinished(bool)));
    setCentralWidget(webview);

}

MainWindow::~MainWindow()
{
    
}



void MainWindow::closeEvent(QCloseEvent *ev)
{

}


void MainWindow::loadStarted()
{
    qDebug()<<" MainWindow::loadStarted()";
}

void MainWindow::loadFinished(bool l)
{
    qDebug()<<" MainWindow::loadFinished()"<<l;
}


void MainWindow::openPage()
{
    QString rawUrl("http://www.google.com");
    QUrl url(rawUrl);
    webview->load(url);
}

void MainWindow::createUi()
{
    menu= menuBar()->addMenu("main");

    open = new QAction(QIcon(":/images/open.png"),"open", this);

    connect(open, SIGNAL(triggered()),this, SLOT(openPage()));

    menu->addAction(open);

    show();
}
