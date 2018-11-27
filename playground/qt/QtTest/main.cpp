#include <QCoreApplication>
#include"qttest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QtTest test;

    return a.exec();

}
