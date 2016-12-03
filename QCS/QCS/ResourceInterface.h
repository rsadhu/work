#pragma once
#ifndef ResourceInterface_h
#define ResourceInterface_h
#include<qstring.h>
#include"Logger.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QLabel>
#include<qwebview.h>
#include<qwidget.h>
#include <QObject>
#include<qdom.h>


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

