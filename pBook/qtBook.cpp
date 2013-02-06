#include"qtBook.h"

QtBook::QtBook()
{
    qDebug()<<"QtBook::QtBook\n";
}

QtBook::~QtBook()
{
    qDebug()<<"QtBook::~QtBook\n";
}

void QtBook::read(char *data)
{
    qDebug()<<"QtBook::read\n";
}

void QtBook::write(char *data)
{
    qDebug()<<"QtBook::write\n";
}
