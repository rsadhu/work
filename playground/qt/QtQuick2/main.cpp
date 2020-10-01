#include "common.h"
#include "qmlnetworkclass.h"
#include "testdata.h"
#include "testplugin.h"
#include <QDebug>
#include <QDir>
#include <QGuiApplication>
#include <QJSEngine>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QtQml>
#include <set>
#include <stack>
#include <unordered_map>

static QObject *
example_qobject_singletontype_provider(QQmlEngine *engine,
                                       QJSEngine *scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)
  AccessType *access = new AccessType;
  return access;
}

int main(int argc, char *argv[]) {

  QGuiApplication app(argc, argv);

  qmlRegisterType<QmlNetworkClass>("NetworkMngr.qml", 1, 0, "NetworkMngr");
  qmlRegisterType<EmployeeCard>("EmployeeCard", 1, 0, "EmployeeCard");
  qmlRegisterType<TestPlugin>("TestPlugin", 1, 0, "TestPlugin");
  qmlRegisterSingletonType<AccessType>("AccessType", 1, 0, "AccessType",
                                       example_qobject_singletontype_provider);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
