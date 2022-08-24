#pragma once

#include <QObject>
#include <qdom.h>
#include "ResourceInterface.h"

class ResourceFactory
{
public:
	ResourceFactory();
	~ResourceFactory();
	ResourceInterface *getInstance(const QString &key) const;

private:
	QDomDocument *mDom;
};