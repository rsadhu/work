#ifndef MYRUNTIME_H
#define MYRUNTIME_H
#include<qsysinfo.h>
#include <QWidget>
class MyWebViewer;
class MyRunTime : public QWidget
{
	Q_OBJECT

public:
	MyRunTime(QWidget *parent);
	~MyRunTime();
	void init();
signals:
	void signalCallBackToJsWorld(QString ,QString ,QString);
public slots:
	void addJSObject(); 
	void getSysInfo();
private:	
	MyWebViewer *mWebView = nullptr;
	QString systemName;
	QString cpuArchitecture;
	QString productName;	
};

#endif // MYRUNTIME_H
