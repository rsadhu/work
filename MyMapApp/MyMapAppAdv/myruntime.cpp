#include "myruntime.h"
#include"mywebviewer.h"
#include<qwebframe.h>
#include<qwidget.h>
#include"qwebpage.h"

MyRunTime::MyRunTime(QWidget *parent)
	: QWidget(parent)
{
	init();
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

}

void MyRunTime::addJSObject()
{
	mWebView->page()->mainFrame()->addToJavaScriptWindowObject("MyRunTime", this);	
//	this->signalSystemInfoDetails.connect(getSysInfo);
}

MyRunTime::~MyRunTime()
{

}
