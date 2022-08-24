#include "mainmenu.h"
#include <QVBoxLayout>

MainMenu::MainMenu(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	ui.setupUi(this);
	ui.pushButton->setStyleSheet("background-color:cyan");
	ui.pushButton_2->setStyleSheet("background-color:cyan");
	ui.pushButton_3->setStyleSheet("background-color:cyan");
	ui.pushButton_4->setStyleSheet("background-color:cyan");

	ui.lineEdit->setWordWrapMode(QTextOption::WrapMode::WordWrap);
	mRestApiConsumer = new RestApiConsumer(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotGetBalance()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(slotWithDraw()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(slotChangePin()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(slotMiniStatement()));
}

MainMenu::~MainMenu()
{
}

void MainMenu::drawData(QByteArray &d)
{

	ui.lineEdit->clear();
	ui.lineEdit->setText(d.data());
}

void MainMenu::slotGetBalance()
{
	mRestApiConsumer->GetBalance();
}

void MainMenu::slotWithDraw()
{
	mRestApiConsumer->WithDraw();
}

void MainMenu::slotChangePin()
{
	mRestApiConsumer->ChangePin();
}

void MainMenu::slotMiniStatement()
{
	mRestApiConsumer->MiniStatement();
}