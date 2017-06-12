#ifndef MYSERVER_H
#define MYSERVER_H

#include<QtNetwork/QTcpServer>
//#include<QtWebKit>
#include<QTcpSocket>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void startServer();
protected:
   void incomingConnection(qintptr handle);
signals:
public slots:
   void errorSocket(QTcpSocket::SocketError);
    
};

#endif // MYSERVER_H
