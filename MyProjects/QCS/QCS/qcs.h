#ifndef QCS_H
#define QCS_H

#include <QtWidgets/QWidget>
#include "ui_qcs.h"

#include"ResourceFactory.h"


class QCS : public QWidget
{
	Q_OBJECT

public:
	QCS(QWidget *parent = 0);
	~QCS();
public slots:
	void slotShowImg();
	void slotShowWeb();
	void slotShowTxt();
	void slotShowVideo();
private:
	ResourceFactory mFactory;
	Ui::QCSClass ui;
	QList<ResourceInterface *> mAllObjects;
};

#endif // QCS_H
