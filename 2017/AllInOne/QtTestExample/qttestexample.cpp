#include "qttestexample.h"
#include<qdrag.h>
#include"QMimeData.h"

QtTestExample::QtTestExample(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAcceptDrops(true);	
}

QtTestExample::~QtTestExample()
{

}


void QtTestExample::dragMoveEvent(QDragMoveEvent *event)
{

}


void QtTestExample::dragEnterEvent(QDragEnterEvent *event)
{

}

void QtTestExample::dragLeaveEvent(QDragLeaveEvent *event)
{

}

void QtTestExample::dropEvent(QDropEvent *event)
{

}


void QtTestExample::mousePressEvent(QMouseEvent *event)
{

	QMimeData *mimeData = new QMimeData;
	mimeData->setText("test");

	

	QPixmap pixmap(ui.tabWidget->currentWidget()->size());

	render(&pixmap);

	QDrag *drag = new QDrag(this);
	drag->setMimeData(mimeData);
	drag->setPixmap(pixmap);

	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

}
