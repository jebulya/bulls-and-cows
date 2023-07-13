#include "Enemy.h"
#include <random>
#include <sstream>
#include "stdlib.h"
#include "time.h"

Enemy::Enemy()
{
	int num;
	do {
		std::random_device dev;
		std::mt19937 gen(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1000, 9999);
		num = dist(gen);
	} while (!checker(num) && num <999 && num >10000);
	this->enemyNumber = to_string(num);
	this->bulls = 0;
	this->cows = 0;
}

string Enemy::getEnemyNumber()
{
	return this->enemyNumber;
}

bool Enemy::checker(int num)
{
	string s = to_string(num);
	for (int i = 1; i < 4; i++)
	{
		if (s[0] == s[i])
			return false;
	}
	return true;
}

void Enemy::plusBullAndCow(User& user)
{
	string copyEnemyNumber = this->enemyNumber;
	char space = ' ';
	for (int i = 0; i < 4; i++)
	{
		if (copyEnemyNumber[i] == user.getUserNumber()[i])
		{
			bulls++;
			this->enemyNumber[i] = space;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = i+1; j < 4; j++)
		{
			if (copyEnemyNumber[i] == user.getUserNumber()[j])
				cows++;
		}
	}
}

void Enemy::reset()
{
	this->cows = 0;
	this->bulls = 0;
}

void Enemy::printResult()
{

}

