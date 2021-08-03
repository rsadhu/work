#ifndef WindowManager_H
#define WindowManager_H

#include"window.h"

class WindowManager : public QWidget
{
    Q_OBJECT

public:
    explicit WindowManager(QWidget *parent = 0);
    ~WindowManager();
    void resizeEvent(QResizeEvent *event)
    {
       // static int cnt=10;
        //qDebug()<<event->size().width()<<"  "<<event->size().height()<<"\n"<<event->oldSize().width()<< "  "<<event->oldSize().height()<<endl;
       // w1->setGeometry();
      //  w2->setGeometry(400-cnt,400-cnt,500-cnt,500-cnt);
        float xr =  (event->oldSize().width())/(event->size().width());
        float yr =  (event->oldSize().height())/(event->size().height());
      /*  if(event->oldSize().height() < event->size().height() )
            w2->resize(400+400*xr,400+400*yr);
        else
            w2->resize(400-400*xr,400-400*yr);*/
      //  w2->resize(10+cnt,10+cnt);
       // cnt+=10;
    }
    void mousePressEvent(QMouseEvent *);
    //void dragEnterEvent(QDragEnterEvent *);
   // void dragMoveEvent(QDragMoveEvent *);

private:
    QHBoxLayout *mLayout;
    QWidget  *mCentralWidget;
    Window *mWindow;
    QWidget *w1,*w2;
};

#endif // WindowManager_H
