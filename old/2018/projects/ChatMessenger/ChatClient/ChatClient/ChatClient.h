#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatClient.h"
#include "ui_LoginClient.h"
#include"ChatClientPriv.h"
class ChatClient : public QMainWindow
{
	Q_OBJECT

public:
	ChatClient(QWidget *parent = Q_NULLPTR);
	~ChatClient();
protected:
	void connections();
public slots:
	void slotLogin();
	void slotClientListFetched(QStringList  );
private:
	Ui::ChatClientClass ui;
	Ui::Login loginUi;
	QDialog *m_Dial = nullptr;
	ChatClientPriv *m_ChatClientPriv = nullptr;
	bool m_ServerConnected = false;
};
