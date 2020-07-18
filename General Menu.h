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

class GeneralManu
{
	int actino;
public:
	int GetDifficultyLevel()
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
