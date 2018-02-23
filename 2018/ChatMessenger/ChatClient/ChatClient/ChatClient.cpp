#include "ChatClient.h"
#include "qmessagebox.h"
#include<QTreeWidgetItem>

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
	
	});
}


void ChatClient::slotLogin()
{
	m_ServerConnected = true;	
}

void ChatClient::slotClientListFetched(QStringList  list)
{

	foreach(QString item, list)
	{	
		ui.chatClientList->addTopLevelItem(new QTreeWidgetItem(QStringList(item)));
	}
}

ChatClient::~ChatClient()
{
	delete m_ChatClientPriv;
}
