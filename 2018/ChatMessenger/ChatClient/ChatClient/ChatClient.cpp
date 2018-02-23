#include "ChatClient.h"

ChatClient::ChatClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connections();

	m_ChatClientPriv = new ChatClientPriv;	
	
	connect(m_ChatClientPriv, SIGNAL(signalLogin()), this, SLOT(slotLogin()));

	//ui.actionLogin->setEnabled(false);
	//ui.actionLogout->setEnabled(false);
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

		
	});
}


void ChatClient::slotLogin()
{
	ui.actionLogin->setEnabled(true);
	ui.actionLogout->setEnabled(true);
}



ChatClient::~ChatClient()
{
	delete m_ChatClientPriv;
}
