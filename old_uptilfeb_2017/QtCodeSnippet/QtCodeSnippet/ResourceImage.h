#pragma once
#include"ResourceInterface.h"
#include<qwidget.h>

class ResourceImage : public QWidget, public ResourceInterface
{
public:
	ResourceImage(const QString &src,QWidget *parent=0);
	~ResourceImage();
	void showResource();;
};

