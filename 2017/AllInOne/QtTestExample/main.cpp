#include "qttestexample.h"
#include"dockwidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QtTestExample w;
	//w.show();	
	DockWidget w;
	w.show();
	return a.exec();
}
