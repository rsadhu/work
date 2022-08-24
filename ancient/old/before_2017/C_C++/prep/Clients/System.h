#pragma once
class System
{
public:
	System();
	~System();
	unsigned long long getTotalSystemMemory();
	bool GetProcessList();
	int GetDiskSpace();
};
