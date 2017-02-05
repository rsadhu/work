#include "qtstuff.h"
#include <QtWidgets/QApplication>
#include <QHBoxLayout>
#include<QVBoxLayout>
#include<qgridlayout.h>
#include<QPushButton>
#include<QTranslator>
#include<qmap.h>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtStuff w;
	w.show();

	return a.exec();
}
