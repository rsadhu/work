#include "windowManager.h"

WindowManager::WindowManager(QWidget *parent) :
QWidget(parent),mCentralWidget(this)
{
      this->resize(650,850);
     this->setStyleSheet("background-color:rgb(255,255,255);");
       /*this->setStyleSheet("background-color:rgb(0,0,255);");

        w1= new QWidget(this);
        w1->setStyleSheet("background-color:rgb(0,255,0);");
        w1->resize(300,300);
        w2 =  new QWidget(this);
        w2->setGeometry(400,400,300,300);
        w2->setStyleSheet("background-color:rgb(255,0,0);");
    //    w2->raise();
        w1->raise();



//        QHBoxLayout *layout = new QHBoxLayout(mCentralWidget);

        //mWindow = new Window(this);
        //mWindow->setStyleSheet("background-color:rgb(0,255,0);");
  //      layout->addWidget(mWindow);;

        //Window *anotherWindow =  new Window(this);
    //    layout->addWidget(anotherWindow);
       // anotherWindow->setStyleSheet("background-color:rgb(0,0,255);");

       // anotherWindow->setParent(mWindow);
       // anotherWindow->resize(400,500);
        //mWindow->setParent(0);


     /*   QGridLayout *gridLayout = new QGridLayout(anotherWindow);
        //layout->addLayout(gridLayout,0,0);
        Window *w1 =  new Window(mCentralWidget);
        Window *w2 =  new Window(mCentralWidget);
        Window *w3 =  new Window(mCentralWidget);
        Window *w4 =  new Window(mCentralWidget);
        gridLayout->addWidget(w1,0,0,1,1);
        gridLayout->addWidget(w2,0,1,1,1);
        gridLayout->addWidget(w3,1,0,1,1);
        gridLayout->addWidget(w4,1,1,1,1);
        w1->raise();
        w3->raise();

        w1->setStyleSheet("background-color:rgb(255,0,0);");
        w2->setStyleSheet("background-color:rgb(255,0,255);");
        w3->setStyleSheet("background-color:rgb(255,255,0);");
        w4->setStyleSheet("background-color:rgb(0,0,255);");

        QGridLayout *anotherLayout = new QGridLayout(mWindow);
        Window *newWindow1 = new Window();
        anotherLayout->addWidget(newWindow1);
        newWindow1->setStyleSheet("background-color:rgb(255,0,0);");


        Window *newWindow2 = new Window();
        anotherLayout->addWidget(newWindow2);
        newWindow2->setStyleSheet("background-color:rgb(255,0,255);");*/

        //mCentralWidget->show();*/

    mWindow = new Window(this);
    mWindow->setStyleSheet("background-color:rgb(0,0,255);");
    mWindow->setGeometry(0,0,100,100);
    QWidget *w = new QWidget(mWindow);
    w->setStyleSheet("background-color:rgb(255,0,0);");
    w->setGeometry(0,0,50,50);
    //w->show();
}

WindowManager::~WindowManager()
{
    qDebug()<<"WindowManager::~WindowManager"<<this<<endl;
}


void WindowManager::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"WindowManager::mousePressEvent: "<<this<<endl;
 //   event->
}



