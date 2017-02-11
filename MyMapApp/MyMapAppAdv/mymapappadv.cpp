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
	QStringList list;
	list << "Test";
	ui.treeWidget->addTopLevelItem(new QTreeWidgetItem(list));
	
}
