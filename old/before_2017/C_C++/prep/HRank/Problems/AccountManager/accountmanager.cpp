#include "accountmanager.h"


AccountManager::AccountManager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setStyleSheet("background-color:black");
	ui.pushButton->setStyleSheet("background-color:blue");
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotTransitToMainMenu()));
	menu = nullptr;
}

AccountManager::~AccountManager()
{

}

void AccountManager::slotTransitToMainMenu()
{
	//ui.gridLayout->removeWidget(ui.lineEdit);
	//ui.gridLayout->removeWidget(ui.lineEdit_2);
	//ui.gridLayout->removeWidget(ui.lineEdit_3);
	//ui.gridLayout->removeWidget(ui.lineEdit_4);
	
	ui.pushButton->hide();
	ui.lineEdit->hide();
	ui.lineEdit_2->hide();
	ui.lineEdit_3->hide();
	ui.lineEdit_4->hide();
	if (menu)
		delete menu;
	if (!menu)
	{
		menu = new MainMenu(this);	
		menu->show();
	}

}