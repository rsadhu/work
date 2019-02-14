#ifndef Wi_H
#define Wi_H

#include <QWidget>
#include <QEvent>

#include<QDrag>
#include<QMouseEvent>
#include<QMimeData>

namespace Ui {
class wi;
}

class wi : public QWidget
{
    Q_OBJECT

public:
    explicit wi(QWidget *parent = 0);
    ~wi();

private:
    Ui::wi *ui;

protected:
        void dropEvent(QDropEvent *event);
        void dragEnterEvent(QDragEnterEvent *event);
        void mousePressEvent(QMouseEvent* event);
};

#endif // Wi_H
