#ifndef TESTOVERLAPWIDGET_H
#define TESTOVERLAPWIDGET_H

#include "ui_testoverlapwidget.h"
#include"OverLayWidget.h"

class TestOverLapWidget : public QWidget
{
	Q_OBJECT

public:
	TestOverLapWidget(QWidget *parent = 0);
	~TestOverLapWidget();

private:
	OverLay::OverLayWidget *mWidget;
};

#endif // TESTOVERLAPWIDGET_H
