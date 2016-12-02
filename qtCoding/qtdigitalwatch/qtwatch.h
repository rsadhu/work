#ifndef QTWATCH_H
#define QTWATCH_H
#include<QLCDNumber>
#include <QObject>

class QtWatch : public QLCDNumber
{
    Q_OBJECT
public:
    QtWatch(QWidget *parent = 0);
public slots:
    void slotShowTime();
};

#endif // QTWATCH_H
