#include "automatictellermachine.h"

AutomaticTellerMachine::AutomaticTellerMachine(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotTransitToMainMenu()));
	menu = nullptr;
}

AutomaticTellerMachine::~AutomaticTellerMachine()
{

}



void AutomaticTellerMachine::slotTransitToMainMenu()
{

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