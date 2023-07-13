#include <iostream>
#include "Menu.h"
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu menu;
	menu.handler();
}
