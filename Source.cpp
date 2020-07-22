#include <iostream>
#include <string>
#include "General Menu.h"
#include <thread>
#include <Windows.h>
#include <conio.h>
#include"Field.h"
#include"Game.h"
#include"Text Helper.h"
using namespace std;


int main()
{
	Field field;

	int level = GeneralMenu::selectDifficultyLevel();

	if (level == 4)
	{

		int* parameters = GeneralMenu::myLevel();
		field = Field(parameters);

	}
	else
	{

		field =  Field(level);

	}

	Game game = Game(field);

	game.StartGame();


	

	system("pause");
	return 0;
}