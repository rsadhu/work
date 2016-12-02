#include "ibexshortcuts.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iBexShortCuts w;
    w.show();

    return a.exec();
}
