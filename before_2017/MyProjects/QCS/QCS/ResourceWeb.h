#pragma once

#include"ResourceInterface.h"

class ResourceWeb :public QWidget, public ResourceInterface
{
	Q_OBJECT
public:
	ResourceWeb(const QString &url, QWidget *parent=0);
	~ResourceWeb();
	void showResource()final;
private:
	QWebView mWebView;
};

