// Win32 Calculator - Cobra844 - Cobra#3081

#include "stdafx.h"

#include "CalcDebugger.h"

#include "CalcLogic.h"

HWND Button0Handle, Button1Handle, Button2Handle, Button3Handle, Button4Handle, Button5Handle, Button6Handle, Button7Handle, Button8Handle, Button9Handle;
HWND PlusButtonHandle, MinusButtonHandle, MultiplyButtonHandle, DivideButtonHandle, EqualButtonHandle;
WNDCLASSEX WindowClass = { 0 }; // Window Class used for Calculator Window
MSG WindowMessage = { 0 }; // Initializing Variable used for Window Messages

CalcDebugger Debug; // Initializes Debugger Object
CalcLogic Logic; // Initializes Logic Object

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, INT)
{
	WindowClass.cbSize = sizeof(WNDCLASSEX);
	WindowClass.lpfnWndProc = WindowProcedure;
	WindowClass.lpszClassName = WindowClassName;
	WindowClass.lpszMenuName = WindowMenuName;
	WindowClass.cbClsExtra = NULL;
	WindowClass.cbWndExtra = NULL;
	WindowClass.hInstance = HInstance;
	WindowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WindowClass.hIconSm = NULL;
	WindowClass.style = NULL;

	if (!RegisterClassEx(&WindowClass)) return 1;

	HWND WindowHandle = CreateWindowEx(NULL, WindowClassName, WindowMenuName, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, StartPosX, StartPosY, WindowWidth, WindowHeight, NULL, NULL, HInstance, NULL);

	if (!WindowHandle) return 2;

	Debug.SetupDebugConsole();

	while (GetMessage((&WindowMessage), NULL, 0, 0) > 0)
	{
		TranslateMessage(&WindowMessage);
		Debug.LogWindowInfo(WindowHandle);
		DispatchMessage(&WindowMessage);
	}
	
	return 0;
}

