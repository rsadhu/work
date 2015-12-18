#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include<QDebug>
#include<QTcpServer>
#include<QTcpSocket>>
#include<QThread>


class ReaderWriter:public QThread
{
public:
    ReaderWriter(QTcpSocket *socket):mSocket(socket)
    {

    }

    void run(void);


private:
    QTcpSocket *mSocket;
};


class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

public:
    void start();
    void close();
    void setReaderWriter(ReaderWriter *p)
    {
        objToBeDestroyed = p;
    }

public slots:
   void newConnection();
   void readData();

private:
   QTcpServer *server;
   QTcpSocket *socket ;
   ReaderWriter *objToBeDestroyed;
};



#endif // MYSERVER_H
