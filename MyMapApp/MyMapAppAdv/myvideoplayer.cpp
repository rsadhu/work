#include "myvideoplayer.h"
#include"MyDatabaseContoller.h"


MyVideoPlayer::MyVideoPlayer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	vlcPlayer = NULL;	
	vlcInstance = libvlc_new(0, NULL);	
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(play()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(stop()));
	openFile();
	resize(500, 500);
	MyDatabaseContoller::getInstance()->writeData("VideoPlayer", "Logged in ");
}

MyVideoPlayer::~MyVideoPlayer()
{
	if (vlcInstance)
		libvlc_release(vlcInstance);
	MyDatabaseContoller::getInstance()->writeData("VideoPlayer", "Logged out ");
}


void MyVideoPlayer::openFile()
{
	QString fileName = "D:\\rsadhu\\work\\MyMapApp\\MyMapAppAdv\\Resources\\vfile.avi";
	
	libvlc_media_t *vlcMedia = libvlc_media_new_path(vlcInstance, fileName.toUtf8().constData());
	if (!vlcMedia)
		return;

	/* Create a new libvlc player */
	vlcPlayer = libvlc_media_player_new_from_media(vlcMedia);

	/* Release the media */
	libvlc_media_release(vlcMedia);
	/* Integrate the video in the interface */
#if defined(Q_OS_MAC)
	libvlc_media_player_set_nsobject(vlcPlayer, (void *)videoWidget->winId());
#elif defined(Q_OS_UNIX)
	libvlc_media_player_set_xwindow(vlcPlayer, videoWidget->winId());
#elif defined(Q_OS_WIN)
	libvlc_media_player_set_hwnd(vlcPlayer, (void *)ui.widget->winId());
#endif

	/* And start playback */
	libvlc_media_player_play(vlcPlayer);

}

void MyVideoPlayer::play()
{
	if (!vlcPlayer)
		return;		

	libvlc_media_player_play(vlcPlayer);
	ui.pushButton_2->setText("Pause");
}

void MyVideoPlayer::close()
{
	if (!vlcPlayer)
		return;

	if (libvlc_media_player_is_playing(vlcPlayer))
	{		
		libvlc_media_player_pause(vlcPlayer);
		ui.pushButton->setText("Play");
	}
}