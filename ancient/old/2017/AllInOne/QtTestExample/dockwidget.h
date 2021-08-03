#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QWidget>
#include "ui_dockwidget.h"

class DockWidget : public QWidget
{
	Q_OBJECT

public:
	DockWidget(QWidget *parent = 0);
	~DockWidget();

private:
	Ui::DockWidget ui;
};

#endif // DOCKWIDGET_H
