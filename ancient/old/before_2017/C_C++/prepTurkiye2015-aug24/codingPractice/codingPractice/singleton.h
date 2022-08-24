#pragma once
class singleton
{
	singleton() {}
	~singleton() {}
	singleton(const singleton &);
	singleton &operator=(const singleton &);

public:
	static singleton mObj;
	static singleton *getInstance();
	void display();
};
