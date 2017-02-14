#ifndef MYLOGGERVIEWER_H
#define MYLOGGERVIEWER_H

#include <QWidget>
#include "ui_myloggerviewer.h"



class MyLoggerViewer : public QWidget
{
	Q_OBJECT

public:
	MyLoggerViewer(QWidget *parent = 0);
	~MyLoggerViewer();
	void updateDataCallBack(QString&);
private:
	Ui::MyLoggerViewer ui;
};

#endif // MYLOGGERVIEWER_H
