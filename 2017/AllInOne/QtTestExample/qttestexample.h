#ifndef QTTESTEXAMPLE_H
#define QTTESTEXAMPLE_H

#include <QtWidgets/QWidget>
#include "ui_qttestexample.h"

class QtTestExample : public QWidget
{
	Q_OBJECT

public:
	QtTestExample(QWidget *parent = 0);
	~QtTestExample();
	void dragMoveEvent(QDragMoveEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);
	
	void dropEvent(QDropEvent *event);

	void mousePressEvent(QMouseEvent *event);


private:
	Ui::QtTestExampleClass ui;
	QWidget w1;	
};

#endif // QTTESTEXAMPLE_H
