#ifndef QTAPP_H
#define QTAPP_H

#include <QtWidgets/QWidget>
#include "ui_qtapp.h"

class QtApp : public QWidget
{
	Q_OBJECT

public:
	QtApp(QWidget *parent = 0);
	~QtApp();

private:
	Ui::QtAppClass ui;
};

#endif // QTAPP_H
