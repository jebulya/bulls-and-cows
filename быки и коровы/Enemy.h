#pragma once
#include <iostream>
#include "User.h"

using namespace std;
class Enemy
{
	string enemyNumber;
	int bulls;
	int cows;
public:
	Enemy();
	string getEnemyNumber();
	bool checker(int);
	void plusBullAndCow(User&);
	void reset();
	void printResult();
};

