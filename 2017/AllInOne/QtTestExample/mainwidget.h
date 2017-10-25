#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "ui_mainwidget.h"


class ChildWidget;
class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

private:
	ChildWidget *w1, *w2;
};


class ChildWidget : public QWidget
{
	Q_OBJECT
public:
	ChildWidget(const QString &style,QWidget *parent = nullptr);
	~ChildWidget();
	/*QSize sizeHint()
	{
		return QSize(250, 600);
	}*/

	QSize minimumSizeHint()
	{
		return QSize(250, 600);
	}

	//void paint(QPaintEvent *painter);
	
};



#endif // MAINWIDGET_H
