#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include<QTcpServer>
#include"connectionthread.h"
#include<qlist.h>
#include<qqueue.h>
#include<QString>
#include<qtcpsocket.h>
#include<qtimer.h>

class TcpServer : public QTcpServer
{
	Q_OBJECT

public:
	TcpServer(QTcpServer *parent=0);
	~TcpServer();

public slots:
	void slotNewConnection();
signals:
	void newSocketAdded();
private:
	QList<QTcpSocket *> mListOfSockets;		
	QQueue<QString> mQueue;
	QList<QByteArray> mAddresses;	
};

#endif // TCPSERVER_H
