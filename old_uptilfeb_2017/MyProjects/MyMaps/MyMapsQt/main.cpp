#include "mymapsqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyMapsQt w;
	w.show();
	return a.exec();
}
