#include "rtspplayer.h"
#include <QtWidgets/QApplication>
#include"videoplayer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	rtspPlayer w;
	w.show();

	//VideoPlayer player;
//	player.resize(320, 240);
	//player.show();
	return a.exec();
}
