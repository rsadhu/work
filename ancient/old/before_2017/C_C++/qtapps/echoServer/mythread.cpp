#include "mythread.h"
#include<QDebug>

MyThread::MyThread(int ID,QObject *parent) :
    QThread(parent)
{
    qDebug()<<"MyThread::MyThread\n";
    this->socketdescriptor = ID;
}

void MyThread::run()
{
    qDebug()<<"MyThread::Run\n";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketdescriptor))
    {
        emit errorSocket(socket->error());
        return ;
    }
    connect(socket, SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);
    exec();
}

void MyThread::readyRead()
{
    QByteArray data;
    data =  socket->readAll();
    qDebug()<<" MyThread::readyRead::"<<data;
    socket->write(data);
}

void MyThread::disconnected()
{
    qDebug()<<"MyThread::Disconnected\n";
    socket->deleteLater();
    exit(0);
}

