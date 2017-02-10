#include "mymapapp.h"
#include<qdir.h>

MyMapApp::MyMapApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);	
	m_wView = new MyWebVeiew();
	this->setCentralWidget(m_wView);
	//QUrl url("http://www.google.com");
	QUrl url(QDir::toNativeSeparators("file:\\\c:\\Users\\rsadhu\\Desktop\\maptest.html"));
	m_wView->load(url);
	m_wView->show();
}

MyMapApp::~MyMapApp()
{

}

