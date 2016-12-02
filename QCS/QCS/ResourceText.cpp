#include "ResourceText.h"
#include<QLabel>



ResourceText::ResourceText(const QString &src, QWidget *parent) :QWidget(parent)
{			
	setResourcePath(src);
	this->setGeometry(100, 100, 200, 200);
}


ResourceText::~ResourceText()
{
}


void ResourceText::showResource()
{
	QString str = "text is null";
	if (!getResourcePath().isEmpty())
		str = getResourcePath();
		
	QLabel *label = new QLabel((str),this);
	label->show();
	show();
}