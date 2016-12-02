#include "qcs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCS w;
	w.show();
	return a.exec();
}
