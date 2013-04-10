#ifndef __LAYOUT_H
#define __LAYOUT_H
#include<QWidget>
#include<QPushButton>
#include<QHBoxLayout>


class Layout:public QWidget
{
    Q_OBJECT
public:
    Layout();
public slots:
    void onPress();
private:
    QPushButton play;
    QHBoxLayout *m_hlayout;
};

#endif
