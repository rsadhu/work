#include "mywebviewer.h"

MyWebViewer::MyWebViewer(QWidget *parent)
	: QWebView(parent)
{
	ui.setupUi(this);
	resize(500, 500);
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