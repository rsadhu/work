#pragma once
#include "windows.h"
#include "psapi.h"
#include "TCHAR.h"
#include "pdh.h"


class MySystem
{
public:
	MySystem();
	~MySystem();

	int getRAMSize();
};

