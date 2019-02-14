#pragma once
#include"QObject.h"

class DisplayWidget :
	public QObject
{
	Q_OBJECT
public:
	DisplayWidget();
	virtual ~DisplayWidget();
	void start();
public slots:
	void slotToTest();
	
signals:
	void signalToCheckTest();
};

