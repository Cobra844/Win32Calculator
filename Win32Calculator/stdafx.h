#pragma once

#include <Windows.h>
#include <iostream>
#include <CommCtrl.h>
#include <fstream>

#include "CalcConfig.h"

LRESULT __stdcall WindowProcedure(HWND, UINT, WPARAM, LPARAM); // Forward Declaration of standard WinProc

const short StartPosX = WindowStartingXPosition;
const short StartPosY = WindowStartingYPosition;
const short WindowWidth = WindowStartingXLength;
const short WindowHeight = WindowStartingYLength;

#define HInstance GetModuleHandle(NULL)

#define WindowClassName TEXT("WindowClass")

#define Button0ID 0
#define Button1ID 1
#define Button2ID 2
#define Button3ID 3
#define Button4ID 4
#define Button5ID 5
#define Button6ID 6
#define Button7ID 7
#define Button8ID 8
#define Button9ID 9

#define PlusButtonID 10
#define MinusButtonID 11
#define MultiplyButtonID 12
#define DivideButtonID 13
#define EqualButtonID 14

typedef PAINTSTRUCT PS;