#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QtWidgets/QWidget>
#include "ui_widget.h"
#include<QDir>

class ImageViewer : public QWidget
{
	Q_OBJECT

public:
	ImageViewer(QWidget *parent = 0);
	~ImageViewer();
public slots:
	void slotShowMePrevImage();
	void slotShowMeNextImage();
private:
	void showImage(int index);
private:
	Ui::ImageViewerClass ui;
	QStringList mList;
    int mIndex = 2;
};

#endif // IMAGEVIEWER_H
