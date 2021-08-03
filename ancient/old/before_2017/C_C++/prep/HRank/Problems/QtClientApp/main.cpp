#include "qtclientapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtClientApp w("10.0.0.221","hello Data");
	w.show();
	return a.exec();
}
