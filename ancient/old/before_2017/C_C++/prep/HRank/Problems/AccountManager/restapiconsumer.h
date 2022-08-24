#ifndef RESTAPICONSUMER_H
#define RESTAPICONSUMER_H

#include <QObject>
#include <QNetWorkReply.h>

class RestApiConsumer : public QObject
{
	Q_OBJECT

public:
	RestApiConsumer(QObject *parent);
	~RestApiConsumer();

	void GetBalance();
	void WithDraw();
	void ChangePin();
	void MiniStatement();

private:
	void slotReplyFinished(QNetworkReply *);
	void slotReadyRead();
}

#endif // RESTAPICONSUMER_H
