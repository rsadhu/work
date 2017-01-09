#pragma once
#include"ResourceInterface.h"

class ResourceText : public QWidget, public ResourceInterface
{
	Q_OBJECT
public:
	ResourceText(const QString &src,QWidget *parent=0);
	~ResourceText();
	void showResource() final;
};

