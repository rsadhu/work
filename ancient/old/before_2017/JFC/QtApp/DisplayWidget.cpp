#include "DisplayWidget.h"

#include<iostream>

DisplayWidget::DisplayWidget()
{
	QObject::connect(this, SIGNAL(signalToCheckTest()), this, SLOT(slotToTest()), Qt::UniqueConnection);
	QObject::connect(this, SIGNAL(signalToCheckTest()), this, SLOT(slotToTest()));

	/*QObject::connect(this, &DisplayWidget::signalToCheckTest, this, []()
	{
		std::cout << "  hit slot::\n";
	}
	);*/

}


DisplayWidget::~DisplayWidget()
{
}

void DisplayWidget::start()
{
	emit signalToCheckTest();
}

void DisplayWidget::slotToTest()
{
	std::cout << "  hit slot::\n";
}