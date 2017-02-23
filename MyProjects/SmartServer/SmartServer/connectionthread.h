#ifndef CONNECTIONTHREAD_H
#define CONNECTIONTHREAD_H

#include <QThread>

class ConnectionThread : public QThread
{
	Q_OBJECT

public:
	ConnectionThread(QObject *parent);
	~ConnectionThread();
	void run();
private:
	
};

#endif // CONNECTIONTHREAD_H
