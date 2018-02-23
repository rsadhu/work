#include "ChatClientPriv.h"
#include<qjsonvalue.h>
#include<qjsonobject.h>
#include<QJsonDocument>
#include<qjsonarray.h>

void ChatClientPriv::reConnect()
{
	if (m_SocketClientToServer)
	{
		m_SocketClientToServer->disconnectFromHost();
		m_SocketClientToServer->connectToHost("127.0.0.1", 2704);
	}
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
		auto data =   m_SocketClientToServer->readAll();

		
		QJsonDocument jsD;
		jsD = QJsonDocument::fromJson(data);
		QJsonObject jsonVal = jsD.object();

		if (jsonVal["key"].toString().compare("onlineClients") == 0)
		{
			auto listClients = jsonVal["clients"];
			QStringList list;
			for (int i = 0; i < listClients.toArray().size(); i++)
			{
				qDebug() << " Data read :: " << listClients.toArray()[i];
				list << listClients.toArray()[i].toString();

			}
			emit signalClientListFetched(list);
		}
	});

	QObject::connect(m_SocketClientToServer, &QTcpSocket::stateChanged, [=](QAbstractSocket::SocketState st)
	{
		qDebug() << " Socket State  " << st;
		//m_SocketClientToServer->write("Hello Client Here");
	});
}


ChatClientPriv::~ChatClientPriv()
{
	m_SocketClientToServer->disconnectFromHost();
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
