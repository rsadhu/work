#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base::Base\n";
		foo();
	}
	virtual ~Base() { cout << "Base::~Base\n"; }
	virtual void foo() { cout << " Base::Foo\n"; }
	void test() { foo(); }
};

class Der : public Base
{
public:
	Der()
	{
		cout << "Der::Der\n";
		foo();
	}
	void foo() { cout << " Der:: foo\n"; }
	~Der() { cout << "Der::~Der\n"; }
};

int main(void)
{
	Base *p = new Der();
	p->foo();
	p->test();

	return 0;
}
