#include <iostream>
#pragma once

using namespace std;
class User
{
	string userNumber;
public:
	User();
	bool correctInput(string&);
	void setUserNumber(string&);
	string getUserNumber();

	friend std::istream& operator>>(std::istream&, User&);
};

