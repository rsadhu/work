#pragma once

#include"ResourceInterface.h"
#include"ResourceImage.h"
#include"ResourceText.h"
#include"ResourceWeb.h"


class ResourceFactory
{	
public:
	ResourceFactory();
	~ResourceFactory();
	ResourceInterface *getInstance(const QString & key) const;
private:
	QDomDocument *mDom;	

};