// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Pelco Headers
#include "PelcoSDK/System.h"
#include "PelcoSDK/SystemCollection.h"
using namespace PelcoSDK;

int main()
{

	std::string username = "admin";
	std::string password = "admin";
	std::string nvrIp = "10.0.5.5";
	int portNumber = 8000;

	SystemCollection systemCollection;
	if (systemCollection.GetCount())
	{
		try
		{
			// Attempt to get the system by its alias.
			PelcoSDK::PString systemAlias("admin");
			PelcoSDK::System system = systemCollection.GetItemByKey(systemAlias);

			PelcoSDK::PString u(username);
			PelcoSDK::PString p(password);

			// Login In
			system.Login(u, p);
		}
		catch (...)
		{
			throw;
		}
	}
	return 0;
}
