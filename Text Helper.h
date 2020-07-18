#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <conio.h>
using namespace std;

class TextHelper
{
public:
	static void ShowTextWithColor(string text, int textColor) {
		SetConsoleTextAttribute(hConsole, textColor);
		cout << text << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}

	static void ShowTextWithColorAndTab(string text, int textColor) {
		SetConsoleTextAttribute(hConsole, textColor);
		cout << setw(3) << text;
		SetConsoleTextAttribute(hConsole, 7);
	}
};
