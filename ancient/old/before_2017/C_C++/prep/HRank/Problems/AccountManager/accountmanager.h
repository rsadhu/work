#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QtWidgets/QWidget>
#include "ui_accountmanager.h"
#include "mainmenu.h"

class AccountManager : public QWidget
{
	Q_OBJECT

public:
	AccountManager(QWidget *parent = 0);
	~AccountManager();
public slots:
	void slotTransitToMainMenu();

private:
	Ui::AccountManagerClass ui;
	MainMenu *menu;
};

#endif // ACCOUNTMANAGER_H
