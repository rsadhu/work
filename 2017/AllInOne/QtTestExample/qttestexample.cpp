#include "qttestexample.h"
#include<qdrag.h>
#include"QMimeData.h"
#include<QMouseEvent>

QtTestExample::QtTestExample(QTabWidget *parent)
	: QTabWidget(parent)
{
	
//	tabBar()->installEventFilter(this);
	setMinimumSize(QSize(500, 600));
	for (int i = 0; i < 5; i++)
	{
		m[i] = new MyDocks();
		addDocks(m[i]);
	}
}

QtTestExample::~QtTestExample()
{

}


bool QtTestExample::eventFilter(QObject *sender, QEvent *event)
{ 
	if (sender == tabBar())
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *e = static_cast<QMouseEvent *>(event);
			mPressEventPos = e->pos();
		}
		else if (event->type() == QEvent::MouseMove)
		{
			QMouseEvent *e = static_cast<QMouseEvent *>(event);
			int movement = e->pos().x() - mPressEventPos.x();
			if (movement == 20)
			{
				int in = currentIndex();

				if (in >=0 && widget(in))
				{
					widget(in)->setMinimumSize(QSize(400, 400));
					widget(in)->setParent(nullptr);
					//removeTab(currentIndex());
					widget(in)->show();
				}
			}
		}
	}
	return false;
}


void 
QtTestExample::addDocks(MyDocks *dock)
{
	addTab(dock, "");;
	connect(this, &QTabWidget::tabBarDoubleClicked, [=](int index)
	{		
		m[index]->setParent(nullptr);
		m[index]->show();
		m[index]->setGeometry(geometry());
		removeTab(index);
	});
}


MyDocks::MyDocks(QDockWidget *parent) :QDockWidget(parent)
{
	QDockWidget::setFloating(false);
}


MyDocks::~MyDocks()
{

};