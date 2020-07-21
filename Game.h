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

class Game /*: public Field*/
{
	Field field;
	
public:

	int get_count_of_mines(int x, int y)
	{
		
	
		int count = 0;
		if (field[x][y] != 'x') {
			for (int i = x - 1; i <= x + 1 && i < field.GetHorizontalyCount(); i++) {
				for (int j = y - 1; j <= y + 1; j++) {
					if (i >= 0 && j >= 0) {
						if (field[i][j] == 'x') count++;
					}
				}
			}
			field[x][y] = 48 + count;
			field.GetUnopenedCellsCount() -= 1;
		}
		return count;
	}

	bool you_Win() {
		field.Show_Mines(10);

		cout << "Y O U    W O N ! ! !" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
		cout << "Game Over" << endl;

		return false; 
	};

	bool you_Are_Loser() {
		field.Show_Mines(12);

		cout << "L O S E R ! ! !" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
		cout << "Game Over" << endl;

		return false;
	};

	void check_Zero(int x, int y) {
		bool stop = false;

		

		for (int i = x + 1; i < field.GetHorizontalyCount() ; i++) {
			if (field[i][y] == ' ' && stop == false) {
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
			if (field[i][y] == ' ' && stop == false) {
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

		for (int j = y + 1; j < field.GetVerticalyCount(); j++) {
			if (field[x][j] == ' ' && stop == false) {
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
			if (field[x][j] == ' ' && stop == false) {
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
		cout << "no open cells remain " <<   unopenedCellsCount << endl;


		if (unopenedCellsCount == field.GetMinesCount()) {  //������
			return you_Win();
		}

		if (field[x][y] == 'x') { // �������
			return you_Are_Loser();
		}

		return true;
	}

	void PlayGame(/*Field field*/)
	{

		/*field.FieldInit();*/
		field.Set_Mine();

		char x;
		int y;
		do
		{
			field.drawField();
			cout << endl;
			cout << "Enter the shot coordinates" << endl;
			cin >> x >> y;

			// ���������� ˲���� �  � ����� (��� ˲���� � - 65)
			x = x - 65;
			y = y - 1;
			system("cls");

		} while (Shot(x, y));

	}

};
