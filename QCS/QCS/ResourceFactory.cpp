#include "ResourceFactory.h"


ResourceFactory::ResourceFactory()
{
	Logger::getInstance()->writeToFile("ResourceFactory::ResourceFactory\n");
	mDom = new QDomDocument();
	QFile f("D:\\rsadhu\\work\\CodeSnippet\\data.xml");
	if (f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QByteArray data = f.readAll();
		mDom->setContent(data);		
		Logger::getInstance()->writeToFile("ResourceFactory::ResourceFactory:: successfully  opened xml\n");
	}
	else
	{
		Logger::getInstance()->writeToFile("ResourceFactory::ResourceFactory:: failed to open xml\n");
	}
}


ResourceFactory::~ResourceFactory()
{
	Logger::getInstance()->writeToFile("ResourceFactory::~ResourceFactory\n");
	delete mDom;
	mDom = nullptr;
}

ResourceInterface * ResourceFactory::getInstance(const QString &key) const
{
	Logger::getInstance()->writeToFile("ResourceFactory::getInstance::factory method\n");
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
				return new ResourceText(e.attribute("src"));
			}
			else
			if (e.attribute("id") == "url")
			{
				return new ResourceWeb(e.attribute("src"));
			}			
		}
	}
	return nullptr;
}

