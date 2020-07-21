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

	int level = GeneralMenu::selectDifficultyLevel();
	if (level == 4)
	{
		/*GeneralMenu::myLevel();*/

		Field field();

	}

	

	system("pause");
	return 0;
}