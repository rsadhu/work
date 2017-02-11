#include "mywebveiew.h"
#include<qwebpage.h>
#include<qwebframe.h>

MyWebVeiew::MyWebVeiew(QWidget *parent)
	: QWebView(parent)
{
	ui.setupUi(this);
	connect(this, SIGNAL(loadFinished(bool)), this, SLOT(slotloadFinished(bool)));
}
	

MyWebVeiew::~MyWebVeiew()
{

}


void MyWebVeiew::slotloadFinished(bool status)
{
	if (!m_WebRunTime)
	{		
		m_WebRunTime = new MyWebRuntime(nullptr);	
	}
	page()->mainFrame()->addToJavaScriptWindowObject("MyWebRunTime", m_WebRunTime);	
}