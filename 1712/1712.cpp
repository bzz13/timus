#include <iostream>
#include <stdio.h>
using namespace std;


void printMask(bool m[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << m[i][j] ? 1 : 0;
		}
		cout << endl;
	}
}
void printMask(bool** m)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << m[i][j] ? 1 : 0;
		}
		cout << endl;
	}
}

void printMaskedChars(bool m[4][4], char c[4][4])
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (m[i][j])
				cout << c[i][j];
}
void printMaskedChars(bool** m, char c[4][4])
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (m[i][j])
				cout << c[i][j];
}

bool** rotateMask(bool m[4][4])
{
	bool** rotated = new bool*[4];
	for (int i = 0; i < 4; i++)
		rotated[i] = new bool[4];

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			rotated[j][3 - i] = m[i][j];
	return rotated;
}

int main()
{
	char tmp;
	bool mask[4][4] = { { false } };;
	char chars[4][4];

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			tmp = getchar();
			if (tmp == '.')
				mask[i][j] = false;
			if (tmp == 'X')
				mask[i][j] = true;
		}
		getchar();
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			chars[i][j] = getchar();
		}
		getchar();
	}

	// cout << endl;
	printMaskedChars(mask, chars);
	// cout << endl;

	bool** rot = rotateMask(mask);
	printMaskedChars(rot, chars);
	// cout << endl;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			mask[i][j] = rot[i][j]; 
	rot = rotateMask(mask);
	printMaskedChars(rot, chars);
	// cout << endl;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			mask[i][j] = rot[i][j]; 
	rot = rotateMask(mask);
	printMaskedChars(rot, chars);
	// cout << endl;

	for (int i = 0; i < 4; ++i)
		delete[] rot[i];
}