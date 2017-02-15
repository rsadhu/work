#include "mymapappadv.h"
#include<QTreeWidgetItem>
#include<MyDatabaseContoller.h>
#include"mylayouts.h"

MyMapAppAdv::MyMapAppAdv(QWidget *parent)
	: QMainWindow(parent)
{	
	MyDatabaseContoller::getInstance()->writeData("MainApp", "Starting ....");
	ui.setupUi(this);	
	init();	
}

MyMapAppAdv::~MyMapAppAdv()
{
	MyDatabaseContoller::getInstance()->writeData("MainApp", "Shutting Down....");	
}

void MyMapAppAdv::init()
{
	MyLayouts *layouts[4];	
	layouts[0] = new MyLayouts(ui.layout_1,1);
	layouts[1] = new MyLayouts(ui.layout_2,2);
	layouts[2] = new MyLayouts(ui.layout_3,3);
	layouts[3] = new MyLayouts(ui.layout_4,4);

	
	
	ui.widget->show();
	QTreeWidgetItem *mapItem = new QTreeWidgetItem();
	mapItem->setText(0, tr("Map-App"));

	QTreeWidgetItem *loggerItem = new QTreeWidgetItem();
	loggerItem->setText(0, tr("Logger"));

	QTreeWidgetItem *mediaplayer = new QTreeWidgetItem();
	mediaplayer->setText(0, tr("MediaPlayer"));

	QTreeWidgetItem *webruntme = new QTreeWidgetItem();
	webruntme->setText(0, tr("WebRunTime"));
		
	ui.treeWidget->addTopLevelItem(mapItem);
	ui.treeWidget->addTopLevelItem(loggerItem);	
	ui.treeWidget->addTopLevelItem(webruntme);	
	ui.treeWidget->addTopLevelItem(mediaplayer);	
}
