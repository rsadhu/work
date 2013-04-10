#include<QApplication>
#include"inc/layout.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Layout lay;
    lay.show();
    return app.exec();
}
