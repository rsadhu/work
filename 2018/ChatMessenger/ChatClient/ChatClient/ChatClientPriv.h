#pragma once
#include<qobject.h>
#include<qtcpsocket.h>
#include<qtimer.h>

class ChatClientPriv:public QObject
{
	Q_OBJECT
public:
	ChatClientPriv();
	~ChatClientPriv();
	void reConnect();
	void login(QString &username, QString &password);
	//void logout();
	void refresh();
	void createChatClient(int);	
	void send(QString);
signals:
	void signalLogin();
	void signalLoginSuccessful();
	void signalLogoutSuccessful();
	void signalClientListFetched( QStringList );
private:
	QTcpSocket * m_SocketClientToServer = nullptr;
	QTcpSocket * m_SocketClientToClient = nullptr;
	QTimer  *m_Timer = nullptr;
};

