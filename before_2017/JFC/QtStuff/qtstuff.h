#ifndef QTSTUFF_H
#define QTSTUFF_H

#include <QtWidgets/QWidget>
#include "ui_qtstuff.h"

class QtStuff : public QWidget
{
	Q_OBJECT

public:
	QtStuff(QWidget *parent = 0);
	~QtStuff();
public slots:
	void slotQWidgetStuff();
	void slotQThreading();
signals:
	void test();
private:
	void init();
	
};

#endif // QTSTUFF_H
