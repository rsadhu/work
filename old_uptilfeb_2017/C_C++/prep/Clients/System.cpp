#include "System.h"
#include <windows.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include<qDebug.h>
#include<Logger.h>

//  Forward declarations:
//BOOL GetProcessList();
BOOL ListProcessModules(DWORD dwPID);
BOOL ListProcessThreads(DWORD dwOwnerPID);
void printError(TCHAR* msg);

System::System()
{
}


System::~System()
{
}



unsigned long long System:: getTotalSystemMemory()
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	return status.ullTotalPhys;
}








#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

void PrintProcessNameAndID(DWORD processID)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	// Get the process name.

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
			&cbNeeded))
		{
			GetModuleBaseName(hProcess, hMod, szProcessName,
				sizeof(szProcessName) / sizeof(TCHAR));
		}
	}

	// Print the process name and identifier.

	printf("%s  (PID: %u)\n", szProcessName, processID);
	char arr[100] = { 0 };
	sprintf(arr, "%s (PID: %u)\n", szProcessName, processID);
	string s = arr;
	
	Logger::log(s);

	// Release the handle to the process.

	CloseHandle(hProcess);
}

bool System:: GetProcessList(void)
{
	// Get the list of process identifiers.

	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		return 1;
	}


	// Calculate how many process identifiers were returned.

	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the name and process identifier for each process.

	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			PrintProcessNameAndID(aProcesses[i]);
		}
	}

	return 0;
}


int System::GetDiskSpace()
{
	int hdSize = 0;
	_In_opt_  LPCTSTR         lpDirectoryName = L"D:";
	_Out_opt_ PULARGE_INTEGER lpFreeBytesAvailable=0;
	_Out_opt_ PULARGE_INTEGER lpTotalNumberOfBytes=0;
	_Out_opt_ PULARGE_INTEGER lpTotalNumberOfFreeBytes = 0;
	lpFreeBytesAvailable = (PULARGE_INTEGER)malloc(sizeof(PULARGE_INTEGER));
	lpTotalNumberOfBytes = (PULARGE_INTEGER)malloc(sizeof(PULARGE_INTEGER));
	lpTotalNumberOfFreeBytes = (PULARGE_INTEGER)malloc(sizeof(PULARGE_INTEGER));
	try{
		bool ret = GetDiskFreeSpaceEx(lpDirectoryName, lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes);
		qDebug() << "FreeBytes Available::" << (lpFreeBytesAvailable->QuadPart)/(1024*1024*1024) << endl;
		qDebug() << "TotalNumberOfBytes::" << (lpTotalNumberOfBytes->QuadPart) / (1024 * 1024*1024) << endl;
		qDebug() << "TotalNumberOfFreeBytes::" << (lpTotalNumberOfFreeBytes->QuadPart) / (1024 * 1024*1024) << endl;
		hdSize = (lpTotalNumberOfFreeBytes->QuadPart) / (1024 * 1024 * 1024);
		char *ram = new char[100];
		itoa(hdSize, ram, 10);
		string str = "RamSize::";
		str += ram;
		Logger::log(str);

		delete ram;
	}
	catch (...)
	{
		qDebug() << " Excpetion::   ";
	}

	free(lpFreeBytesAvailable);
	free(lpTotalNumberOfBytes);
	free(lpTotalNumberOfFreeBytes);
	return hdSize;
}
