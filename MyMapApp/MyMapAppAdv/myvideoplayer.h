#ifndef MYVIDEOPLAYER_H
#define MYVIDEOPLAYER_H

#include <QWidget>
#include "ui_myvideoplayer.h"

class MyVideoPlayer : public QWidget
{
	Q_OBJECT

public:
	MyVideoPlayer(QWidget *parent = 0);
	~MyVideoPlayer();

private:
	Ui::MyVideoPlayer ui;
};

#endif // MYVIDEOPLAYER_H
