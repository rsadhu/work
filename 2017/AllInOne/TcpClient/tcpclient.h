#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtWidgets/QWidget>
#include "ui_tcpclient.h"
#include<QTcpSocket>

class TcpClient : public QWidget
{
	Q_OBJECT

public:
	TcpClient(QWidget *parent = 0);
	~TcpClient();
public slots:
	void slotIamConnected();
	void slotError(QAbstractSocket::SocketError err);
	void slotSendData();
private:
	Ui::TcpClientClass ui;
	QTcpSocket *mSocket = nullptr;
};

#endif // TCPCLIENT_H
