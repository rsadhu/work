#include "ResourceText.h"




ResourceText::ResourceText(const QString &src, QWidget *parent) :QWidget(parent)
{		
	Logger::getInstance()->writeToFile("ResourceText::ResourceText");
	setResourcePath(src);
	this->setGeometry(100, 100, 200, 200);
	setAttribute(Qt::WA_DeleteOnClose);
}


ResourceText::~ResourceText()
{
	Logger::getInstance()->writeToFile("ResourceText::~ResourceText");
}


void ResourceText::showResource()
{
	Logger::getInstance()->writeToFile("ResourceText::showResource");
	QString str = "text is null";
	if (getResourcePath().isEmpty())
		str = getResourcePath();
		
	QLabel *label = new QLabel((str),this);
	label->show();
	show();
}