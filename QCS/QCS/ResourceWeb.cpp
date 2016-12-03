#include "ResourceWeb.h"


ResourceWeb::ResourceWeb(const QString &url, QWidget *parent) :QWidget(parent)
{
	Logger::getInstance()->writeToFile("ResourceWeb::ResourceWeb");
	setResourcePath(url);
	setAttribute(Qt::WA_DeleteOnClose);
}


ResourceWeb::~ResourceWeb()
{
	Logger::getInstance()->writeToFile("ResourceWeb::~ResourceWeb");
}


void ResourceWeb::showResource()
{
	Logger::getInstance()->writeToFile("ResourceWeb::~showResource");
	QString path = getResourcePath();
	if (path.isEmpty())
		path = "https://www.qt.io";
	mWebView.load(QUrl(path));
	mWebView.show();
}