#ifndef MYWEBRUNTIME_H
#define MYWEBRUNTIME_H

#include <QObject>

class MyWebRuntime : public QObject
{
	Q_OBJECT

public:
	MyWebRuntime(QObject *parent);
	~MyWebRuntime();
private:
	
};

#endif // MYWEBRUNTIME_H
