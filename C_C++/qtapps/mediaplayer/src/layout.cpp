#include"../inc/layout.h"
#include<QDebug>

#include<QToolBar>
#include<QAction>
#include<QList>


Layout::Layout()
{
    qDebug()<<"Layout::Layout\n";

    mainLayout =  new QVBoxLayout();
    topLayout  =  new QHBoxLayout();
    downLayout =  new QHBoxLayout();
    middleLayout =  new QHBoxLayout();


    QPushButton *topButton1 =  new QPushButton("Top1");
    QPushButton *topButton2 =  new QPushButton("Top2");
    QPushButton *topButton3 =  new QPushButton("Top3");

    connect(topButton1,SIGNAL(released()),this,SLOT(onPausePress()));
    connect(topButton2,SIGNAL(released()),this,SLOT(onStopPress()));
    connect(topButton3,SIGNAL(released()),this,SLOT(onPlayPress()));

    topLayout->addWidget(topButton1);
    topLayout->addWidget(topButton2);
    topLayout->addWidget(topButton3);


    QPushButton *downButton1 =  new QPushButton("Down1");
    QPushButton *downButton2 =  new QPushButton("Down2");
    QPushButton *downButton3 =  new QPushButton("Down3");

    connect(downButton1,SIGNAL(released()),this,SLOT(onPausePress1()));
    connect(downButton2,SIGNAL(released()),this,SLOT(onStopPress1()));
    connect(downButton3,SIGNAL(released()),this,SLOT(onPlayPress1()));

    downLayout->addWidget(downButton1);
    downLayout->addWidget(downButton2);
    downLayout->addWidget(downButton3);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(middleLayout);
    mainLayout->addLayout(downLayout);

    setLayout(mainLayout);
}

Layout::~Layout()
{
    qDebug()<<"Layout::~Layout\n";
    delete mainLayout;
}

void Layout::onPlayPress()
{
    qDebug()<<"Layout::onPlayPress()\n";
}

void Layout::onPausePress()
{
    qDebug()<<"Layout::onPausePress()\n";
}

void Layout::onStopPress()
{
    qDebug()<<"Layout::onStopPress()\n";
}

void Layout::onPlayPress1()
{
    qDebug()<<"Layout::onPlayPress1()\n";
}

void Layout::onPausePress1()
{
    qDebug()<<"Layout::onPausePress1()\n";
}

void Layout::onStopPress1()
{
    qDebug()<<"Layout::onStopPress1()\n";
}
