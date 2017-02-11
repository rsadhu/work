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

private:
	Ui::MyWebViewer ui;
};

#endif // MYWEBVIEWER_H
