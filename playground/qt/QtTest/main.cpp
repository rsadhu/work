#include "qttest.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  QtTest test;

  return a.exec();
}
