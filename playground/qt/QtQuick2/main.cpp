#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include<QDebug>


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

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
