#include <QtCore/QCoreApplication>
#include"contact.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Contact c(12345,"rakesh");
    Contact d(c);
    Contact e;
    e = c;
    return a.exec();
}
