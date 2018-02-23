#include "ChatClientPriv.h"
#include<qjsonvalue.h>
#include<qjsonobject.h>
#include<QJsonDocument>

void ChatClientPriv::reConnect()
{
	if(m_SocketClientToServer)
		m_SocketClientToServer->connectToHost("127.0.0.1", 2704);
}

ChatClientPriv::ChatClientPriv()
{
	m_SocketClientToServer = new QTcpSocket();
	m_SocketClientToServer->connectToHost("127.0.0.1", 2704);

	QObject::connect(m_SocketClientToServer, &QTcpSocket::connected, [=]() 
	{
		emit signalLogin();
		qDebug() << " SOcket is connected \n";
		QJsonObject val;
		val["key"] = QJsonValue("biodata");
		val["name"] = QJsonValue("rsadhu");
		val["age"] = QJsonValue(35);
		val["address"] = QJsonValue("JK India");
		
		QJsonDocument doc(val);
		QByteArray data = doc.toJson();

		m_SocketClientToServer->write(data);
	});

	QObject::connect(m_SocketClientToServer, &QTcpSocket::readyRead, [=]()
	{
		qDebug() << " Data read :: " << m_SocketClientToServer->readAll();
	});

	QObject::connect(m_SocketClientToServer, &QTcpSocket::stateChanged, [=](QAbstractSocket::SocketState st)
	{
		qDebug() << " Socket State  " << st;
		//m_SocketClientToServer->write("Hello Client Here");
	});
}


ChatClientPriv::~ChatClientPriv()
{
	m_SocketClientToServer->disconnect();
	delete m_SocketClientToServer;
}

void ChatClientPriv::login(QString &username, QString&password)
{
	if (m_SocketClientToServer && m_SocketClientToServer->state()==QAbstractSocket::ConnectedState)
	{
		QJsonObject val;
		val["key"] = QJsonValue("Login");
		val["username"] = QJsonValue(username);		
		val["password"] = QJsonValue(password);

		QJsonDocument doc(val);
		QByteArray data = doc.toJson();

		m_SocketClientToServer->write(data);
		m_SocketClientToServer->flush();
		m_SocketClientToServer->waitForBytesWritten(100);
	}
}
