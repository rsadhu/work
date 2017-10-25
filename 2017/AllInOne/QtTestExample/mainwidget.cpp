#include "mainwidget.h"
#include<qpainter.h>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{	
	setMinimumSize(QSize(500, 600));
	w1 = new ChildWidget("background:blue",0);
	w2 = new ChildWidget("background:red",0);
	QBoxLayout *h = new QHBoxLayout();
	setLayout(h);
	/*h->addWidget(w1);
	h->addWidget(w2);*/
	w1->show();
	w2->show();
}

MainWidget::~MainWidget()
{
	//delete w1, w2;
}


ChildWidget::ChildWidget(const QString &style,QWidget *parent) :QWidget(parent)
{
	setStyleSheet(style);
	/*setWindowTitle("ChildWidget");
	setSizePolicy(QSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding));
	QHBoxLayout *h = new QHBoxLayout(this);
	this->setLayout(h);*/
	update();
}



ChildWidget::~ChildWidget()
{
	
}


//void paint(QPaintEvent*painter)
//{
//	QPainter paitner;
//	//painter
//
//}

//void ChildWidget::mousePressEvent(QMouseEvent *)
//{
//
//}