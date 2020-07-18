#ifndef MAINDISPLAY_H
#define MAINDISPLAY_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainDisplay; }
QT_END_NAMESPACE

class MainDisplay : public QWidget
{
    Q_OBJECT

public:
    MainDisplay(QWidget *parent = nullptr);
    ~MainDisplay();

private:
    Ui::MainDisplay *ui;
};
#endif // MAINDISPLAY_H
