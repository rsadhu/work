#include "qcs.h"

QCS::QCS(QWidget *parent)
	: QWidget(parent)
{
	Logger::getInstance()->writeToFile("QCS::QCS\n");
	ui.setupUi(this);
	connect(ui.showImg, SIGNAL(clicked()), this, SLOT(slotShowImg()));
	connect(ui.showWeb, SIGNAL(clicked()), this, SLOT(slotShowWeb()));
	connect(ui.showTxt, SIGNAL(clicked()), this, SLOT(slotShowTxt()));
	connect(ui.showVid, SIGNAL(clicked()), this, SLOT(slotShowVideo()));
}



QCS::~QCS()
{
	Logger::getInstance()->writeToFile("QCS::~QCS\n");
	mAllObjects.clear();
}



void QCS::slotShowImg()
{
	ResourceInterface *iface = mFactory.getInstance("img");
	if (iface)
	{
		Logger::getInstance()->writeToFile("QCS::opening Image\n");
		iface->showResource();
		mAllObjects.append(iface);
	}
}

void QCS::slotShowWeb()
{
	ResourceInterface *iface = mFactory.getInstance("url");
	if (iface)
	{
		Logger::getInstance()->writeToFile("QCS::opening Browser\n");
		iface->showResource();
		mAllObjects.append(iface);
	}
}

void QCS::slotShowTxt()
{
	ResourceInterface *iface = mFactory.getInstance("txt");
	if (iface)
	{
		Logger::getInstance()->writeToFile("QCS::opening TextWidget\n");
		iface->showResource();
		mAllObjects.append(iface);
	}
}

void QCS::slotShowVideo()
{
	ResourceInterface *iface = mFactory.getInstance("mov");
	if (iface)
	{
		Logger::getInstance()->writeToFile("QCS::opening Video\n");
		iface->showResource();
		mAllObjects.append(iface);
	}
}