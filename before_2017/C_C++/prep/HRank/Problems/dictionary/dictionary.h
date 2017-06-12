#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QtWidgets/QWidget>
#include "ui_dictionary.h"

class dictionary : public QWidget
{
	Q_OBJECT

public:
	dictionary(QWidget *parent = 0);
	~dictionary();

private:
	Ui::dictionaryClass ui;
};

#endif // DICTIONARY_H
