#include "mymapapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyMapApp w;
	w.show();
	return a.exec();
}
