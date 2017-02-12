#include "myruntime.h"
#include"mywebviewer.h"
#include<qwebframe.h>
#include<qwidget.h>
#include"qwebpage.h"

MyRunTime::MyRunTime(QWidget *parent)
	: QWidget(parent)
{
	mWebView = new MyWebViewer(this);
	mWebView->page()->mainFrame()->addToJavaScriptWindowObject("MyRunTime",this);

	mWebView->loadPage("file:///D://rsadhu//work//MyMapApp//MyMapAppAdv//Resources//sysinfo.html");

}

MyRunTime::~MyRunTime()
{

}
