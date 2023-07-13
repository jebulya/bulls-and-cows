#include "User.h"
#include "Enemy.h"
#include "windows.h"
#include "conio.h"
#include "stdio.h"


#pragma once
class Menu
{
	int bestResult;
	int moves = 0;
	const int menuItems = 3;
	int activeMenuItem = 1;
	int ch = 0;
	bool exit = false;
	Enemy enemy;
	void countBullsCows(User&);
	void check(int, int);
	void title();
	void gotoxy(int, int);
	void rules();
	void newTurn();
	void game();
public:
	void handler();
};

