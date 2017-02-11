#include "mylayouts.h"
#include<QDragEnterEvent>
#include<QDropEvent>
#include<qmimedata.h>
#include<QTreeWidgetItem>

MyLayouts::MyLayouts(QWidget *parent,  int layoutId )
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
	mLayoutId = layoutId;	
	setAcceptDrops(true);
}

MyLayouts::~MyLayouts()
{

}



void MyLayouts::init()
{
	setStyleSheet("background-color:red");
}


void MyLayouts::mousePressEvent(QMouseEvent *event)
{

}


void MyLayouts::dragEnterEvent(QDragEnterEvent *event)
{
	if (event && event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}


void MyLayouts::dropEvent(QDropEvent *event)
{
	if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{
		QString content;
		QTreeWidget * tree = dynamic_cast<QTreeWidget*>(event->source());
		if (tree)
		{
			QList<QTreeWidgetItem*> treeWidgetItemList = tree->selectedItems();

			for (auto it = treeWidgetItemList.begin(); it != treeWidgetItemList.end(); it++)
			{
				content = (*it)->text(0);
			}
		}
	}
}
