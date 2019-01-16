#ifndef QMLNETWORKCLASS_H
#define QMLNETWORKCLASS_H

#include <QObject>
#include<functional>
#include<QNetworkAccessManager>
#include<QByteArray>
#include<QNetworkReply>
#include<memory>
#include<QQmlListProperty>

enum class Result{
    FAILED,
    PASSED
};

class TestData : public QObject {
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_OBJECT
public:
    explicit TestData(QObject *parent=nullptr){
        Q_UNUSED(parent)
    }

    TestData(const TestData &rhs)
    {
        m_name = rhs.m_name;
    }

    QString name () const { return m_name;}
    void setName(const QString &name) { if(name!=m_name) {m_name =  name; emit nameChanged(m_name);}}
    Q_SIGNAL void nameChanged(const QString& name);
private:
    QString m_name;
};

class QmlNetworkClass : public QObject
{
    Q_PROPERTY(QQmlListProperty<QString> networkadaptors READ networkadaptors NOTIFY networkadaptorsChanged)
    Q_PROPERTY(TestData* testD  READ testData)
    Q_OBJECT
public:
    explicit QmlNetworkClass(QObject *parent = nullptr);

    Q_INVOKABLE void connectToHost(const QString &, int port);
    Q_INVOKABLE void sendRequest(QByteArray &,std::function<void(QByteArray)> func);

    QQmlListProperty<QString> networkadaptors() const;
    TestData *testData()
    {
        auto m_data =  new TestData;
        m_data->setName("PackChik PackChick Raja Babu");
        return m_data;
    }

signals:
    void responseArrived(QByteArray &response);
    void resultArrived(Result result);
    void networkadaptorsChanged(const QString adaptor);
private:
    std::unique_ptr<QNetworkAccessManager> m_networkManager;
    std::function<void(QByteArray)> m_callable;
};
#endif // QMLNETWORKCLASS_H
