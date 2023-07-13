#include "Menu.h"
#include "conio.h"
#include "stdio.h"

void Menu::countBullsCows(User& user)
{
	int cows = 0;
	int bulls = 0;
	char space = ' ';
	string enemyNum = enemy.getEnemyNumber();
	string userNum = user.getUserNumber();
	for (int i = 0; i < enemyNum.length(); i++)
	{
		if (enemyNum[i] == userNum[i])
		{
			bulls++;
			enemyNum[i] = space;
		}
	}
	for (int i = 0; i < userNum.length(); i++) //быков 4 - коров тоже
	{
		for (int j = i; j < userNum.length(); j++)
		{
			if (enemyNum[i] == userNum[j])
				cows++;
		}
	}
	if (bulls == 4)
		cows = 4;
	cout << userNum << " быков - " << bulls << ", коров - " << cows << endl;
	check(cows, bulls);
}

void Menu::check(int cows, int bulls)
{
	if (cows == 4 && bulls == 4) {
		cout << "Игра завершена. Количество ходов - " << moves << endl;
		cout << "Для выхода нажмите Escape" << endl;
		moves = 11;
		exit = true;
	}
	else if (moves == 10) {
		cout << "Игра завершена. Вы проиграли" << endl;
		cout << "Для выхода нажмите Escape" << endl;
	}
}

void Menu::title()
{
	cout << " - - - Б Ы К И   И   К О Р О В Ы - - -" << endl;
	cout << "Новая игра" << endl;
	cout << "Напомнить правила и играть" << endl;
	cout << "Выход" << endl;
}

void Menu::handler()
{
	title();
	const int menuItems = 3;
	int activeMenuItem = 1;
	int ch = 0;
	bool exit = false;
	while (!exit) {
		gotoxy(0, activeMenuItem);
		ch = _getch();
		if (ch == -32)
			ch = _getch();
		switch (ch)
		{
		case 72:
			--activeMenuItem;
			break;
		case 80:
			++activeMenuItem;
			break;
		case 13:
			if (activeMenuItem == 1)
			{
				game();
				activeMenuItem == 3;
				break;
				exit = true;
			}
			else if (activeMenuItem == 2)
			{
				rules();
				activeMenuItem = 1;
			}
			else if (activeMenuItem == 3)
			{
				system("cls");
				exit = true;
			}
		case 27:
			system("cls");
			exit = true;
			break;
		}
	}
}

void Menu::gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Menu::rules()
{
	system("cls");
	cout << "П Р А В И Л А ::" << endl;
	cout << "Корова - угадана цифра. Бык - угадана цифра вплоть до позиции.";
}

void Menu::newTurn()
{
	User newUser;
	cin >> newUser;
	cout << "Попытка №" << moves + 1 << endl;
	countBullsCows(newUser);
	moves++;
}

void Menu::game()
{
	system("cls");
	cout << "Имеется 10 попыток, чтобы отгадать число!" << endl;
	while (moves < 10)
	{
		newTurn();
	}
}
