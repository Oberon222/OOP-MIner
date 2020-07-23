#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <conio.h>
using namespace std;


class GeneralMenu
{
	
public:

	static int* myLevel()
	{
		int myHorizonralCells;
		int myVerticalCells;
		int myCountMine;
		cout << "Enter count of horizontal cells: ";
		cin >> myHorizonralCells;
		cout << "Enter count of vertical cells: ";
		cin >> myVerticalCells;
		if (myVerticalCells > 26)
		{
			cout << "Too many cells, it'll be set 26" << endl;
			myVerticalCells = 26;
		}

		cout << "Enter count mine: ";
		cin >> myCountMine;
		if (myCountMine >= myHorizonralCells * myVerticalCells)
		{
			myCountMine = myHorizonralCells * myVerticalCells - 1;
			cout << "Too many mines, it'll be set to" << myCountMine << endl;
		}
		
		int arr[3]= { myHorizonralCells, myVerticalCells, myCountMine };

		return arr ;
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
