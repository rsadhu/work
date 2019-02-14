#include "tcpclient.h"
#include <QtWidgets/QApplication>
#include<qdatetime.h>
#include<thread>
#include<iostream>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	///TcpClient w;
	//w.show();

	QWidget w;
	QHBoxLayout *h = new QHBoxLayout;
	w.setLayout(h);
	QPushButton b;
	b.setText("press");
	h->addWidget(&b);
	QObject::connect(&b, &QPushButton::pressed, []()
	{
		std::thread t[10];
		
		for (int i = 0; i < 10; i++)
		{			
			t[i]= std::thread(
			[]()
			{
				static int i = 0;
				qDebug()<< "\n hello ::  " << ++i;;
			}
			);
			t[i].join();
		}
	});
	w.show();
	return a.exec();
}
