#include "mainwindow.h"
#include <QApplication>
#include<QTreeWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //  MainWindow w;
    // w.show();

    QWidget *centralWidget = new QWidget;
    centralWidget->setGeometry(100,100,800,600);

    QGridLayout *gridLayout =  new QGridLayout(centralWidget);

    QWidget *w1 =  new QWidget(centralWidget);
    QWidget *w2 =  new QWidget(centralWidget);
    QWidget *w3 =  new QWidget(centralWidget);
    QWidget *w4 =  new QWidget(centralWidget);

    gridLayout->addWidget(w1,0,0,1,1);
    gridLayout->addWidget(w2,0,1,1,1);
    gridLayout->addWidget(w3,1,0,1,1);
    gridLayout->addWidget(w4,1,1,1,1);
    centralWidget->setLayout(gridLayout);

    /*
    gridLayout->addWidget(w1);
    gridLayout->addWidget(w2);
    gridLayout->addWidget(w3);
    gridLayout->addWidget(w4);
     */

    w1->setStyleSheet("background-color: rgb(0,0,255)");
    w2->setStyleSheet("background-color: rgb(0,255,0)");
    w3->setStyleSheet("background-color: rgb(255,0,0)");
    w4->setStyleSheet("background-color: rgb(255,255,255)");

    QGridLayout *anotherLayout = new QGridLayout(w1);


    QWidget *w11 =  new QWidget(w1);
    QWidget *w21 =  new QWidget(w1);
    QWidget *w31 =  new QWidget(w1);
    QWidget *w41 =  new QWidget(w1);

    anotherLayout->addWidget(w11,0,0,1,1);
    anotherLayout->addWidget(w21,0,1,1,1);
    anotherLayout->addWidget(w31,1,0,1,1);
    anotherLayout->addWidget(w41,1,1,1,1);

    w1->setLayout(anotherLayout);

    w11->setStyleSheet("background-color: rgb(0,0,255)");
    w21->setStyleSheet("background-color: rgb(0,255,0)");
    w31->setStyleSheet("background-color: rgb(255,0,0)");
    w41->setStyleSheet("background-color: rgb(255,255,255)");

    w1->show();
    /*
    QTreeWidget *treeWidget = new QTreeWidget(centralWidget);
    treeWidget->setDragEnabled(true);;

    QHBoxLayout *hlayout =  new QHBoxLayout(centralWidget);
    gridLayout->addLayout(hlayout,0,2,1,3);


    QTreeWidgetItem *itemOne = new QTreeWidgetItem(treeWidget);
    QTreeWidgetItem *itemTwo = new QTreeWidgetItem(treeWidget);
    QTreeWidgetItem *itemThree = new QTreeWidgetItem(treeWidget);

    itemOne->setText(0, "One");
    itemTwo->setText(0, "Two");
    itemThree->setText(0, "Three");
    treeWidget->setAcceptDrops(1);

    hlayout->addWidget(treeWidget);*/
    centralWidget->show();
    centralWidget->setAcceptDrops(true);;
    return a.exec();
}
