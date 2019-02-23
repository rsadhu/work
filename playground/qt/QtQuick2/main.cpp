#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QtQml>
#include <QDebug>
#include "testdata.h"
#include "qmlnetworkclass.h"
#include "common.h"
#include "testplugin.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QmlNetworkClass>("NetworkMngr.qml", 1, 0, "NetworkMngr");
    qmlRegisterType<EmployeeCard>("EmployeeCard", 1, 0, "EmployeeCard");
    qmlRegisterType<TestPlugin>("TestPlugin", 1, 0, "TestPlugin");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
