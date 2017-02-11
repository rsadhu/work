#include "mymapappadv.h"
#include"mylayouts.h"
#include<QTreeWidgetItem>


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
	QTreeWidgetItem *firstItem = new QTreeWidgetItem();
	firstItem->setText(0, tr("Browser"));
	QTreeWidgetItem *secondItem = new QTreeWidgetItem();
	secondItem->setText(0, tr("Map App"));
	QTreeWidgetItem *thirdItem = new QTreeWidgetItem();
	thirdItem->setText(0, tr("Records"));
	QTreeWidgetItem *editorItem = new QTreeWidgetItem();
	editorItem->setText(0, tr("Editor"));
	

	ui.treeWidget->addTopLevelItem(firstItem);
	ui.treeWidget->addTopLevelItem(secondItem);
	ui.treeWidget->addTopLevelItem(thirdItem);
	ui.treeWidget->addTopLevelItem(editorItem);
	
}
