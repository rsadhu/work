#ifndef WIDGETDEST_H
#define WIDGETDEST_H
#include"base.h"


class WidgetDest : public Base
{
    Q_OBJECT
public:
    WidgetDest(QWidget *parent=0);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // WIDGETDEST_H
