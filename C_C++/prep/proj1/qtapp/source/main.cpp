#ifdef QT
#include <QtCore/QCoreApplication>
#endif

#include"../include/contact.h"

int main(int argc, char *argv[])
{
#ifdef QT
QCoreApplication a(argc, argv);
#endif

    Contact c(12345,"rakesh");
    Contact d(c);
    Contact e;
    e = c;
	
#ifdef QT
 return a.exec();
#endif 

	return 0;
}
