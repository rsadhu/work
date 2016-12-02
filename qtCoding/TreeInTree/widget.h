#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTreeWidget>
#include<QTreeWidgetItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTreeWidget *m_Tree;
    QTreeWidgetItem *m_TreeItem;
};

#endif // WIDGET_H
