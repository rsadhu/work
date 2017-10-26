#include "dragndrop.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DragNDrop w;
	SourceW sw;
	sw.show();
	w.setSourcePtr(&sw);
	w.show();
	return a.exec();
}
