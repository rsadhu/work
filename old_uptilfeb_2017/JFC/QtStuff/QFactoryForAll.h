#pragma once
class QFactoryForAll
{
public:
	QFactoryForAll();
	static QFactoryForAll * getInstance();
	virtual ~QFactoryForAll();
};

