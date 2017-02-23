#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include<QTcpServer>
#include"connectionthread.h"
#include<qlist.h>
#include<qqueue.h>
#include<QString>

class TcpServer : public QTcpServer
{
	Q_OBJECT

public:
	TcpServer(QTcpServer *parent=0);
	~TcpServer();

public slots:
	void slotNewConnection();
private:
	QList<ConnectionThread *> mList;	
	int mMaxThreads = 10;
	QQueue<QString> mQueue;
};

#endif // TCPSERVER_H
