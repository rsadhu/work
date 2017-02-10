#ifndef MYMAPAPP_H
#define MYMAPAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_mymapapp.h"
#include"mywebveiew.h"

class MyMapApp : public QMainWindow
{
	Q_OBJECT

public:
	MyMapApp(QWidget *parent = 0);
	~MyMapApp();

private:
	Ui::MyMapAppClass ui;
	MyWebVeiew *m_wView;
};

#endif // MYMAPAPP_H
