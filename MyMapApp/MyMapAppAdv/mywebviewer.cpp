#include "mywebviewer.h"

MyWebViewer::MyWebViewer(QWidget *parent)
	: QWebView(parent)
{
	ui.setupUi(this);
	QUrl url("file:///c://Users//rsadhu//Desktop//maptest.html");
	this->load(url);
}

MyWebViewer::~MyWebViewer()
{

}
