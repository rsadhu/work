#include "ResourceFactory.h"
#include"ResourceImage.h"
#include"ResourceText.h"
#include"ResourceWeb.h"
#include<qfile.h>
#include<iostream>
#include<qdom.h>


ResourceFactory::ResourceFactory()
{
	mDom = new QDomDocument();
	QFile f("D:\\rsadhu\\work\\CodeSnippet\\data.xml");
	if (f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QByteArray data = f.readAll();
		mDom->setContent(data);		
	}
}


ResourceFactory::~ResourceFactory()
{
	delete mDom;
	mDom = nullptr;
}

ResourceInterface * ResourceFactory::getInstance(const QString &key) const
{
	QDomElement root = mDom->firstChildElement();
	QDomNodeList nodes = root.elementsByTagName(key);
	for (int i = 0; i < nodes.count(); i++)
	{
		QDomNode elm = nodes.at(i);
		if (elm.isElement())
		{
			QDomElement e = elm.toElement();					
			if (e.attribute("id") == "img")
			{
				return new ResourceImage(e.attribute("src"));
			}
			else 
			if (e.attribute("id") == "mov")
			{

			}
			else
			if (e.attribute("id") == "txt")
			{
				return new ResourceText(e.attribute("txt"));
			}
			else
			if (e.attribute("id") == "url")
			{
				return new ResourceWeb(e.attribute("url"));
			}			
		}
	}
	return nullptr;
}

