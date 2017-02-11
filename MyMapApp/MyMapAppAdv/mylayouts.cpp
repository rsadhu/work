#include "mylayouts.h"
#include<QDragEnterEvent>
#include<QDropEvent>
#include<qmimedata.h>
#include<qsizepolicy.h>

MyLayouts::MyLayouts(QWidget *parent,  int layoutId )
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
	mLayoutId = layoutId;	
	setAcceptDrops(true);
}

MyLayouts::~MyLayouts()
{

}



void MyLayouts::init()
{
	setStyleSheet("background-color:red");
}


void MyLayouts::mousePressEvent(QMouseEvent *event)
{

}


void MyLayouts::dragEnterEvent(QDragEnterEvent *event)
{
	if (event && event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}


void MyLayouts::dropEvent(QDropEvent *event)
{
	if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{
		
	}
}
