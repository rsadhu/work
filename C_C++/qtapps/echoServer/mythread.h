#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include<QHash>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int ID,QObject *parent = 0);
    void run();
signals:
    void errorSocket(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead();
    void disconnected();
private:
    QTcpSocket *socket;
    int socketdescriptor;
};

#endif // MYTHREAD_H
