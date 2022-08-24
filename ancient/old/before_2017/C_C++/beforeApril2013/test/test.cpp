#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << " Base::Base\n"; }
	Base(int p) { cout << "Base::Base::int\n"; }
	virtual void display() { cout << " Base:: Display\n"; }
};

class Der : public Base
{
public:
	Der() : Base()
	{
		cout << " Der::Der\n";
	}
	void display()
	{
		cout << " Der::display\n";
		Base::display();
	}
};

int main(void)
{
	Base *b = new Der();
	b->display();
	return 0;
}
