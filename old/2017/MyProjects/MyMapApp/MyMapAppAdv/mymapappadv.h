#ifndef MYMAPAPPADV_H
#define MYMAPAPPADV_H

#include <QtWidgets/QMainWindow>
#include "ui_mymapappadv.h"

class MyMapAppAdv : public QMainWindow
{
	Q_OBJECT

public:
	MyMapAppAdv(QWidget *parent = 0);
	~MyMapAppAdv();
	void init();

private:
	Ui::MyMapAppAdvClass ui;	
	QGridLayout *mLayout;		
};

#endif // MYMAPAPPADV_H
