#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "ui_mainmenu.h"
#include "restapiconsumer.h"

class MainMenu : public QWidget
{
	Q_OBJECT

public:
	MainMenu(QWidget *parent = 0);
	~MainMenu();
public slots:
	void slotGetBalance();
	void slotWithDraw();
	void slotChangePin();
	void slotMiniStatement();

private:
	Ui::MainMenu ui;
	// RestApiConsumer *mRestApiConsumer;
};

#endif // MAINMENU_H
