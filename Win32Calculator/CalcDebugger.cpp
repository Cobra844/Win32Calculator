#pragma once
#include "stdafx.h"
#include "CalcDebugger.h"

RECT DebugWindowRect;

bool CalcDebugger::SetupDebugConsole()
{
	DebugLogs = "0";
	if (DebugToggle == 1)
	{
		DebugConsoleInitialized = true;
		AllocConsole();
		FILE* fDummy;
		freopen_s(&fDummy, "CONIN$", "r", stdin);
		freopen_s(&fDummy, "CONOUT$", "w", stderr);
		freopen_s(&fDummy, "CONOUT$", "w", stdout);
		system("cls");
		return true;
	}
	else return false;
}

bool CalcDebugger::LogWindowInfo(HWND WindowHandle)
{
	if (DebugConsoleInitialized)
	{
		system("cls");
		std::cout << "DEBUG:\n->Log Details:\n" << "HWND - " << WindowHandle << std::endl;
 		if (!GetWindowRect(WindowHandle, &DebugWindowRect)) { return 3; }
		std::cout << "RECT:\nLeft - " << DebugWindowRect.left << " Right - " << DebugWindowRect.right << std::endl;
		std::cout << "Top - " << DebugWindowRect.top << " Bottom - " << DebugWindowRect.bottom << std::endl;
		if (DebugLogs != "0")
		{
			std::cout << "DEBUG LOGS:" << std::endl;
			std::cout << DebugLogs;
		}
		return true;
	}
	else return false;
}

bool CalcDebugger::LogToConsole(std::string LogText)
{
	if (DebugConsoleInitialized)
	{
		DebugLogs += std::string("\n") + LogText + std::string("\n");
	}
	else return false;
}

void CalcDebugger::UpdateWindow(HWND WindowHandle, RECT WindowRect)
{
	GetClientRect(WindowHandle, &WindowRect);
	InvalidateRect(WindowHandle, &WindowRect, TRUE);
}