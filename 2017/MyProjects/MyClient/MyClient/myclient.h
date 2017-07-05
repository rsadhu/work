#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QtWidgets/QWidget>
#include "ui_myclient.h"
#include<qtcpsocket.h>

class MyClient : public QWidget
{
	Q_OBJECT

public:
	MyClient(QWidget *parent = 0);
	~MyClient();
private slots:
	void slotSendData();
private:
	Ui::MyClientClass ui;
	QTcpSocket *mClientSocket = nullptr;
	bool g_connected = false;
	QString mIp;
	QString mPort;
};

#endif // MYCLIENT_H
