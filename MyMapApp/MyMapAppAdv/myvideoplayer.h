#ifndef MYVIDEOPLAYER_H
#define MYVIDEOPLAYER_H

#include <QWidget>
#include "ui_myvideoplayer.h"
#include <vlc/vlc.h>

class MyVideoPlayer : public QWidget
{
	Q_OBJECT
public:
	MyVideoPlayer(QWidget *parent = 0);
	~MyVideoPlayer();	
	void openFile();
/*public slots :
	void play();
	void close();*/
private:
	//Ui::MyVideoPlayer ui;
	// vlc members
	libvlc_instance_t *vlcInstance;
	libvlc_media_player_t *vlcPlayer;
};

#endif // MYVIDEOPLAYER_H
