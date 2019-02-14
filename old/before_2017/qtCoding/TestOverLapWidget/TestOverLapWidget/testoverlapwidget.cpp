#include "testoverlapwidget.h"

TestOverLapWidget::TestOverLapWidget(QWidget *parent)
	: QWidget(parent)
{
	this->resize(600, 800);
	mWidget = new OverLay::OverLayWidget(0);
	mWidget->setGeometry(this->width() / 2, this->height() / 2, 30, 30);
	mWidget->setStyleSheet("background:red");
	mWidget->show();
}

TestOverLapWidget::~TestOverLapWidget()
{

}
