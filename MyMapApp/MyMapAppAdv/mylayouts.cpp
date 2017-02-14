#include "mylayouts.h"
#include<QDragEnterEvent>
#include<QDropEvent>
#include<qmimedata.h>
#include<QTreeWidgetItem>
#include<qdebug.h>
#include<mywebviewer.h>
#include<myruntime.h>
#include"myvideoplayer.h"
#include"myloggerviewer.h"



MyLayouts::MyLayouts(QWidget *parent,  int layoutId )
	: QWidget(parent)
{
	ui.setupUi(this);	
	mLayoutId = layoutId;	
	setAcceptDrops(true);
	setMinimumSize(QSize(500, 500));
}

MyLayouts::~MyLayouts()
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
	
			if (content == "Logger")
			{				
				qDebug() << content;				
				mLoggerViewer = new MyLoggerViewer(this);
				mLoggerViewer->show();
				mContent = LOGGER;				
			}
			else
			if (content == "Map-App")
			{
				qDebug() << content;
				mWebView = new MyWebViewer(this);
				mWebView->loadPage("file:///c://Users//rsadhu//Desktop//maptest.html");
				mWebView->show();
				mContent = MAP_APP;				
			}
			else
			if (content == "MediaPlayer")
			{
				qDebug() << content;
				mVideolPlayer = new MyVideoPlayer(this);
				mVideolPlayer->show();
				mContent = VIDEO_PLAYER;				

			}
			else if(content=="WebRunTime")
			{
				qDebug() << content;
				mWebRunTime = new MyRunTime(this);
				mWebRunTime->show();
				mContent = WEB_RUNTIME;				
			}
		}
	}
}
