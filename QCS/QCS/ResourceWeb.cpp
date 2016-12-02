#include "ResourceWeb.h"


ResourceWeb::ResourceWeb(const QString &url, QWidget *parent) :QWidget(parent)
{
	setResourcePath(url);
}


ResourceWeb::~ResourceWeb()
{
}


void ResourceWeb::showResource()
{
	QString path = getResourcePath();
	if (path.isEmpty())
		path = "https://www.qt.io";
	mWebView.load(QUrl(path));
	mWebView.show();
}