#include "qtapp.h"
#include <QtWidgets/QApplication>
#include"DisplayWidget.h"
#include<QBoxLayout>
#include<QVBoxLayout>
#include<qgridlayout.h>
#include<qpushbutton.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QWidget w;

	w.setStyleSheet("background-color:green");
	w.show();


/*	QHBoxLayout Hl;
	QVBoxLayout Vl;
	Gl.addLayout(&Hl, 1, 0);
	Gl.addLayout(&Vl, 0, 1, 2, 1);

	QWidget ws[5];
	for (int i = 0; i < 5; i++)
	{
		if (i < 3)
		{
			ws[i].setStyleSheet("background-color:red");
			Hl.addWidget(&ws[i],1,i);
		}
		else
		{
			ws[i].setStyleSheet("background-color:blue");
			Vl.addWidget(&ws[i]);
		}
		ws[i].show();
	}
	*/
	QGridLayout Gl;
	//Gl.addWidget(&w, 0, 0);
	w.setLayout(&Gl);
	

	
	QWidget *tmp = new QWidget();
	QWidget *tmp1 = new QWidget();
	QWidget *tmp2 = new QWidget();
	QWidget *tmp3 = new QWidget();
	QWidget *tmp4 = new QWidget();
	

	Gl.addWidget(tmp , 0, 2, 1, 1);
	Gl.addWidget(tmp1, 1, 2, 1, 1);
	Gl.addWidget(tmp2, 2, 0, 1, 1);
	Gl.addWidget(tmp3, 2, 1, 1, 1);
	Gl.addWidget(tmp4, 2, 2, 1, 1);
	tmp->setStyleSheet("background-color:blue");
	tmp1->setStyleSheet("background-color:blue");
	tmp2->setStyleSheet("background-color:blue");
	tmp3->setStyleSheet("background-color:blue");
	tmp4->setStyleSheet("background-color:blue");
	tmp->show();
	tmp1->show();
	tmp2->show();
	tmp3->show();
	tmp4->show();
	
	w.show();

	/*

	// Grid layout with 3 buttons
	QGridLayout *gridLayout = new QGridLayout;
	QPushButton *b1 = new QPushButton("A");
	QPushButton *b2 = new QPushButton("B");
	QPushButton *b3 = new QPushButton("C");
	QPushButton *b4 = new QPushButton("D");
	QPushButton *b5 = new QPushButton("E");
	QPushButton *b6 = new QPushButton("F");

	// addWidget(*Widget, row, column, rowspan, colspan)
	// 0th row
	gridLayout->addWidget(b1, 0, 0, 1, 1);
	gridLayout->addWidget(b2, 0, 1, 1, 1);
	gridLayout->addWidget(b3, 0, 2, 1, 1);

	// 1st row
	gridLayout->addWidget(b4, 1, 0, 1, 1);

	// 2nd row with 2-column span
	gridLayout->addWidget(b5, 2, 0, 1, 2);

	// 3rd row with 3-column span
	gridLayout->addWidget(b6, 3, 0, 1, 3);

	// Create a widget
	QWidget *w = new QWidget();

	// Set the grid layout as a main layout
	w->setLayout(gridLayout);

	// Window title
	w->setWindowTitle("Grid Layouts (3x4)");

	// Display
	w->show();*/

	return a.exec();
}
