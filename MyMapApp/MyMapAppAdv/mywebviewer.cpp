#include "mywebviewer.h"
#include "MyDatabaseContoller.h"
MyWebViewer::MyWebViewer(QWidget *parent)
	: QWebView(parent)
{
	ui.setupUi(this);
	resize(500, 500);
	MyDatabaseContoller::getInstance()->writeData("WebViewer", "Logged in ");
}

MyWebViewer::~MyWebViewer()
{

}

void MyWebViewer::loadPage(const QString &path)
{
	//path = "file:///c://Users//rsadhu//Desktop//maptest.html"
	QUrl url(path);
	this->load(url);
}