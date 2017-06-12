#include "myserver.h"
#include "mythread.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    qDebug()<<"MyServer::MyServer\n";
}


void MyServer::startServer()
{

    if(!listen(QHostAddress::Any,1234))
    {
        qDebug()<<" MyServer:: not Listening ...";
    }
    else
    {
        qDebug()<<" MyServer::Listening ...";
    }
}

void  MyServer::incomingConnection(qintptr handle)
{
    qDebug()<<" MyServer::incomingConnection::"<<handle;
    MyThread *mythread = new MyThread(handle,this);
    connect(mythread,SIGNAL(finished()), mythread  , SLOT(deleteLater()));
    connect(mythread,SIGNAL(errorSocket(QTcpSocket::SocketError)),this,SLOT(errorSocket(QTcpSocket::SocketError)));
    mythread->start();
}


void MyServer::errorSocket(QAbstractSocket::SocketError err)
{
    qDebug()<<"MyServer::errorSocket:: "<<err;
}

