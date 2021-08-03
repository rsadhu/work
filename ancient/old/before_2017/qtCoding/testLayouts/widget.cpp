#include "widget.h"
#include "ui_widget.h"
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent)//,
    //ui(new Ui::Widget)
{
    this->setGeometry(50,50,850,650);
    QGridLayout *gridLayout= new QGridLayout(this);
    setLayout(gridLayout);
    QVBoxLayout *vLayout =  new QVBoxLayout(this);
    QHBoxLayout *hLayout =  new QHBoxLayout(this);
    //QWidget *tmp1 = new QWidget(this);
    //QWidget *tmp2 = new QWidget(this);
   // tmp1->setLayout(vLayout);
   // tmp2->setLayout(hLayout);


    gridLayout->addLayout(hLayout,1,0);
    gridLayout->addLayout(vLayout,0,1,2,1);//0,3);
    //gridLayout->addWidget(tmp1,0,3,1,1);
    //gridLayout->addWidget(tmp2,3,0,1,1);

    QWidget *w =  new QWidget(this);

    QWidget *w1 =  new QWidget(this);
    QWidget *w2 =  new QWidget(this);
    QWidget *w3 =  new QWidget(this);

    QWidget *w11 =  new QWidget(this);
    QWidget *w22 =  new QWidget(this);
    QWidget *w33 =  new QWidget(this);


    QWidget *w4 =  new QWidget(this);
    QWidget *w5 =  new QWidget(this);

    w->setStyleSheet("background-color:rgb(0,0,0);");

    w1->setStyleSheet("background-color:rgb(255,0,0);");
    w2->setStyleSheet("background-color:rgb(255,0,255);");
    w3->setStyleSheet("background-color:rgb(0,255,0);");

    w11->setStyleSheet("background-color:rgb(255,0,0);");
    w22->setStyleSheet("background-color:rgb(255,0,255);");
    w33->setStyleSheet("background-color:rgb(0,255,0);");

    w4->setStyleSheet("background-color:rgb(0,0,255);");
    w5->setStyleSheet("background-color:rgb(255,255,0);");

    vLayout->addWidget(w1);
    vLayout->addWidget(w2);
    vLayout->addWidget(w3);

    //vLayout->addWidget(w11);
//    vLayout->addWidget(w22);
//    vLayout->addWidget(w33);

    hLayout->addWidget(w4);
    hLayout->addWidget(w5);

    gridLayout->addWidget(w,0,0,2,2);
    show();
}

Widget::~Widget()
{
    //delete ui;
}
