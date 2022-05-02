#pragma once
class CalcDebugger
{
public:
	bool SetupDebugConsole();
	bool LogWindowInfo(HWND);
	bool LogToConsole(std::string);

	void UpdateWindow(HWND, RECT);
private:
	bool DebugConsoleInitialized;
	std::string DebugLogs;
};