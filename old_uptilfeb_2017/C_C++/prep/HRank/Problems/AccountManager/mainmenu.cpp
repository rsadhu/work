#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton->setStyleSheet("background-color:cyan");
	ui.pushButton_2->setStyleSheet("background-color:cyan");
	ui.pushButton_3->setStyleSheet("background-color:cyan");
	ui.pushButton_4->setStyleSheet("background-color:cyan");

	//mRestApiConsumer = new RestApiConsumer(this);

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotGetBalance()));

}

MainMenu::~MainMenu()
{
	//delete mRestApiConsumer;
}


void MainMenu::slotGetBalance()
{
	//mRestApiConsumer->GetBalance();
}

void MainMenu::slotWithDraw()
{

}

void MainMenu::slotChangePin()
{

}

void MainMenu::slotMiniStatement()
{

}