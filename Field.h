#pragma once
#include <iostream>
#include <string>
#include "General Menu.h"
#include <thread>
#include <Windows.h>
#include <conio.h>
#include"Game.h"
#include"Text Helper.h"
using namespace std;

class Field
{
	int horizontalyCount;
	int verticalyCount;
	int minesCount; // перейменувати, у Game.h теж є minesCount
	int unopenedCellsCount;
	char** cellsValues;
	

	void ShowHorizontalNumbers() {
		cout << "  ";
		for (int i = 0; i < verticalyCount; i++) {
			cout << setw(3) << i + 1;
		}
		cout << endl;
		cout << "   ";
	}

	void ShowHorizontalSeparator() {
		for (int i = 0; i < verticalyCount; i++) {
			cout << setw(3) << "---";
		}
		cout << endl;
	}

public:

	Field() { }

	Field(int horizontalyCount, int verticalyCount, int minesCount, int unopenedCellsCount, char cellsValues)
	{
		if (horizontalyCount <= 26)
		{
			this->horizontalyCount = horizontalyCount;
		}
	
		this->verticalyCount = verticalyCount;
		this->minesCount = minesCount;
		this->unopenedCellsCount = unopenedCellsCount;
		char** Field = new char* [horizontalyCount];
		FieldInit();
	}

	int GetHorizontalyCount()
	{
		return horizontalyCount;
	}

	int GetVerticalyCount()
	{
		return verticalyCount;
	}

	int GetMinesCount()
	{
		return minesCount;
	}

	char** GetFieldChars() {
		return cellsValues;
	}

	void FieldInit() {

		cellsValues = new char* [horizontalyCount];
		for (int x = 0; x < horizontalyCount; x++)
		{
			cellsValues[x] = new char[verticalyCount];
			for (int y = 0; y < verticalyCount; y++)
			{
				cellsValues[x][y] = ' ';
			}
		}
		unopenedCellsCount = horizontalyCount * verticalyCount;
	}

	void ShowField() {
		ShowHorizontalNumbers();
		ShowHorizontalSeparator();
		for (int i = 0; i < horizontalyCount; i++) {
			cout << (char)(i + 65) << "|";

			for (int j = 0; j < verticalyCount; j++) {
				if (cellsValues[i][j] == '0') {
					cout << setw(3) << '0';
				}

				else if (cellsValues[i][j] != ' ' && cellsValues[i][j] != '0' && cellsValues[i][j] != 'x') {
					cout << setw(3) << cellsValues[i][j];
				}

				else {
					TextHelper::ShowTextWithColorAndTab("*", 6);
				}
			}
			cout << endl;
		}
		cout << endl;
		cout << "To win you need to find " << minesCount << " mines" << endl;
	}

	void Set_Mine() {
		srand(time(0));

		int mineX = 0;
		int mineY = 0;
		for (int i = 0; i < minesCount; )
		{
			mineX = rand() % horizontalyCount;
			mineY = rand() % verticalyCount;
			/*cout << "X" << mineX << "-Y" << mineY<<endl;*/   // ï³äêàçêà, êîîðäèíàòè ì³í
			if (cellsValues[mineX][mineY] == ' ') {

				cellsValues[mineX][mineY] = 'x';
				i++;
			}
		}
	}

	void Show_Mines( int colorCode) {
		ShowHorizontalNumbers();
		ShowHorizontalSeparator();
		for (int i = 0; i < horizontalyCount; i++) {
			cout << (char)(i + 65) << "|";

			for (int j = 0; j < verticalyCount; j++) {
				if (cellsValues[i][j] == ' ') {
					SetConsoleTextAttribute(hConsole, 6);

					cout << setw(3) << '*';
					SetConsoleTextAttribute(hConsole, 7);

				}
				else {
					SetConsoleTextAttribute(hConsole, colorCode);

					cout << setw(3) << cellsValues[i][j];
					SetConsoleTextAttribute(hConsole, 7);

				}
			}
			cout << endl;
		}
		cout << endl;
		SetConsoleTextAttribute(hConsole, colorCode);
	}

	int Get_Count_Of_Mines(int x, int y) {
		int count = 0;
		if (cellsValues[x][y] != 'x') {
			for (int i = x - 1; i <= x + 1 && i < horizontalyCount; i++) {
				for (int j = y - 1; j <= y + 1; j++) {
					if (i >= 0 && j >= 0) {
						if (cellsValues[i][j] == 'x') count++;
					}
				}
			}
			cellsValues[x][y] = 48 + count;
			unopenedCellsCount = unopenedCellsCount - 1;
		}
		return count;
	}

};
