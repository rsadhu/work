#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QWidget>
#include "ui_myplayer.h"

%NAMESPACE_BEGIN%class MyPlayer : public QWidget
{
    Q_OBJECT

public:
    MyPlayer(QWidget *parent = 0);
    ~MyPlayer();

private:
    Ui::MyPlayer ui;
};

%NAMESPACE_END%#endif // MYPLAYER_H
