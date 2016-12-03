#include "ResourceImage.h"


ResourceImage::ResourceImage(const QString &src, QWidget *parent) :QWidget(parent)
{
	Logger::getInstance()->writeToFile("ResourceImage::ResourceImage");
	setResourcePath(src);
	setAttribute(Qt::WA_DeleteOnClose);
}


ResourceImage::~ResourceImage()
{
	Logger::getInstance()->writeToFile("ResourceImage::~ResourceImage");	
}

void ResourceImage::showResource()
{
	Logger::getInstance()->writeToFile("ResourceImage::showResource");
	
	mView.setScene(&mScene);
	mItem.setPixmap(QPixmap(getResourcePath()));	
	mScene.addItem(&mItem);	
	mView.show();
}
