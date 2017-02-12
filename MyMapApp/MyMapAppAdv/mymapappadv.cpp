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
	thirdItem->setText(0, tr("Records"));

	QTreeWidgetItem *editorItem = new QTreeWidgetItem();
	editorItem->setText(0, tr("Editor"));

	QTreeWidgetItem *webruntme = new QTreeWidgetItem();
	webruntme->setText(0, tr("WebRunTime"));
		
	ui.treeWidget->addTopLevelItem(mapItem);
	ui.treeWidget->addTopLevelItem(thirdItem);
	ui.treeWidget->addTopLevelItem(editorItem);
	ui.treeWidget->addTopLevelItem(webruntme);	

	MyDatabaseContoller dbController(QString("test"));
	QString data = "INSERT INTO tbl_test ( name, address, age) VALUES(rakesh,ankara, 34)";
	dbController.insertData(data);
	QList<QStringList> d;
	dbController.getAllData(d);

	
}
