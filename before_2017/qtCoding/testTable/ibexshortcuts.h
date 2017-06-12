#ifndef IBEXSHORTCUTS_H
#define IBEXSHORTCUTS_H

#include <QWidget>

namespace Ui {
class ibexShortCuts;
}

class ibexShortCuts : public QWidget
{
    Q_OBJECT

public:
    explicit ibexShortCuts(QWidget *parent = 0);
    ~ibexShortCuts();

private:
    Ui::ibexShortCuts *ui;
};

#endif // IBEXSHORTCUTS_H
