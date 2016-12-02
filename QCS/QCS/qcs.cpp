#include "qcs.h"

QCS::QCS(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.showImg, SIGNAL(clicked()), this, SLOT(slotShowImg()));
	connect(ui.showWeb, SIGNAL(clicked()), this, SLOT(slotShowWeb()));
	connect(ui.showTxt, SIGNAL(clicked()), this, SLOT(slotShowTxt()));
	connect(ui.showVid, SIGNAL(clicked()), this, SLOT(slotShowVideo()));
}



QCS::~QCS()
{

}



void QCS::slotShowImg()
{
	ResourceInterface *iface = mFactory.getInstance("img");
	if (iface)
	{
		iface->showResource();
	}
}

void QCS::slotShowWeb()
{
	ResourceInterface *iface = mFactory.getInstance("url");
	if (iface)
	{
		iface->showResource();
	}
}

void QCS::slotShowTxt()
{
	ResourceInterface *iface = mFactory.getInstance("txt");
	if (iface)
	{
		iface->showResource();
	}
}

void QCS::slotShowVideo()
{
	ResourceInterface *iface = mFactory.getInstance("mov");
	if (iface)
	{
		iface->showResource();
	}
}