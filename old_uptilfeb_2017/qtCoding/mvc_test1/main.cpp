#include "widget.h"
#include <QApplication>

/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}*/




#include <QTableView>
#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTableView tableView;
    QTreeView tableView;
    MyModel myModel(0);
    tableView.setModel( &myModel );
    tableView.show();
    return a.exec();
}
