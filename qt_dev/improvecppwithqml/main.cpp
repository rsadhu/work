#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <map>
#include <QMap>
#include <vector>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //std::multimap<int, std::vector<int>>aa;
    //aa.insert(1, {22,2});
    QMap<int, int> mmp;

    QMultiMap<int,int> m;
    m.insert(1,3);
    m.insert(1,4);


    return app.exec();
}
