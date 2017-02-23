#ifndef SERVER_H
#define SERVER_H
#include<QDebug>
#include<QTcpServer>
#include<QTcpSocket>




class MyServer:public QObject
{
    Q_OBJECT
public:
    MyServer();
public slots:
    void newConnection();

private:
    QTcpServer *server;
};

#endif // SERVER_H
