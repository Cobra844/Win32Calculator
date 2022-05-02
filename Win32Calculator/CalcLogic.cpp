#include "stdafx.h"
#include "CalcLogic.h"
#include "CalcDebugger.h"
std::wstring CalcLogic::CalcSumString = TEXT("SUM: ");
std::wstring CalcLogic::CalcResultString = TEXT("RESULT: ");
bool CalcLogic::ValidCalculation = false;
bool CalcLogic::FindTotal(HWND WindowHandle)
{
	std::vector<CString> Instructions = { }; // This vector stores the instruction set, E.G. "SUM: 4/5*6+22".
	
	for (int A = 0; A < CalcLogic::CalcSumString.size(); A++) // Adds the values to the "Instructions" vector while removing "SUM: ".
	{
		if (A > 4) Instructions.push_back(CalcLogic::CalcSumString[A]);
	}

	if (DebugToggle == 1) // Writes a log of Instructions vector if Debug Mode is enabled, see "CalcConfig.h".
	{
		std::wofstream MyFile("DebugFileWrite.txt");
		for (int A = 0; A < Instructions.size(); A++) MyFile << (CStringA)Instructions[A] << std::endl; // Casting to CStringA is necessary to write to files?
		MyFile.close();
	}

	int Number1 = 0;
	int Number2 = 0;
	bool AddToggle = false;
	bool SubtractToggle = false;
	bool MultiplyToggle = false;
	bool DivideToggle = false;
	bool DoneCalc = true;

	for (int A = 0; A < Instructions.size(); A++)
	{
		if (DoneCalc)
		{
			if (wcscmp(Instructions[A], TEXT("+")) == 0)
			{
				DoneCalc = false;
				AddToggle = true;
			}
			else if (wcscmp(Instructions[A], TEXT("-")) == 0)
			{
				DoneCalc = false;
				SubtractToggle = true;
			}
			else if (wcscmp(Instructions[A], TEXT("*")) == 0)
			{
				DoneCalc = false;
				MultiplyToggle = true;
			}
			else if (wcscmp(Instructions[A], TEXT("/")) == 0)
			{
				DoneCalc = false;
				DivideToggle = true;
			}
			if (wcscmp(Instructions[A], TEXT("0")) == 0) Number1 = ((Number1 * 10) + 0);
			if (wcscmp(Instructions[A], TEXT("1")) == 0) Number1 = ((Number1 * 10) + 1);
			if (wcscmp(Instructions[A], TEXT("2")) == 0) Number1 = ((Number1 * 10) + 2);
			if (wcscmp(Instructions[A], TEXT("3")) == 0) Number1 = ((Number1 * 10) + 3);
			if (wcscmp(Instructions[A], TEXT("4")) == 0) Number1 = ((Number1 * 10) + 4);
			if (wcscmp(Instructions[A], TEXT("5")) == 0) Number1 = ((Number1 * 10) + 5);
			if (wcscmp(Instructions[A], TEXT("6")) == 0) Number1 = ((Number1 * 10) + 6);
			if (wcscmp(Instructions[A], TEXT("7")) == 0) Number1 = ((Number1 * 10) + 7);
			if (wcscmp(Instructions[A], TEXT("8")) == 0) Number1 = ((Number1 * 10) + 8);
			if (wcscmp(Instructions[A], TEXT("9")) == 0) Number1 = ((Number1 * 10) + 9);
		}
		else if (!DoneCalc)
		{
			if (wcscmp(Instructions[A], TEXT("+")) == 0)
			{
				if (AddToggle)
				{
					Number1 += Number2;
					Number2 = 0;
					DoneCalc = true;
					AddToggle = false;
				}
				else if (SubtractToggle)
				{
					Number1 -= Number2;
					Number2 = 0;
					DoneCalc = true;
					SubtractToggle = false;
				}
				else if (MultiplyToggle)
				{
					Number1 *= Number2;
					Number2 = 0;
					DoneCalc = true;
					MultiplyToggle = false;
				}
				else if (DivideToggle)
				{
					Number1 /= Number2;
					Number2 = 0;
					DoneCalc = true;
					DivideToggle = false;
				}
				DoneCalc = false;
				AddToggle = true;
			}
			else if (wcscmp(Instructions[A], TEXT("-")) == 0)
			{
				if (AddToggle)
				{
					Number1 += Number2;
					Number2 = 0;
					DoneCalc = true;
					AddToggle = false;
				}
				else if (SubtractToggle)
				{
					Number1 -= Number2;
					Number2 = 0;
					DoneCalc = true;
					SubtractToggle = false;
				}
				else if (MultiplyToggle)
				{
					Number1 *= Number2;
					Number2 = 0;
					DoneCalc = true;
					MultiplyToggle = false;
				}
				else if (DivideToggle)
				{
					Number1 /= Number2;
					Number2 = 0;
					DoneCalc = true;
					DivideToggle = false;
				}
				DoneCalc = false;
				SubtractToggle = true;
			}
			else if (wcscmp(Instructions[A], TEXT("*")) == 0)
			{
				if (AddToggle)
				{
					Number1 += Number2;
					Number2 = 0;
					DoneCalc = true;
					AddToggle = false;
				}
				else if (SubtractToggle)
				{
					Number1 -= Number2;
					Number2 = 0;
					DoneCalc = true;
					SubtractToggle = false;
				}
				else if (MultiplyToggle)
				{
					Number1 *= Number2;
					Number2 = 0;
					DoneCalc = true;
					MultiplyToggle = false;
				}
				else if (DivideToggle)
				{
					Number1 /= Number2;
					Number2 = 0;
					DoneCalc = true;
					DivideToggle = false;
				}
				Number1 -= Number2;
				DoneCalc = false;
				MultiplyToggle = true;
			}
			else if (wcscmp(Instructions[A], TEXT("/")) == 0)
			{
				if (AddToggle)
				{
					Number1 += Number2;
					Number2 = 0;
					DoneCalc = true;
					AddToggle = false;
				}
				else if (SubtractToggle)
				{
					Number1 -= Number2;
					Number2 = 0;
					DoneCalc = true;
					SubtractToggle = false;
				}
				else if (MultiplyToggle)
				{
					Number1 *= Number2;
					Number2 = 0;
					DoneCalc = true;
					MultiplyToggle = false;
				}
				else if (DivideToggle)
				{
					Number1 /= Number2;
					Number2 = 0;
					DoneCalc = true;
					DivideToggle = false;
				}
				DoneCalc = false;
				DivideToggle = true;
			}
			if (wcscmp(Instructions[A], TEXT("0")) == 0) Number2 = ((Number2 * 10) + 0);
			if (wcscmp(Instructions[A], TEXT("1")) == 0) Number2 = ((Number2 * 10) + 1);
			if (wcscmp(Instructions[A], TEXT("2")) == 0) Number2 = ((Number2 * 10) + 2);
			if (wcscmp(Instructions[A], TEXT("3")) == 0) Number2 = ((Number2 * 10) + 3);
			if (wcscmp(Instructions[A], TEXT("4")) == 0) Number2 = ((Number2 * 10) + 4);
			if (wcscmp(Instructions[A], TEXT("5")) == 0) Number2 = ((Number2 * 10) + 5);
			if (wcscmp(Instructions[A], TEXT("6")) == 0) Number2 = ((Number2 * 10) + 6);
			if (wcscmp(Instructions[A], TEXT("7")) == 0) Number2 = ((Number2 * 10) + 7);
			if (wcscmp(Instructions[A], TEXT("8")) == 0) Number2 = ((Number2 * 10) + 8);
			if (wcscmp(Instructions[A], TEXT("9")) == 0) Number2 = ((Number2 * 10) + 9);
		}
	}
	if (AddToggle) Number1 += Number2;
	if (SubtractToggle) Number1 -= Number2;
	if (MultiplyToggle) Number1 *= Number2;
	if (DivideToggle) Number1 /= Number2;
	std::cout << Number1;
	UINT NumLength;
	bool Negative;
	if (Number1 < 0) {
		NumLength = (Number1 / -1);
		Negative = true;
	}
	else
	{
		NumLength = (Number1);
		Negative = false;
	}
	CalcLogic::CalcSumString = TEXT("SUM: ");
	CalcLogic::CalcResultString = TEXT("RESULT: ");
	for (int A = 0; A < Instructions.size(); A++) CalcLogic::CalcResultString += Instructions[A];
	CalcLogic::CalcResultString += TEXT(" = ");
	if (Negative) CalcLogic::CalcResultString += TEXT("-");
	std::stringstream NumStringConvert;
	NumStringConvert << Number1;
	std::string NumString = NumStringConvert.str();
	CString NumCString = NumString.c_str();
	CalcLogic::CalcResultString += NumCString;
	std::wcout << CalcLogic::CalcSumString;
	PlaySound(TEXT("SystemStart.wav"), NULL, SND_FILENAME | SND_ASYNC);
	return true;
}