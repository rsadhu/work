#ifndef QTTESTEXAMPLE_H
#define QTTESTEXAMPLE_H

#include <QtWidgets/QWidget>
#include "ui_qttestexample.h"
#include<QDockWidget>

class MyDocks;
class QtTestExample : public QTabWidget
{
	Q_OBJECT
public:
	QtTestExample(QTabWidget *parent = 0);
	~QtTestExample();
	void addDocks(MyDocks *);
	bool eventFilter(QObject *sender, QEvent *event);
	QPoint mPressEventPos;
	MyDocks *m[5];	
};


class MyDocks : public QDockWidget
{
	Q_OBJECT
public:
	MyDocks(QDockWidget *parent = 0);
	~MyDocks();
};

#endif // QTTESTEXAMPLE_H
