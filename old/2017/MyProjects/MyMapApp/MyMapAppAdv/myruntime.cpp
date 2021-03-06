#include "myruntime.h"
#include"mywebviewer.h"
#include<qwebframe.h>
#include<qwidget.h>
#include"qwebpage.h"
#include"MyDatabaseContoller.h"

MyRunTime::MyRunTime(QWidget *parent)
	: QWidget(parent)
{
	init();
	resize(500, 500);
	MyDatabaseContoller::getInstance()->writeData("WebRunTime", "Logged in ");
}

void MyRunTime::init()
{
	mWebView = new MyWebViewer(this);

	// Signal is emitted before frame loads any web content:
	QObject::connect(mWebView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
		this, SLOT(addJSObject()));
	mWebView->loadPage("file:///D://rsadhu//work//MyMapApp//MyMapAppAdv//Resources//sysinfo.html");
}

void MyRunTime::getSysInfo()
{
	systemName = QSysInfo::buildAbi();
	cpuArchitecture = QSysInfo::currentCpuArchitecture();
	productName = QSysInfo::prettyProductName();	
	emit signalCallBackToJsWorld(systemName,cpuArchitecture,productName);
}

void MyRunTime::addJSObject()
{
	mWebView->page()->mainFrame()->addToJavaScriptWindowObject("MyRunTime", this);		
}

MyRunTime::~MyRunTime()
{
	MyDatabaseContoller::getInstance()->writeData("WebRunTime", "Logged out ");
	delete mWebView;
}
