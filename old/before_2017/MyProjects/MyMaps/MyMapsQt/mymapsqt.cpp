#include "mymapsqt.h"
#include"qwebpage.h"


QUrl g_url;
MyMapsQt::MyMapsQt(QWebView *parent)
: QWebView(parent)
{	
	ui.setupUi(this);
	auto settings = page()->settings();
	settings->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
	settings->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
	QUrl url("file:\\\c:\\users\\rsadhu\\Desktop\\maptest.html");
	//QUrl url("http://qt.nokia.com");
	g_url = url;
	page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);	
	connect(this, SIGNAL(loadFinished(bool)), this, SLOT(slotLoadFinished(bool)));
	connect(this, SIGNAL(loadProgress(int)), this, SLOT(slotLoadProgress(int)));	

	//load(url);
	ui.webView->load(url);
}

MyMapsQt::~MyMapsQt()
{

}

void MyMapsQt::slotLoadFinished(bool st)
{
	
}

void MyMapsQt::slotLoadProgress(int pr)
{

}
