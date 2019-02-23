#ifndef QMLCPPPLUGIN_H
#define QMLCPPPLUGIN_H
#include <QObject>
#include <QAbstractListModel>

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:

};

class QmlCppPlugin: public QObject
{
    Q_OBJECT
public:
    QmlCppPlugin();
};

#endif // QMLCPPPLUGIN_H
