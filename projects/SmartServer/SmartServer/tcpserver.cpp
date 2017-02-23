#include "tcpserver.h"

TcpServer::TcpServer( QTcpServer*parent)
: QTcpServer(parent)
{
	listen(QHostAddress::Any, 27482);
	connect(this, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
}

TcpServer::~TcpServer()
{
	mList.clear();
}

void TcpServer::slotNewConnection()
{
	if (mMaxThreads-- > 0)
	{
		ConnectionThread * newConnection = new ConnectionThread(this);		
		newConnection->start();
		mList.append(newConnection);
	}
	else
	{
		//mQueue.append(QString::number();
	}
}