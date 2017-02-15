#ifndef MYWEBVIEWER_H
#define MYWEBVIEWER_H

#include <QWebView>
#include "ui_mywebviewer.h"
#include<qdir.h>

class MyWebViewer : public QWebView
{
	Q_OBJECT

public:
	MyWebViewer(QWidget *parent = 0);
	~MyWebViewer();
	void loadPage(const QString &url);
public slots:
	void permissionRequested(QWebFrame*, QWebPage::Feature);
private:
	Ui::MyWebViewer ui;
};

#endif // MYWEBVIEWER_H
