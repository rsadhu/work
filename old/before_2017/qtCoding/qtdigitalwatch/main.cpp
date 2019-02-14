#include "mainwindow.h"
#include <QApplication>
#include<qtwatch.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QtWatch qWatch;
    qWatch.show();
    return a.exec();
}
