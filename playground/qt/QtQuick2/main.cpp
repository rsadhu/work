#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QtQml>
#include <QDebug>
#include "testdata.h"
#include "qmlnetworkclass.h"

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

    qmlRegisterType<QmlNetworkClass>("NetworkMngr.qml", 1, 0, "NetworkMngr");
    qmlRegisterType<EmployeeCard>("EmployeeCard", 1, 0, "EmployeeCard");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
