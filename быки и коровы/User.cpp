#include "User.h"

User::User()
{
}

bool User::correctInput(string& input)
{
	const string evilSyms = "0123456789";
	for (char c : input)
	{
		if (evilSyms.find(c) == evilSyms.npos || input.length() != 4)
		{
			cout << "Неверно!" << endl;
			return false;
		}
	}
	return true;
}

void User::setUserNumber(string& str)
{
	if (str.length() == 4)
	this->userNumber = str;
}

string User::getUserNumber()
{
	return this->userNumber;
}

std::istream& operator>>(std::istream& is, User& user)
{
	do {
		cout << "Введите число:" << endl;
		is >> user.userNumber;
	} while (!user.correctInput(user.userNumber));
	return is;
}
