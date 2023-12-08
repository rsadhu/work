#include <iostream>
#include <dbus-c++-1/dbus-c++/dbus.h>

class Calculator : public DBus::ObjectProxy
{
public:
	Calculator(DBus::Connection& connection) :
		DBus::ObjectProxy(connection, "/org/example/Calculator", "org.example.CalculatorService") {}

	double add(double a, double b)
	{
		return call_method<double>("add", a, b);
	}

	double subtract(double a, double b)
	{
		return call_method<double>("subtract", a, b);
	}

	double multiply(double a, double b)
	{
		return call_method<double>("multiply", a, b);
	}

	double divide(double a, double b)
	{
		return call_method<double>("divide", a, b);
	}
};

int main()
{
	DBus::Connection conn = DBus::Connection::SessionBus();
	Calculator calculator(conn);

	std::cout << calculator.add(2, 3) << std::endl;        // prints 5.0
	std::cout << calculator.subtract(7, 4) << std::endl;   // prints 3.0
	std::cout << calculator.multiply(3, 5) << std::endl;   // prints 15.0
	std::cout << calculator.divide(10, 2) << std::endl;    // prints 5.0

	return 0;
}
