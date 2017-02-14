#ifndef MYLOGGERVIEWER_H
#define MYLOGGERVIEWER_H

#include <QWidget>
#include "ui_myloggerviewer.h"
#include"MyDatabaseContoller.h"
#include<QTimer>


class MyLoggerViewer : public QWidget
{
	Q_OBJECT

public:
	MyLoggerViewer(QWidget *parent = 0);
	~MyLoggerViewer();		
protected:
	void initUI();
public slots:
	void slotUpdateLogs(Data);
	void slotCheckLogsAgain();
private:		
	Ui::MyLoggerViewer ui;	
	static int m_tableCounter;
	QTimer *mTimer = nullptr;
};

Q_DECLARE_METATYPE(Data);
#endif // MYLOGGERVIEWER_H
