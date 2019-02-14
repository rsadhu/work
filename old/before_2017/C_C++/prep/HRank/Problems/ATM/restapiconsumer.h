

class RestApiConsumer : public QObject
{
	Q_OBJECT

public:
	RestApiConsumer(QObject *parent);
	~RestApiConsumer();
	void GetBalance();
	void WithDraw();
	void ChangePin();
	void MiniStatement();
public slots:
	void slotReplyFinished(QNetworkReply *);
	void slotReadyRead();
	void onAuthenticationRequestSlot(QNetworkReply*, QAuthenticator*);
private:
	QNetworkAccessManager *m_netman;
	QNetworkReply *m_netReply;
	QObject *super;
	
};

#endif // RESTAPICONSUMER_H
