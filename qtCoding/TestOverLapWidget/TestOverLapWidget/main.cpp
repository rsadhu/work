#include "testoverlapwidget.h"
#include <QtWidgets/QApplication>
#include<QHBoxLayout>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget w1;
	w1.setStyleSheet("background:cyan");

	OverLay::OverLayWidget w(&w1);
	w.move(200, 300);
	w.update();
	
	w.show();
	w1.show();
	
	return a.exec();
}
