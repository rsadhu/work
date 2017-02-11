#include "mylayouts.h"


MyLayouts::MyLayouts(QWidget *parent,  int layoutId )
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
	mLayoutId = layoutId;	
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