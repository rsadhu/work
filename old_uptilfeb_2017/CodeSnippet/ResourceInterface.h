#pragma once
#ifndef ResourceInterface_h
#define ResourceInterface_h
#include<qstring.h>

class ResourceInterface 
{
public:
	ResourceInterface();	
	virtual ~ResourceInterface();

	void setResourcePath(const QString &);
	QString & getResourcePath();

	virtual void showResource() = 0;
private:
	QString mSrc;
};
#endif 

