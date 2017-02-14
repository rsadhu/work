#include "mymapappadv.h"
#include"mylayouts.h"
#include<QTreeWidgetItem>
#include<MyDatabaseContoller.h>



MyMapAppAdv::MyMapAppAdv(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);	
	init();
}

MyMapAppAdv::~MyMapAppAdv()
{

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

	QTreeWidgetItem *thirdItem = new QTreeWidgetItem();
	thirdItem->setText(0, tr("Logger"));

	QTreeWidgetItem *editorItem = new QTreeWidgetItem();
	editorItem->setText(0, tr("MediaPlayer"));

	QTreeWidgetItem *webruntme = new QTreeWidgetItem();
	webruntme->setText(0, tr("WebRunTime"));
		
	ui.treeWidget->addTopLevelItem(mapItem);
	ui.treeWidget->addTopLevelItem(thirdItem);
	ui.treeWidget->addTopLevelItem(editorItem);
	ui.treeWidget->addTopLevelItem(webruntme);		
	MyDatabaseContoller::getInstance()->writeData("MainApp","Starting ....");
	QList<QStringList> d;
	MyDatabaseContoller::getInstance()->getAllData(d);

}
