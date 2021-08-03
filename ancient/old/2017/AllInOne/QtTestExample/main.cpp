#include "qttestexample.h"
#include"dockwidget.h"
#include"mainwidget.h"
#include <QtWidgets/QApplication>
#include<thread>

int main(int argc, char *argv[])
{	
	QApplication a(argc, argv);
	/*QtTestExample w;
	w.show();*/

	QWidget w;
	w.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
	w.setMinimumSize(80, 80);
	w.setStyleSheet("background-color:black");
	QGridLayout *mainLay = new QGridLayout();
	w.setLayout(mainLay);
	w.show();
	


	std::this_thread::sleep_for(std::chrono::seconds(10));
	w.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
	w.show(); 
	
	
	QWidget mWid;
	mainLay->addWidget(&mWid);
	mWid.setMinimumSize(w.size());
	QGridLayout *mGridLayoutForPips = new QGridLayout();
	QWidget contentWidget, contentWidget1, contentWidget2, contentWidget3, contentWidget4;
	contentWidget.setStyleSheet("background-color:red");
	contentWidget1.setStyleSheet("background-color:grey");
	contentWidget2.setStyleSheet("background-color:blue");
	contentWidget3.setStyleSheet("background-color:yellow");
	contentWidget4.setStyleSheet("background-color:green");
	mGridLayoutForPips->addWidget(&contentWidget, 0, 2, 1, 1);
	mGridLayoutForPips->addWidget(&contentWidget1, 1, 2, 1, 1);
	mGridLayoutForPips->addWidget(&contentWidget2, 2, 0, 1, 1);
	mGridLayoutForPips->addWidget(&contentWidget3, 2, 1, 1, 1);
	mGridLayoutForPips->addWidget(&contentWidget4, 2, 2, 1, 1);

	mWid.setLayout(mGridLayoutForPips);
	mWid.show();

	return a.exec();
}

