#include "ResourceImage.h"
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsPixmapItem>
#include <QPixmap>

ResourceImage::ResourceImage(const QString &src, QWidget *parent) : QWidget(parent)
{
	setResourcePath(src);
}

ResourceImage::~ResourceImage()
{
}

void ResourceImage::showResource()
{
	QGraphicsScene *scene = new QGraphicsScene(this);
	QGraphicsView *view = new QGraphicsView(scene);
	QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap(getResourcePath()));
	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(item);
	scene->addItem(i);
	view->show();
}
