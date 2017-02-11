#include "mymapappadv.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyMapAppAdv w;
	w.show();
	return a.exec();
}
