#ifndef QTCLIENTAPP_H
#define QTCLIENTAPP_H

#include <QtWidgets/QWidget>
#include "ui_qtclientapp.h"
#include <QTcpSocket>

class QtClientApp : public QWidget
{
	Q_OBJECT

public:
	QtClientApp(QString host, QString datatobewritten, int portNumber = 9999, QWidget *parent = 0);
	~QtClientApp();
public slots:
	void slotConnectToHost();	  // ui connection
	void slotWriteDate();		  // write to server
	void slotIsConnectedToHost(); // slot if connected to server
	void slotReadyRead();		  // data from server to be read
private:
	Ui::QtClientAppClass ui;
	QTcpSocket mClient;
	QString mHostAddress;
	QString mDataToBeWritten;
	int mPortNumber;
	bool mIsConnected;
	bool isReadFromServer;
};

#endif // QTCLIENTAPP_H
