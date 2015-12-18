#include "base.h"


void Base::init(QGraphicsScene *scene, QGraphicsPixmapItem *item, QImage *img)
{
   mScene = scene;
   mPixmapItem = item;
   mImage = img;
   this->setScene(scene);
}



