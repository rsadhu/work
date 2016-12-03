#include "ResourceInterface.h"


ResourceInterface::ResourceInterface()
{
}


ResourceInterface::~ResourceInterface()
{
}



void ResourceInterface::setResourcePath(const QString &src)
{
	mSrc = src;
}


QString & ResourceInterface:: getResourcePath() 
{
	return mSrc;
}