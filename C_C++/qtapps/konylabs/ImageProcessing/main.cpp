#include <QApplication>
#include"imageprocessor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString image("download");
    ImageProcessor ip(image);
    ip.process();

    return a.exec();
}
