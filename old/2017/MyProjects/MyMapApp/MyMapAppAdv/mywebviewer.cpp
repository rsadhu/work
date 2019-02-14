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
	MyDatabaseContoller::getInstance()->writeData("WebViewer", "Logged out ");
}

void MyWebViewer::loadPage(const QString &path)
{	
	QUrl url(path);
	this->load(url);
}


void MyWebViewer::permissionRequested(QWebFrame* frame, QWebPage::Feature feature)
{
	this->page()->setFeaturePermission(frame, feature, QWebPage::PermissionPolicy::PermissionGrantedByUser);
}