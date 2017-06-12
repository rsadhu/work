#pragma once
#include"ResourceInterface.h"

class ResourceMovie:public QWidget,public ResourceInterface
{
public:
	ResourceMovie(const QString &path, QWidget *parent=0);
	~ResourceMovie();
	void showResource()final;
};

