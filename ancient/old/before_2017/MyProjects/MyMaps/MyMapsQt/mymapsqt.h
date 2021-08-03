#ifndef MYMAPSQT_H
#define MYMAPSQT_H

#include <QtWidgets/QWidget>
#include<QWebView>
#include "ui_mymapsqt.h"

class MyMapsQt : public QWebView
{
	Q_OBJECT

public:
	MyMapsQt(QWebView *parent = 0);
	~MyMapsQt();
public slots:
	void slotLoadFinished(bool st);
	void slotLoadProgress(int pr);
private:
	Ui_MyMapsQtClass ui;

};

#endif // MYMAPSQT_H
