#ifndef __LAYOUT_H
#define __LAYOUT_H
#include<QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>



class Layout:public QWidget
{
    Q_OBJECT
public:
    Layout();
    ~Layout();
public slots:
    void onPlayPress();
    void onPausePress();
    void onStopPress();
    void onPlayPress1();
    void onPausePress1();
    void onStopPress1();
private:
    QPushButton play,pause,stop;
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout,*downLayout,*middleLayout;
};

#endif
