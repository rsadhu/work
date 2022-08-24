#include <regex>
#include <string>
#include <iostream>

int main(void)
{
	std::regex reg("\\t[a-b]*");

	std::string str{"this is a test string"};
	if (std::regex_match(str, reg))
	{
		std::cout << " yes\n";
	}
	else
	{
		std::cout << " no\n";
	}
	return 0;
}
