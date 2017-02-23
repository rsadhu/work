#include "overlaywidget.h"
#include<qlabel.h>
#include<qpainter.h>
#include"qbrush.h"
#include<qcolor.h>
using namespace OverLay;

OverLayWidget::OverLayWidget(QWidget *parent)
	: QWidget(parent)
{
	//this->setStyleSheet("background-color:red");	
}

OverLayWidget::~OverLayWidget()
{

}


void OverLayWidget::paintEvent(QPaintEvent  *event)
{
	QPainter painter(this);
	//paint.setBackgroundMode(Qt::BGMode::TransparentMode);
	painter.fillRect(rect(), QBrush(QColor(255, 255, 255, 0)));
	painter.setPen(Qt::blue);
	painter.setFont(QFont("Arial", 30));
	painter.drawText(rect(), Qt::AlignCenter, "Qt");

}

void OverLayWidget::resizeEvent(QResizeEvent *event)
{

}


