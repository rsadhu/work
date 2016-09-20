#pragma once
#include<iostream>
#include<list>
#include<vector>
using namespace std;


class ObserverPattern
{
public:
	ObserverPattern(){}
	virtual ~ObserverPattern(){}
	virtual void notify() = 0;
};

class Observee1 :public ObserverPattern
{
public:
	void notify()
	{
		cout << "I am notified ..." << this << endl;
	}
};

class Observee2 :public ObserverPattern
{
public:
	void notify()
	{
		cout << "I am notified ..." << this << endl;
	}
};


class Subject
{

public:
	void attach(ObserverPattern *observer);
	void detach(ObserverPattern *observer);
	void updateAll();
private:
	vector<ObserverPattern *> mlist;

};