LRESULT __stdcall WindowProcedure(HWND WindowHandle, UINT WindowMessage, WPARAM WParam, LPARAM LParam)
{
	HDC Hdc;
	PS PaintStruct;
	RECT WindowRect{ };
	std::wofstream MyFile("Log1.txt");
	wchar_t* CalcSumString = &CalcLogic::CalcSumString[CalcLogic::CalcSumString.size() - 1];
	switch (WindowMessage)
	{
	case WM_CREATE:
		Button0Handle = CreateWindowEx(0, WC_BUTTON, Button0MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 0, 300, 100, 50, WindowHandle, (HMENU)Button0ID, HInstance, NULL);
		Button1Handle = CreateWindowEx(0, WC_BUTTON, Button1MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 100, 300, 100, 50, WindowHandle, (HMENU)Button1ID, HInstance, NULL);
		Button2Handle = CreateWindowEx(0, WC_BUTTON, Button2MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 200, 300, 100, 50, WindowHandle, (HMENU)Button2ID, HInstance, NULL);
		Button3Handle = CreateWindowEx(0, WC_BUTTON, Button3MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 300, 300, 100, 50, WindowHandle, (HMENU)Button3ID, HInstance, NULL);
		Button4Handle = CreateWindowEx(0, WC_BUTTON, Button4MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 400, 300, 100, 50, WindowHandle, (HMENU)Button4ID, HInstance, NULL);
		Button5Handle = CreateWindowEx(0, WC_BUTTON, Button5MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 0, 350, 100, 50, WindowHandle, (HMENU)Button5ID, HInstance, NULL);
		Button6Handle = CreateWindowEx(0, WC_BUTTON, Button6MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 100, 350, 100, 50, WindowHandle, (HMENU)Button6ID, HInstance, NULL);
		Button7Handle = CreateWindowEx(0, WC_BUTTON, Button7MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 200, 350, 100, 50, WindowHandle, (HMENU)Button7ID, HInstance, NULL);
		Button8Handle = CreateWindowEx(0, WC_BUTTON, Button8MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 300, 350, 100, 50, WindowHandle, (HMENU)Button8ID, HInstance, NULL);
		Button9Handle = CreateWindowEx(0, WC_BUTTON, Button9MenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 400, 350, 100, 50, WindowHandle, (HMENU)Button9ID, HInstance, NULL);
		PlusButtonHandle = CreateWindowEx(0, WC_BUTTON, PlusButtonMenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 0, 400, 100, 50, WindowHandle, (HMENU)PlusButtonID, HInstance, NULL);
		MinusButtonHandle = CreateWindowEx(0, WC_BUTTON, MinusButtonMenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 100, 400, 100, 50, WindowHandle, (HMENU)MinusButtonID, HInstance, NULL);
		MultiplyButtonHandle = CreateWindowEx(0, WC_BUTTON, MultiplyButtonMenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 200, 400, 100, 50, WindowHandle, (HMENU)MultiplyButtonID, HInstance, NULL);
		DivideButtonHandle = CreateWindowEx(0, WC_BUTTON, DivideButtonMenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 300, 400, 100, 50, WindowHandle, (HMENU)DivideButtonID, HInstance, NULL);
		EqualButtonHandle = CreateWindowEx(0, WC_BUTTON, EqualButtonMenuName, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_TABSTOP, 400, 400, 100, 50, WindowHandle, (HMENU)EqualButtonID, HInstance, NULL);
		break;
	case WM_COMMAND:
		Debug.UpdateWindow(WindowHandle, WindowRect);
		switch (LOWORD(WParam))
		{
		case Button0ID:
			Debug.LogToConsole("Button0ID was pressed!");
			CalcLogic::CalcSumString += TEXT("0");
			break;
		case Button1ID:
			Debug.LogToConsole("Button1ID was pressed!");
			CalcLogic::CalcSumString += TEXT("1");
			break;
		case Button2ID:
			Debug.LogToConsole("Button2ID was pressed!");
			CalcLogic::CalcSumString += TEXT("2");
			break;
		case Button3ID:
			Debug.LogToConsole("Button3ID was pressed!");
			CalcLogic::CalcSumString += TEXT("3");
			break;
		case Button4ID:
			Debug.LogToConsole("Button4ID was pressed!");
			CalcLogic::CalcSumString += TEXT("4");
			break;
		case Button5ID:
			Debug.LogToConsole("Button5ID was pressed!");
			CalcLogic::CalcSumString += TEXT("5");
			break;
		case Button6ID:
			Debug.LogToConsole("Button6ID was pressed!");
			CalcLogic::CalcSumString += TEXT("6");
			break;
		case Button7ID:
			Debug.LogToConsole("Button7ID was pressed!");
			CalcLogic::CalcSumString += TEXT("7");
			break;
		case Button8ID:
			Debug.LogToConsole("Button8ID was pressed!");
			CalcLogic::CalcSumString += TEXT("8");
			break;
		case Button9ID:
			Debug.LogToConsole("Button9ID was pressed!");
			CalcLogic::CalcSumString += TEXT("9");
			break;
		case PlusButtonID:
			Debug.LogToConsole("PlusButtonID was pressed!");
			if (!(wcscmp(CalcSumString, TEXT(" ")) == 0))
			{
				if (!(wcscmp(CalcSumString, TEXT("+")) == 0))
				{
					if (!(wcscmp(CalcSumString, TEXT("-")) == 0))
					{
						if (!(wcscmp(CalcSumString, TEXT("*")) == 0))
						{
							if (!(wcscmp(CalcSumString, TEXT("/")) == 0)) CalcLogic::CalcSumString += TEXT("+");
						}
					}
				}
			}
			break;
		case MinusButtonID:
			Debug.LogToConsole("MinusButtonID was pressed!");
			if (!(wcscmp(CalcSumString, TEXT(" ")) == 0))
			{
				if (!(wcscmp(CalcSumString, TEXT("+")) == 0))
				{
					if (!(wcscmp(CalcSumString, TEXT("-")) == 0))
					{
						if (!(wcscmp(CalcSumString, TEXT("*")) == 0))
						{
							if (!(wcscmp(CalcSumString, TEXT("/")) == 0)) CalcLogic::CalcSumString += TEXT("-");
						}
					}
				}
			}
			break;
		case MultiplyButtonID:
			Debug.LogToConsole("MultiplyButtonID was pressed!");
			if (!(wcscmp(CalcSumString, TEXT(" ")) == 0))
			{
				if (!(wcscmp(CalcSumString, TEXT("+")) == 0))
				{
					if (!(wcscmp(CalcSumString, TEXT("-")) == 0))
					{
						if (!(wcscmp(CalcSumString, TEXT("*")) == 0))
						{
							if (!(wcscmp(CalcSumString, TEXT("/")) == 0)) CalcLogic::CalcSumString += TEXT("*");
						}
					}
				}
			}
			break;
		case DivideButtonID:
			Debug.LogToConsole("DivideButtonID was pressed!");
			if (!(wcscmp(CalcSumString, TEXT(" ")) == 0))
			{
				if (!(wcscmp(CalcSumString, TEXT("+")) == 0))
				{
					if (!(wcscmp(CalcSumString, TEXT("-")) == 0))
					{
						if (!(wcscmp(CalcSumString, TEXT("*")) == 0))
						{
							if (!(wcscmp(CalcSumString, TEXT("/")) == 0)) CalcLogic::CalcSumString += TEXT("/");
						}
					}
				}
			}
			break;
		case EqualButtonID:
			Debug.LogToConsole("EqualButtonID was pressed!");
			if ((wcscmp(CalcSumString, TEXT("+")) == 0)) MessageBoxEx(WindowHandle, TEXT("You can't calculate until you place a value after your \"+\" operator!"), TEXT("Warning!"), MB_OK, NULL);
			else if ((wcscmp(CalcSumString, TEXT("-")) == 0)) MessageBoxEx(WindowHandle, TEXT("You can't calculate until you place a value after your \"-\" operator!"), TEXT("Warning!"), MB_OK, NULL);
			else if ((wcscmp(CalcSumString, TEXT("*")) == 0)) MessageBoxEx(WindowHandle, TEXT("You can't calculate until you place a value after your \"*\" operator!"), TEXT("Warning!"), MB_OK, NULL);
			else if ((wcscmp(CalcSumString, TEXT("/")) == 0)) MessageBoxEx(WindowHandle, TEXT("You can't calculate until you place a value after your \"/\" operator!"), TEXT("Warning!"), MB_OK, NULL);
			else
			{
				//Logic.FindTotal()
			}
			break;
		}
		break;
	case WM_KEYDOWN:
		Debug.UpdateWindow(WindowHandle, WindowRect);
		switch (LOWORD(WParam))
		{
		case 0x30:
			Debug.LogToConsole("0x30 key was pressed!");
			CalcLogic::CalcSumString += TEXT("0");
			break;
		case 0x31:
			Debug.LogToConsole("0x31 key was pressed!");
			CalcLogic::CalcSumString += TEXT("1");
			break;
		case 0x32:
			Debug.LogToConsole("0x32 key was pressed!");
			CalcLogic::CalcSumString += TEXT("2");
			break;
		case 0x33:
			Debug.LogToConsole("0x33 key was pressed!");
			CalcLogic::CalcSumString += TEXT("3");
			break;
		case 0x34:
			Debug.LogToConsole("0x34 key was pressed!");
			CalcLogic::CalcSumString += TEXT("4");
			break;
		case 0x35:
			Debug.LogToConsole("0x35 key was pressed!");
			CalcLogic::CalcSumString += TEXT("5");
			break;
		case 0x36:
			Debug.LogToConsole("0x36 key was pressed!");
			CalcLogic::CalcSumString += TEXT("6");
			break;
		case 0x37:
			Debug.LogToConsole("0x37 key was pressed!");
			CalcLogic::CalcSumString += TEXT("7");
			break;
		case 0x38:
			Debug.LogToConsole("0x38 key was pressed!");
			CalcLogic::CalcSumString += TEXT("8");
			break;
		case 0x39:
			Debug.LogToConsole("0x39 key was pressed!");
			CalcLogic::CalcSumString += TEXT("9");
			break;
		case VK_LEFT:
			Debug.LogToConsole("VK_LEFT key was pressed!");
			if (CalcLogic::CalcSumString.size() >= 6) CalcLogic::CalcSumString.pop_back();
			break;
		case VK_BACK:
			Debug.LogToConsole("VK_BACK key was pressed!");
			if (CalcLogic::CalcSumString.size() >= 6) CalcLogic::CalcSumString.pop_back();
			break;
		default:
			if (UseNumPadKeys)
			{
				switch (LOWORD(WParam))
				{
				case VK_NUMPAD0:
					Debug.LogToConsole("NUMPAD0 key was pressed!");
					CalcLogic::CalcSumString += TEXT("0");
					break;
				case VK_NUMPAD1:
					Debug.LogToConsole("NUMPAD1 key was pressed!");
					CalcLogic::CalcSumString += TEXT("1");
					break;
				case VK_NUMPAD2:
					Debug.LogToConsole("NUMPAD2 key was pressed!");
					CalcLogic::CalcSumString += TEXT("2");
					break;
				case VK_NUMPAD3:
					Debug.LogToConsole("NUMPAD3 key was pressed!");
					CalcLogic::CalcSumString += TEXT("3");
					break;
				case VK_NUMPAD4:
					Debug.LogToConsole("NUMPAD4 key was pressed!");
					CalcLogic::CalcSumString += TEXT("4");
					break;
				case VK_NUMPAD5:
					Debug.LogToConsole("NUMPAD5 key was pressed!");
					CalcLogic::CalcSumString += TEXT("5");
					break;
				case VK_NUMPAD6:
					Debug.LogToConsole("NUMPAD6 key was pressed!");
					CalcLogic::CalcSumString += TEXT("6");
					break;
				case VK_NUMPAD7:
					Debug.LogToConsole("NUMPAD7 key was pressed!");
					CalcLogic::CalcSumString += TEXT("7");
					break;
				case VK_NUMPAD8:
					Debug.LogToConsole("NUMPAD8 key was pressed!");
					CalcLogic::CalcSumString += TEXT("8");
					break;
				case VK_NUMPAD9:
					Debug.LogToConsole("NUMPAD9 key was pressed!");
					CalcLogic::CalcSumString += TEXT("9");
					break;
				}
			}
			break;
		}
		break;
	case WM_PAINT:
		GetClientRect(WindowHandle, &WindowRect);
		InvalidateRect(WindowHandle, &WindowRect, TRUE);
		Hdc = BeginPaint(WindowHandle, &PaintStruct);
		DrawText(Hdc, TEXT("Win32 Calculator!"), -1, &WindowRect, DT_TOP | DT_CENTER);
		WindowRect.top += 25;
		DrawText(Hdc, CalcLogic::CalcSumString.c_str(), -1, &WindowRect, DT_TOP | DT_CENTER);
		std::cout << "CalcLogic - CalcSumString: ";
		std::wcout << CalcLogic::CalcSumString << std::endl;
		WindowRect.top += 50;
		DrawText(Hdc, TEXT("RESULT: "), -1, &WindowRect, DT_TOP | DT_CENTER);
		EndPaint(WindowHandle, &PaintStruct);
		break;
	case WM_CLOSE:
		DestroyWindow(WindowHandle);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(WindowHandle, WindowMessage, WParam, LParam);
		break;
	}
}