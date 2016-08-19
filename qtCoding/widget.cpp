#include "widget.h"
#include<QGraphicsPixmapItem>
#include<QPixmap>

#ifndef WIN32
#define PATH "/home/syilmaz/rsadhu/pix/"
#elif WIN32
#define PATH "C://Users//Public//Pictures//"
#endif


ImageViewer::ImageViewer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    QDir *d = new QDir("/home/syilmaz/rsadhu/pix");
	mList = d->entryList();
	connect(ui.prevB, SIGNAL(clicked()), this, SLOT(slotShowMePrevImage()));
	connect(ui.nextB, SIGNAL(clicked()), this, SLOT(slotShowMeNextImage()));
}

ImageViewer::~ImageViewer()
{

}



void ImageViewer::slotShowMePrevImage()
{
    if (mIndex > 2)
		mIndex--;
	showImage(mIndex);	
}


void ImageViewer::slotShowMeNextImage()
{
	if (mIndex < mList.length()-1)
		mIndex++;
	showImage(mIndex);
}

void ImageViewer::showImage(int index)
{
	QString image = mList.at(index);
	QGraphicsScene* scene = new QGraphicsScene(this);	
    ui.graphicsView->setScene(scene);


    scene->addPixmap(QPixmap(PATH + image));


	ui.graphicsView->show();
}
