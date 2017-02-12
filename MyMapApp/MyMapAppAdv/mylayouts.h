#ifndef MYLAYOUTS_H
#define MYLAYOUTS_H

#include <QWidget>
#include "ui_mylayouts.h"
#include"qgridlayout.h"

class MyWebViewer;
class MyRunTime;

typedef enum
{
	NONE=0,
	MAP_APP,
	WEB_RUNTIME
}CONTENT;

class MyLayouts : public QWidget
{
	Q_OBJECT

public:
	MyLayouts(QWidget *parent = 0,int layoutId=0);
	~MyLayouts();		
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);	
private:
	Ui::MyLayouts ui;	
	int mLayoutId;
	CONTENT mContent;
	MyWebViewer *mWebView = nullptr;
	MyRunTime *mWebRunTime = nullptr;
};

#endif // MYLAYOUTS_H
