#include "tcpserver.h"
#include<QTcpSocket>

TcpServer::TcpServer(QTcpServer*parent)
	: QTcpServer(parent)
{
	listen(QHostAddress::Any, 27482);
	connect(this, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

	connect(this, &TcpServer::newSocketAdded, [=]()
	{
		for (auto socket : mListOfSockets)
		{
			if (socket)
			{	
				QByteArray data;
				for (auto d : mAddresses)
				{			
					data.push_back(d);
				}		

				socket->write(data);
			}
		}
	});	
}

TcpServer::~TcpServer()
{
	mListOfSockets.clear();
}

void TcpServer::slotNewConnection()
{
	QTcpSocket *socket = nextPendingConnection(); 
	
	if (socket)
	{
		mListOfSockets.push_back(socket);
		connect(socket, &QIODevice::readyRead, [=]()
		{
			QByteArray d = socket->readAll();		
		
			if (!d.isEmpty())
			{
				d += "#";
				mAddresses.push_back(d);			
				emit newSocketAdded();
			}		
		}
		);
	}		
}