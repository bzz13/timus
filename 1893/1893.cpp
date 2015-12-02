#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const string Window = "window";
const string Aisle = "aisle";
const string Neither = "neither";

string definePosition(int row, char col)
{
	if (row >= 1 && row <= 2)
	{
		switch (col)
		{
			case 'A':
			case 'D':
				return Window;
			default:
				return Aisle;
		}
	}
	else if (row >= 3 && row <= 20)
	{
		switch (col)
		{
			case 'A':
			case 'F':
				return Window;
			default:
				return Aisle;
		}
	}
	else if (row >= 21 && row <= 65)
	{
		switch (col)
		{
			case 'A':
			case 'K':
				return Window;
			case 'C':
			case 'D':
			case 'G':
			case 'H':
				return Aisle;
			default:
				return Neither;
		}
	}
}

int main()
{
	string place;
	cin >> place;
	int row = atoi(place.substr(0, place.size() - 1).c_str());
	char col = place.substr (place.size() - 1, 1)[0];
	cout << definePosition(row, col);
}