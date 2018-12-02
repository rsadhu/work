#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include<QDebug>


void createMenu(const QString &profilePath)
{
    QDir profileDirectory(profilePath);
    QStringList profilesMenuIniEntries, m_profilesMenuEntries;


    profilesMenuIniEntries = profileDirectory.entryList(QStringList() << "*.ini", QDir::Files, QDir::Name);
    profilesMenuIniEntries.sort(Qt::CaseInsensitive);

    QStringListIterator profileMenuEntryIt(profilesMenuIniEntries);
    while (profileMenuEntryIt.hasNext()) {
        //m_profilesMenuEntries.append(profileMenuEntryIt.peekNext().left(profileMenuEntryIt.peekNext().lastIndexOf(".")));
        //profileMenuEntryIt.next();
        auto peeknext = profileMenuEntryIt.peekNext();
        auto next  = profileMenuEntryIt.next();
        auto ind =  profileMenuEntryIt.next().lastIndexOf(".");
        m_profilesMenuEntries.append(profileMenuEntryIt.peekNext().left(profileMenuEntryIt.next().lastIndexOf(".")));

    }
}

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

    //createMenu("/home/rsadhu/dev/carbon-ui/common/developerProfiles");

    TestEnum obj = TestEnum::FRIDAY;
    qDebug()<<obj;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
