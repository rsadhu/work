#include <iostream>
#include <dbus-c++-1/dbus-c++/dbus.h>

class Calculator : public DBus::ObjectAdaptor
{
public:
	Calculator(DBus::Connection& connection) :
		DBus::ObjectAdaptor(connection, "/org/example/Calculator") {}

	double add(double a, double b)
	{
		return a + b;
	}

	double subtract(double a, double b)
	{
		return a - b;
	}

	double multiply(double a, double b)
	{
		return a * b;
	}

	double divide(double a, double b)
	{
		return a / b;
	}
};

int main()
{
	DBus::Connection conn = DBus::Connection::SessionBus();
	Calculator calculator(conn);
	conn.request_name("org.example.CalculatorService");

	//DBus::Loop::GlibMainLoop loop;
	//loop.run();
	while(true);

	return 0;
}
