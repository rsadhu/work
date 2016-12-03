#include "qcs.h"
#include <QtWidgets/QApplication>
#include"Logger.h"

int main(int argc, char *argv[])
{	
	QApplication a(argc, argv);
	Logger::getInstance()->writeToFile("main");
	QCS w;
	w.show();
	return a.exec();
}
