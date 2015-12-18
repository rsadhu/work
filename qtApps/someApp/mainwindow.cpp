#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mView = ui->webView;    
    mView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //mView->setGe
    mGo =  ui->GO;
    mRefresh = ui->REFRESH;
    mForward = ui->FORWARD;
    mBackward =  ui->BACKWARD;
    connect(mView, SIGNAL(loadFinished(bool)), SLOT(pageLoaded(bool)));    
    connect(mView,SIGNAL(loadProgress(int)),SLOT(pageLoading(int)));
    connect(mView,SIGNAL(loadStarted()),SLOT(pageLoadStarted()));

    connect(mGo,SIGNAL(pressed()),this,SLOT(loadPage()));

    connect(mBackward,SIGNAL(pressed()), this,SLOT(openPreviousUrl()));

    connect(mForward,SIGNAL(pressed()), this,SLOT(openNextUrl()));
    mIndex=0;

}


void MainWindow::resizeEvent(QResizeEvent *e)
{
    if(e)
    {
        mView->resize(this->size());
       //                    ui->URL->resize(this->size());
    }

}

void MainWindow::openNextUrl()
{
#ifdef XXX
    int index = mIndex;
    if(!listofUrls[index+1].isEmpty())
        mView->load(listofUrls[++mIndex]);
#endif
    mView->forward();
}

void MainWindow::openPreviousUrl()
{
#ifdef XXX
    int index = mIndex;
    if(!listofUrls[index-1].isEmpty())
        mView->load(listofUrls[--mIndex]);
#endif
    mView->back();
}

void MainWindow::loadPage()
{
    QString url ("http://localhost");
    qDebug()<<ui->URL->text();
    if(!(ui->URL->text().isEmpty()))
        url =ui->URL->text();
    mView->load(QUrl(url));
    mView->resize(this->size());
}

void MainWindow::pageLoading(int percentage)
{
    qDebug()<<percentage<<endl;
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
    else{
        qDebug()<<"QWebPage loaded successfully\n";      
        ui->URL->setText(mView->url().toString());
    }

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
