#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QDebug>
#include "qmlnetworkclass.h"
#include <QtQml>

enum class TestEnum
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

QDebug operator<<(QDebug stream, const TestEnum &day) {

    switch (day)
    {
    case TestEnum::SUNDAY:
        stream << "Pazar";
        break;
    case TestEnum::MONDAY:
        stream << "Pazartesi";
        break;
    case TestEnum::TUESDAY:
        stream << "Sali";
        break;
    case TestEnum::WEDNESDAY:
        stream << "Carsembe";
        break;
    case TestEnum::THURSDAY:
        stream << "Parsembe";
        break;
    case TestEnum::FRIDAY:
        stream << "Cummah";
        break;
    case TestEnum::SATURDAY:
        stream << "Cummahtersi";
        break;
    }
    return stream;
}



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TestEnum obj = TestEnum::FRIDAY;
    qDebug()<<obj;

    QmlNetworkClass nwc;
    nwc.connectToHost(QString("http://www.google.com"),1);

    qmlRegisterType<QmlNetworkClass>("NetworkMngr.qml", 1, 0, "NetworkMngr");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
