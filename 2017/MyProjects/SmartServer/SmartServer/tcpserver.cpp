#include "tcpserver.h"
#include<QTcpSocket>
#include<QFile>

TcpServer::TcpServer(QTcpServer*parent)
	: QTcpServer(parent)
{
	listen(QHostAddress::Any, 27482);
	connect(this, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

	connect(this, &TcpServer::newSocketAdded, [=]()
	{
		for (auto socket : mListOfSockets)
		{
			if (socket )
			{	
				QByteArray data;
				for (auto d : mAddresses)
				{			
				//	data.push_back(d);
				}		

				QFile img("D:\\rsadhu\\work_git\\2017\\MyProjects\\SmartServer\\SmartServer\\dp.jpg");
				img.open(QIODevice::ReadOnly);
				data = img.readAll();
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
	static int cnt = 0;
	
	if (socket)
	{	
		mListOfSockets.push_back(socket);
		connect(socket, &QIODevice::readyRead, [=]()
		{
			qDebug() << "socket des :   " << socket->socketDescriptor();
			QByteArray d = socket->readAll();		
		
			if (!d.isEmpty())
			{				
				mAddresses.push_back(d);			
				emit newSocketAdded();
			}		
		}
		);

		connect(socket, &QAbstractSocket::disconnected, [=]()
		{
			for (auto it : mListOfSockets)
			{
				if (it->socketDescriptor() == socket->socketDescriptor())
				{
					qDebug() << "socket des :   "<<it->socketDescriptor();
					mListOfSockets.removeOne(it);
					break;
				}
			}
		}
		);
	}		
}