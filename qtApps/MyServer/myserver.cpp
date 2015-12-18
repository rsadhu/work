#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server =  new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),SLOT(newConnection()));
}


void MyServer::start()
{
    if(server->listen(QHostAddress::Any,5000))
    {
        qDebug()<<"Server is Listening....";
    }
    else
    {
        qDebug()<<"Server is down...";

    }
}


void MyServer::close()
{
    server->close();
}

void MyServer::readData()
{

}

void MyServer::newConnection()
{
    qDebug()<<"Client Connected ..";
    socket =  server->nextPendingConnection();
    ReaderWriter *rw = new ReaderWriter(socket);
    this->setReaderWriter(rw);
    connect(socket,SIGNAL(readyRead()),rw,SLOT(run()));
    socket->write("hello");
    socket->flush();
    socket->waitForBytesWritten(3000);
}


void ReaderWriter::run()
{
    QByteArray data;
    data = mSocket->readAll();
    qDebug()<<data;
}
