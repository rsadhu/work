#ifndef DRAGNDROP_H
#define DRAGNDROP_H

#include <QtWidgets/QWidget>
#include "ui_dragndrop.h"
#include<qboxlayout.h>



class SourceW :public QWidget
{
	Q_OBJECT
public:
	SourceW(QWidget*parent = 0,int count=0);
	~SourceW();
	bool eventFilter(QObject *, QEvent *);	
	QHBoxLayout *m_hBoxLayout;
};


class DragNDrop : public QWidget
{
	Q_OBJECT

public:
	DragNDrop(QWidget *parent = 0);
	~DragNDrop();
	void setSourcePtr(SourceW *s){ srcPtr = s; }
private:
	void dragEnterEvent(QDragEnterEvent *);

private:
	QHBoxLayout *m_hBoxLayout;
	SourceW *srcPtr = nullptr;
	int mCounter = 0;
};


#endif // DRAGNDROP_H



