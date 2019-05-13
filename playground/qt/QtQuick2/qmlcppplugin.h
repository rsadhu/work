#ifndef QMLCPPPLUGIN_H
#define QMLCPPPLUGIN_H
#include <QObject>
#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel()
    {
        std::vector<int> list;
        list.push_back(19);

        m_data.push_back(list);
    }

    Q_INVOKABLE int rowCount(const QModelIndex &index) const final
    {
        return m_data.size();
    }

    Q_INVOKABLE int columnCount(const QModelIndex &index) const final
    {
        return m_data.at(0).size();
    }

    Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
    {
        if( (index.row() <= m_data.size()) &&  (index.column() <= m_data.at(index.row()).at(index.column())) )
        {
                m_data.at(index.row()).at(index.column());
        }
        else {

        }
    }
private:
    std::vector<std::vector<int>> m_data;

};

class QmlCppPlugin: public QObject
{
    Q_OBJECT
public:
    QmlCppPlugin();
};

#endif // QMLCPPPLUGIN_H
