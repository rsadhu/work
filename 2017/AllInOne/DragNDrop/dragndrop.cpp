#include "dragndrop.h"
#include<qdrag.h>
#include<QDragEnterEvent>
#include<QMimeData>
#include<qlabel.h>
#include<QPushButton>

DragNDrop::DragNDrop(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	setAcceptDrops(true);
	m_hBoxLayout = new QHBoxLayout(this);
	setLayout(m_hBoxLayout);	
	QWidget *tmp = new QWidget(this);
	tmp->setStyleSheet("background:red");
	m_hBoxLayout->addWidget(tmp);
	tmp->show();
	setMinimumSize(400, 500);
	QPushButton * b = new QPushButton(this);
	connect(b, &QPushButton::clicked, [=]()
	{
		SourceW *tmp = new SourceW(0);
		//tmp->setStyleSheet("background:brown");
		//m_hBoxLayout->addWidget(tmp);
		tmp->show();
	});
	m_hBoxLayout->insertWidget(0,b);
	setStyleSheet("background:green");
}

DragNDrop::~DragNDrop()
{

}


void DragNDrop::dragEnterEvent(QDragEnterEvent *event)
{
	QWidget *src = static_cast<QWidget*>(event->source());	
	src->setParent(this);
	m_hBoxLayout->addWidget(src);	
	event->accept();
}

SourceW::SourceW(QWidget*parent) :QWidget(parent)
{
	installEventFilter(this);
	setWindowTitle("Target");
	setFixedSize(300,400);
	setStyleSheet("background:blue");
	m_hBoxLayout = new QHBoxLayout(this);
	setLayout(m_hBoxLayout);
	QLabel *l = new QLabel(this);
	l->setText("Hello");
	m_hBoxLayout->addWidget(l);
}

SourceW::~SourceW()
{

}


bool SourceW::eventFilter(QObject *src, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMimeData *data = new QMimeData();
		
		QDrag *drag = new QDrag(this);
		drag->setMimeData(data);
		drag->exec(Qt::CopyAction);
	}
	return QObject::eventFilter(src, event);
}