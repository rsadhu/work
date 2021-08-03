#include "ChatClient.h"
#include "qmessagebox.h"
#include<QTreeWidgetItem>
#include<qpicture.h>

ChatClient::ChatClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connections();

	m_ChatClientPriv = new ChatClientPriv;	
	
	connect(m_ChatClientPriv, SIGNAL(signalLogin()), this, SLOT(slotLogin()));
	
	connect(m_ChatClientPriv, SIGNAL(signalClientListFetched(QStringList )), this, SLOT(slotClientListFetched(QStringList )));
	
}

void ChatClient::connections()
{

	connect(ui.btnReconnect, &QPushButton::pressed, [=]()
	{
		if (m_ChatClientPriv)
			m_ChatClientPriv->reConnect();
	});

	connect(ui.btnRefresh, &QPushButton::pressed, [=]()
	{
		if (m_ChatClientPriv)
			m_ChatClientPriv->refresh();
	});

	connect(ui.actionLogin, &QAction::triggered, [=]()
	{
		
		if (m_ServerConnected)
		{
			if (m_Dial)
			{
				delete m_Dial;
			}

			m_Dial = new QDialog(nullptr);
			connect(m_Dial, &QDialog::accepted, [=]()
			{
				m_ChatClientPriv->login(loginUi.leUsername->text(), loginUi.lePassword->text());
//				m_ChatClientPriv->createChatClient(1234);
			});

			loginUi.setupUi(m_Dial);
			m_Dial->show();
		}
		else
		{
			QMessageBox msg(nullptr);
			msg.setText("Server isn't up..");
			msg.exec();
		}		
	});

	connect(ui.chatClientList, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item, int col)
	{
		if (item)
		{
			auto ip = item->text(0);		
			m_ChatClientPriv->send("hello");
		}
	});
}


void ChatClient::slotLogin()
{
	m_ChatClientPriv->createChatClient(1234);
	m_ServerConnected = true;		
}

void ChatClient::slotClientListFetched(QStringList  list)
{
	QTreeWidgetItem *item = nullptr;
	ui.chatClientList->clear();
	foreach(QString ip, list)
	{	
		item = new QTreeWidgetItem();
		
	/*	QIcon    icon("D:\\rsadhu\\work\\2018\\ChatMessenger\\ChatClient\\ChatClient\\online.png");
		QPixmap *pixmap = new QPixmap("D:\\rsadhu\\work\\2018\\ChatMessenger\\ChatClient\\ChatClient\\online.png");
		
		if (!icon.isNull())
			item->setIcon(0, icon);
		else
			qDebug() << " icon couldnt created";

		QLabel *label = new QLabel();
		label->setText(ip);
			
		label->setStyleSheet("background-color:gray");

		if (label->pixmap())
		{
			if (!label->pixmap()->isNull())
			{
				item->setIcon(1, *(label->pixmap()));
			}
			else
			{
				qDebug() << " Pixmap is null\n";
			}
		}
		else
		{
			qDebug() << " Pixmap ptr is null\n";
		}*/

		item->setText(0, ip);
		ui.chatClientList->addTopLevelItem(item);
	}
}

ChatClient::~ChatClient()
{
	delete m_ChatClientPriv;
}
