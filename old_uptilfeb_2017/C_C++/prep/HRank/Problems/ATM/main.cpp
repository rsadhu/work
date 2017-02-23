#include "automatictellermachine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AutomaticTellerMachine w;
	w.show();
	return a.exec();
}
