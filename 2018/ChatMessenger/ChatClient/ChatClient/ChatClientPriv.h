#pragma once
#include<qobject.h>
#include<qtcpsocket.h>

class ChatClientPriv:public QObject
{
	Q_OBJECT
public:
	ChatClientPriv();
	~ChatClientPriv();
	void reConnect();
	void login(QString &username, QString &password);
	void logout();
signals:
	void signalLogin();
	void signalLoginSuccessful();
	void signalLogoutSuccessful();
private:
	QTcpSocket * m_SocketClientToServer = nullptr;
	QTcpSocket * m_SocketClientToClient = nullptr;
};

