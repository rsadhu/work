#include "ChatServerPriv.h"
#include<qdebug.h>
#include<QString>
#include<qjsonvalue.h>
#include<qjsonobject.h>
#include<QJsonDocument>
#include<QJsonArray>




ChatServerPriv::ChatServerPriv()
{	
	if (listen(QHostAddress::Any, 2704))
	{
		qDebug() << "System Health Server Listening..";
	}
	else
	{
		qDebug() << "System Health Server Couldn't start";
	}
}


ChatServerPriv::~ChatServerPriv()
{
}


void ChatServerPriv::incomingConnection(qintptr  socketDescriptor)
{
	ChatClientConnection * newConnection = new ChatClientConnection(socketDescriptor);
	connect(newConnection, SIGNAL(finished()), newConnection, SLOT(deleteLater()));
	newConnection->start();
}

ChatClientConnection::ChatClientConnection(int sdesc):m_SocketDescriptor(sdesc)
{

}




void ChatClientConnection::run()
{
	m_Socket = new QTcpSocket();
	if (m_Socket->setSocketDescriptor(m_SocketDescriptor))
	{
		connect(m_Socket, &QTcpSocket::readyRead, [=]()
		{
			auto data = m_Socket->readAll();	
			QJsonDocument jsD;
			jsD = QJsonDocument::fromJson(data);
			QJsonObject jsonVal = jsD.object();
			
			if (jsonVal["key"].toString().compare("Login") == 0)
			{			
				auto username = jsonVal["username"].toString();
				auto password = jsonVal["password"].toString();
				qDebug() << " username :: " << username;
				qDebug() << " password :: " << password;			

				QJsonObject val;

				val["key"] = QJsonValue("onlineClients");
				QJsonArray array;
				array << "127.0.0.1" << "10.0.5.1" << "10.0.5.2" << "10.0.5.3";
				val["clients"] = QJsonArray(array);
				
				QJsonDocument doc(val);
				QByteArray data = doc.toJson();

				m_Socket->write(data);
			}
			else
			if (jsonVal["key"].toString().compare("Refresh") == 0)
			{
				QJsonObject val;

				val["key"] = QJsonValue("onlineClients");
				QJsonArray array;
				array << "127.0.0.1" << "10.0.5.1" << "10.0.5.2" << "10.0.5.3"<<"192.168.1.1"<<"192.168.1.2";
				val["clients"] = QJsonArray(array);

				QJsonDocument doc(val);
				QByteArray data = doc.toJson();
				m_Socket->write(data);
				
			}
			else
			{				
				qDebug() << " data is " << data;
				m_Socket->write(data);
			}
			
			//m_Socket->write(QByteArray("socketId:: ")+QByteArray(QString::number(m_SocketDescriptor).toStdString().c_str()) + "  " + m_Socket->readAll());
			m_Socket->flush();
			m_Socket->waitForBytesWritten(300);
		});

		connect(m_Socket, &QTcpSocket::disconnected, [=]()
		{
			m_Socket->deleteLater();
			exit(0);
		});
	}
	exec();

}