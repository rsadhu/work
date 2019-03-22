#include "qmlnetworkclass.h"
#include<QNetworkConfigurationManager>
#include<QUrl>

QmlNetworkClass::QmlNetworkClass(QObject *parent) : QObject(parent)
{
    m_networkManager = std::make_unique<QNetworkAccessManager>();
    connect(m_networkManager.get(),&QNetworkAccessManager::networkSessionConnected,[this]()
    {
        emit resultArrived(Result::PASSED);
    });

    connect(m_networkManager.get(),&QNetworkAccessManager::finished,[this](QNetworkReply *reply)
    {
        QByteArray data = reply->readAll();
        emit responseArrived(data);
    });
}

void
QmlNetworkClass::connectToHost(const QString &h,int port)
{
    if(m_networkManager){
        QUrl url(h);
        m_networkManager->get(QNetworkRequest(url));
    }
    else {
        qDebug()<<" network manager is null"   ;
    }
}

void QmlNetworkClass::sendRequest(QByteArray &, std::function<void(QByteArray)> func)
{
    m_callable = std::move(func);
}

QQmlListProperty<QString> QmlNetworkClass::networkadaptors() const
{
    QList<QString*> listOfAdaptors;
    QNetworkConfigurationManager manager;
    QList<QNetworkConfiguration> list = manager.allConfigurations();

    for(int i = 0; i < list.length(); ++i) {
        qDebug() << list[i].isValid();
        qDebug() << list[i].bearerTypeName();
        qDebug() << list[i].bearerType();
        qDebug() << list[i].bearerTypeFamily();
        QString *newS =  new QString (list[i].bearerTypeName());
        listOfAdaptors << newS;
    }

    auto res =  QQmlListProperty<QString>(this->parent(),listOfAdaptors);
    return res;
}
