#include "mainwindow.h"
#include"windowovermainwindow.h"
#include <QApplication>
#include<QMenu>

//template<typename T>
//void (*callBack)(T);


template<typename U>
void test(U x)
{
  qDebug()<<x<<endl;
}

void xyz(QString &rhs)
{
    qDebug()<<" xtyz"<<rhs<<endl;
}

void test(void)
{
     qDebug()<<" callback\n";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//  windowOverMainWindow w;
    w.show();

    //callBack xy = xyz;
    //xy(QString("helllo"));


  test<int>(7);
  test<char*>("testing template functions");
  test<QString>("QString as args in functions");

    return a.exec();
}
