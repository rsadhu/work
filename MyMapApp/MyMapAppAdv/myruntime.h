#ifndef MYRUNTIME_H
#define MYRUNTIME_H

#include <QWidget>
class MyWebViewer;
class MyRunTime : public QWidget
{
	Q_OBJECT

public:
	MyRunTime(QWidget *parent);
	~MyRunTime();

private:	
	MyWebViewer *mWebView = nullptr;
};

#endif // MYRUNTIME_H
