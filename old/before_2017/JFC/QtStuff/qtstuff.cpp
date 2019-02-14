#include "qtstuff.h"

QString map[] = { "QWidgets", " QThreadings ", "", "", "", "", "", "" };


QtStuff::QtStuff(QWidget *parent)
	: QWidget(parent)
{
	init();
}

QtStuff::~QtStuff()
{

}

void QtStuff::init()
{
	QPushButton *b[8];
	QHBoxLayout hlayout;
	QVBoxLayout *vlayout = new QVBoxLayout();
	this->setLayout(vlayout);
	for (int i = 0; i < 8; i++)
	{
		b[i] = new QPushButton(this);
		b[i]->setText(QCoreApplication::tr(map[i].toStdString().c_str()));		
		vlayout->addWidget(b[i]);
	}

	connect(b[0], SIGNAL(clicked()), this, SLOT(slotQWidgetStuff()));
	connect(b[1], SIGNAL(clicked()), this, SLOT(slotQThreading()));
}



void QtStuff::slotQWidgetStuff()
{

}

void QtStuff::slotQThreading()
{

}