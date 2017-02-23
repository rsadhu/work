#include "restapiconsumer.h"

#include"QNetworkRequest"
#include"QNetworkReply"
#include"qnetworkaccessmanager.h"

RestApiConsumer::RestApiConsumer(QObject *parent)
	: QObject(parent)
{

}

RestApiConsumer::~RestApiConsumer()
{

}


QNetworkReply *netReply = nullptr;

void RestApiConsumer::GetBalance()
{
	QNetworkAccessManager *netman = new QNetworkAccessManager(this);
	connect(netman, SIGNAL(finished(QNetworkReply*)),
		this, SLOT(slotReplyFinished(QNetworkReply*)));
	QNetworkRequest netRequest(QUrl("http://10.0.0.221:9999/accountInfo"));
	netReply = netman->get(netRequest);
	connect(netReply, SIGNAL(finished()), this, SLOT(slotReadyRead()));

}

void RestApiConsumer::WithDraw()
{

}

void RestApiConsumer::ChangePin()
{

}

void RestApiConsumer::MiniStatement()
{


}
void RestApiConsumer::slotReadyRead()
{

}


void RestApiConsumer::slotReplyFinished(QNetworkReply *response)
{

}