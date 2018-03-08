#pragma once

#include <QtWidgets/QWidget>
#include "ui_ModelBasedClasses.h"

class ModelBasedClasses : public QWidget
{
	Q_OBJECT

public:
	ModelBasedClasses(QWidget *parent = Q_NULLPTR);

private:
	Ui::ModelBasedClassesClass ui;
};
