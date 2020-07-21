#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include"Field.h"
#include"Game.h"
#include"Text Helper.h"
using namespace std;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class GeneralMenu
{
	
public:

	static int myLevel()
	{
		int myHorizonralCells;
		int myVerticalCells;
		int myCountMine;
		cout << "Enter count of horizontal cells: ";
		cin >> myHorizonralCells;
		cout << "Enter count of vertical cells: ";
		cin >> myVerticalCells;
		cout << "Enter count mine: ";
		cin >> myCountMine;

		return myHorizonralCells, myVerticalCells, myCountMine;
	}

	static int selectDifficultyLevel()
	{
		int difficultyLevel;
		cout<<"Choose the difficulty level of the game: "
			"1 - easy, 2 - medium, 3 - hard, 4 - my level " << endl;

		cin >> difficultyLevel;
		return difficultyLevel;
	}

	void ShowMainMenu()
	{
		cout << "1) Start the game" << endl;
		cout << "2) Exit" << endl;
	}

};
