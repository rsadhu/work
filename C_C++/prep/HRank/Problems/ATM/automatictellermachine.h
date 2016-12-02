#ifndef AUTOMATICTELLERMACHINE_H
#define AUTOMATICTELLERMACHINE_H

#include <QtWidgets/QWidget>
#include "ui_automatictellermachine.h"
#include"mainmenu.h"

class AutomaticTellerMachine : public QWidget
{
	Q_OBJECT

public:
	AutomaticTellerMachine(QWidget *parent = 0);
	~AutomaticTellerMachine();
public slots:
	void slotTransitToMainMenu();

private:
	Ui::AutomaticTellerMachineClass ui;
	MainMenu *menu;
};

#endif // AUTOMATICTELLERMACHINE_H
