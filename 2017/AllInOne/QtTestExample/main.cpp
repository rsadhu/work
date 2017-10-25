#include "qttestexample.h"
#include"dockwidget.h"
#include"mainwidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtTestExample w;
	w.show();	
	///*DockWidget w;
	//w.show();*/

	//MainWidget mW;
	///*QWidget w1, w2;
	//w1.setStyleSheet("background:blue");
	//w2.setStyleSheet("background:red");
	//QHBoxLayout h;
	//mW.setLayout(&h);
	//h.addWidget(&w1);
	//h.addWidget(&w2);*/

	//mW.show();
	return a.exec();
}

