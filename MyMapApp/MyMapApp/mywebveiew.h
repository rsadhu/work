#ifndef MYWEBVEIEW_H
#define MYWEBVEIEW_H

#include <QWebView>
#include "ui_mywebveiew.h"
#include"mywebruntime.h"

class MyWebVeiew : public QWebView
{
	Q_OBJECT

public:
	MyWebVeiew(QWidget *parent = 0);
	~MyWebVeiew();
public slots:
	void slotloadFinished(bool status);

private:
	Ui::MyWebVeiew ui;
	MyWebRuntime *m_WebRunTime = nullptr;
};

#endif // MYWEBVEIEW_H
