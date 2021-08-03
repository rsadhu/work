#ifndef IBEXSHORTCUTS_H
#define IBEXSHORTCUTS_H

#include <QDialog>
#include<QtXML>

namespace Ui {
class iBexShortCuts;
}

class iBexShortCuts : public QDialog
{
    Q_OBJECT

public:
    explicit iBexShortCuts(QWidget *parent = 0);
    ~iBexShortCuts();
    void init();
    void retrievElements(QDomElement root, QString tag, QString att);

private:
    Ui::iBexShortCuts *ui;
    QDomDocument *m_Document;
};

#endif // IBEXSHORTCUTS_H
