#ifndef MYLAYOUTS_H
#define MYLAYOUTS_H

#include <QWidget>
#include "ui_mylayouts.h"
#include"qgridlayout.h"

class MyLayouts : public QWidget
{
	Q_OBJECT

public:
	MyLayouts(QWidget *parent = 0,int layoutId=0);
	~MyLayouts();
	void init();
	void mousePressEvent(QMouseEvent *);
	void dragEnterEvent(QDragEnterEvent *);
	void dropEvent(QDropEvent *event);
private:
	Ui::MyLayouts ui;	
	int mLayoutId;
};

#endif // MYLAYOUTS_H
