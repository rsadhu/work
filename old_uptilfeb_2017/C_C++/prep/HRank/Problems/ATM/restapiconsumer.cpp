#include "restapiconsumer.h"
#include"mainmenu.h"
#include"QAuthenticator.h"


typedef struct map
{

};

char *arr[] = {
				"http://10.0.0.221:9999/accountInfo", ""
			  };
RestApiConsumer::RestApiConsumer(QObject *parent)
	: QObject(parent)
{
	super = parent;
	m_netman = new QNetworkAccessManager(this);
	m_netman->setNetworkAccessible(QNetworkAccessManager::Accessible);
	connect(m_netman, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotReplyFinished(QNetworkReply*)));
	connect(m_netman,SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)),	this,	SLOT(onAuthenticationRequestSlot(QNetworkReply*, QAuthenticator*)));
}

RestApiConsumer::~RestApiConsumer()
{

}

void RestApiConsumer::onAuthenticationRequestSlot(QNetworkReply*aReply, QAuthenticator* aAuthenticator)
{
	aAuthenticator->setUser("admin");
	aAuthenticator->setPassword("admin12.");

}

void RestApiConsumer::GetBalance()
{	
	QUrl url("http://10.0.0.221:9999/accountInfo");
	//QUrl url("http://10.0.0.180/test.html");
	if (url.isValid())
	{
		QNetworkRequest netRequest(url);
		m_netReply = m_netman->get(netRequest);			
	}

//	QNetworkRequest netRequest(QUrl("http://10.0.0.9/stw-cgi/media.cgi?msubmenu=sessionkey&action=view"));
	//QNetworkReply *netReply = m_netman->get(netRequest);
}

void RestApiConsumer::WithDraw()
{
	QUrl url("http://10.0.0.221:9999/withdraw?amount=300");
	if (url.isValid())
	{
		QNetworkRequest netRequest(url);
		m_netReply = m_netman->get(netRequest);
	}

}

void RestApiConsumer::ChangePin()
{

	QUrl url("http://10.0.0.221:9999/pinchange?pin=3");
	if (url.isValid())
	{
		QNetworkRequest netRequest(url);
		m_netReply = m_netman->get(netRequest);
	}
}

void RestApiConsumer::MiniStatement()
{
	QUrl url("http://10.0.0.221:9999/ministatement");
	if (url.isValid())
	{
		QNetworkRequest netRequest(url);
		m_netReply = m_netman->get(netRequest);
	}
}
void RestApiConsumer::slotReadyRead()
{

}


void RestApiConsumer::slotReplyFinished(QNetworkReply *response)
{
	QByteArray data = response->readAll();
	((MainMenu*)super)->drawData(data);
}