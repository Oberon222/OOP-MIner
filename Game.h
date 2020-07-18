#pragma once
#include <iostream>
#include <string>
#include "General Menu.h"
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include"Field.h"
#include"Text Helper.h"
using namespace std;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Game
{
	Field field;

	int horizontalyCount = 0;
	int verticalyCount = 0;
	int minesCount = 0;
	int unopenedCellsCount = 0;
	char** Field = new char* [horizontalyCount];

public:

	void InitHorizontalyCount(int a) {
		if (a > 26) cout << "Error" << endl;
		else
			horizontalyCount = a;
	}

	void InitVerticalyCount(int b) {
		verticalyCount = b;
	}

	void InitMinesCount(int c) {
		minesCount = c;
	}

	void Field_Init() {

		Field = new char* [horizontalyCount];

		for (int i = 0; i < horizontalyCount; i++)
		{
			Field[i] = new char[verticalyCount];
			for (int j = 0; j < verticalyCount; j++)
			{
				Field[i][j] = ' ';
			}
		}
		unopenedCellsCount = horizontalyCount * verticalyCount;
	}

	void Drow_Field() {

		cout << "  ";

		for (int i = 0; i < verticalyCount; i++) {
			cout << setw(3) << i + 1;
		}
		cout << endl;
		cout << "   ";
		for (int i = 0; i < verticalyCount; i++) {
			cout << setw(3) << "---";
		}
		cout << endl;


		for (int i = 0; i < horizontalyCount; i++) {
			cout << (char)(i + 65) << "|";

			for (int j = 0; j < verticalyCount; j++) {
				if (Field[i][j] == '0') {
					cout << setw(3) << '0';
				}

				else if (Field[i][j] != ' ' && Field[i][j] != '0' && Field[i][j] != 'x') {
					cout << setw(3) << Field[i][j];
				}

				else if (Field[i][j] == 'x') {
					SetConsoleTextAttribute(hConsole, 6);

					cout << setw(3) << '*';
					SetConsoleTextAttribute(hConsole, 7);
				}
				else {
					SetConsoleTextAttribute(hConsole, 6);

					cout << setw(3) << '*';
					SetConsoleTextAttribute(hConsole, 7);
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
			/*cout << "X" << mineX << "-Y" << mineY<<endl;*/   // œ≤ƒ ¿« ¿  ŒŒ–ƒ»Õ¿“» Ã≤Õ
			if (Field[mineX][mineY] == ' ') {

				Field[mineX][mineY] = 'x';
				i++;
			}
		}
	}

	void show_Mines(int colorCode) {
		cout << "  ";
		for (int i = 0; i < verticalyCount; i++) {
			cout << setw(3) << i + 1;
		}
		cout << endl;
		cout << "  ";

		for (int i = 0; i < verticalyCount; i++) {
			cout << setw(3) << "---";
		}
		cout << endl;
		for (int i = 0; i < horizontalyCount; i++) {
			cout << (char)(i + 65) << "|";

			for (int j = 0; j < verticalyCount; j++) {
				if (Field[i][j] == ' ') {
					SetConsoleTextAttribute(hConsole, 6);

					cout << setw(3) << '*';
					SetConsoleTextAttribute(hConsole, 7);

				}
				else {
					SetConsoleTextAttribute(hConsole, colorCode);

					cout << setw(3) << Field[i][j];
					SetConsoleTextAttribute(hConsole, 7);

				}
			}
			cout << endl;
		}
		cout << endl;
		SetConsoleTextAttribute(hConsole, colorCode);
	}

	int get_count_of_mines(int x, int y)
	{
		int count = 0;
		if (Field[x][y] != 'x') {
			for (int i = x - 1; i <= x + 1 && i < horizontalyCount; i++) {
				for (int j = y - 1; j <= y + 1; j++) {
					if (i >= 0 && j >= 0) {
						if (Field[i][j] == 'x') count++;
					}
				}
			}
			Field[x][y] = 48 + count;
			unopenedCellsCount = unopenedCellsCount - 1;
		}
		return count;
	}

	bool you_Win() {
		show_Mines(10);

		cout << "Y O U    W O N ! ! !" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
		cout << "Game Over" << endl;

		return false;
	};

	bool you_Are_Loser() {
		show_Mines(12);

		cout << "L O S E R ! ! !" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
		cout << "Game Over" << endl;

		return false;
	};

	void check_Zero(int x, int y) {
		bool stop = false;

		for (int i = x + 1; i < horizontalyCount; i++) {
			if (Field[i][y] == ' ' && stop == false) {
				if (get_count_of_mines(i, y) == 0) {

					check_Zero(i, y);
				}
				else {
					stop = true;
				}
			}
			else {
				stop = true;
			}

		}

		stop = false;

		for (int i = x - 1; i >= 0; i--) {
			if (Field[i][y] == ' ' && stop == false) {
				if (get_count_of_mines(i, y) == 0) {
					check_Zero(i, y);
				}
				else {
					stop = true;
				}
			}
			else {
				stop = true;
			}
		}
		stop = false;

		for (int j = y + 1; j < verticalyCount; j++) {
			if (Field[x][j] == ' ' && stop == false) {
				if (get_count_of_mines(x, j) == 0) {
					check_Zero(x, j);
				}
				else {
					stop = true;
				}

			}
			else {
				stop = true;
			}
		}
		stop = false;

		for (int j = y - 1; j >= 0; j--) {
			if (Field[x][j] == ' ' && stop == false) {
				if (get_count_of_mines(x, j) == 0) {
					check_Zero(x, j);
				}
				else {
					stop = true;
				}
			}
			else {
				stop = true;
			}
		}
	}

	bool Shot(int x, int y) {

		if (get_count_of_mines(x, y) == 0) {
			check_Zero(x, y);
		};
		cout << "no open cells remain " << unopenedCellsCount << endl;


		if (unopenedCellsCount == minesCount) {  //¬»√–¿ÿ
			return you_Win();
		}

		if (Field[x][y] == 'x') { // œ–Œ√–¿ÿ
			return you_Are_Loser();
		}

		return true;
	}

	void PlayGame(/*Field field*/)
	{

		Field_Init();
		Set_Mine();

		char x;
		int y;
		do
		{
			Drow_Field();
			cout << endl;
			cout << "Enter the shot coordinates" << endl;
			cin >> x >> y;

			// œ≈–≈¬Œƒ»ÃŒ À≤“≈–” ’  ” ÷»‘–” ( Œƒ À≤“≈–» ¿ - 65)
			x = x - 65;
			y = y - 1;
			system("cls");

		} while (Shot(x, y));

	}

};
