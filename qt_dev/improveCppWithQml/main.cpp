#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "customplugin.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    CustomPlugin cp;
//    cp.start();

    qmlRegisterType<CustomPlugin>("MyPlugin.CustomPlugin",1, 0, "CustomPlugin");
    qmlRegisterSingletonType<CustomPlugin>("CustomPluginSingleton", 1, 0, "Theme", CustomPlugin::getInstance());


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
