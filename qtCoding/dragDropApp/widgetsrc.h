#ifndef WIDGETSRC_H
#define WIDGETSRC_H

#include"base.h"

class WidgetSrc : public Base
{
public:
    WidgetSrc(QWidget *parent =0);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);

};

#endif // WIDGETSRC_H
