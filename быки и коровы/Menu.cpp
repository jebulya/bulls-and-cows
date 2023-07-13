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
	for (int i = 0; i < userNum.length(); i++) //����� 4 - ����� ����
	{
		for (int j = i; j < userNum.length(); j++)
		{
			if (enemyNum[i] == userNum[j])
				cows++;
		}
	}
	if (bulls == 4)
		cows = 4;
	cout << userNum << " ����� - " << bulls << ", ����� - " << cows << endl;
	check(cows, bulls);
}

void Menu::check(int cows, int bulls)
{
	if (cows == 4 && bulls == 4) {
		cout << "���� ���������. ���������� ����� - " << moves << endl;
		cout << "��� ������ ������� Escape" << endl;
		moves = 11;
		exit = true;
	}
	else if (moves == 10) {
		cout << "���� ���������. �� ���������" << endl;
		cout << "��� ������ ������� Escape" << endl;
	}
}

void Menu::title()
{
	cout << " - - - � � � �   �   � � � � � � - - -" << endl;
	cout << "����� ����" << endl;
	cout << "��������� ������� � ������" << endl;
	cout << "�����" << endl;
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
	cout << "� � � � � � � ::" << endl;
	cout << "������ - ������� �����. ��� - ������� ����� ������ �� �������.";
}

void Menu::newTurn()
{
	User newUser;
	cin >> newUser;
	cout << "������� �" << moves + 1 << endl;
	countBullsCows(newUser);
	moves++;
}

void Menu::game()
{
	system("cls");
	cout << "������� 10 �������, ����� �������� �����!" << endl;
	while (moves < 10)
	{
		newTurn();
	}
}
