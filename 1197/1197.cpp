#include <iostream>
using namespace std;

int Answer(const int &x, const int &y)
{
	if (
		( x == 0 &&  y == 0) ||
		( x == 0 &&  y == 7) ||
		( x == 7 &&  y == 0) ||
		( x == 7 &&  y == 7) 
	) return 2;

	if (
		( x == 0 &&  y == 1) ||
		( x == 0 &&  y == 6) ||
		( x == 1 &&  y == 0) ||
		( x == 1 &&  y == 7) ||
		( x == 6 &&  y == 0) ||
		( x == 6 &&  y == 7) ||
		( x == 7 &&  y == 1) ||
		( x == 7 &&  y == 6) 
	) return 3;


	if ( x >= 2 && x <= 5 && y >= 2 && y <= 5)
		return 8;

	if (
		( x == 1 && (y >= 2 && y <= 5)) ||
		( x == 6 && (y >= 2 && y <= 5)) ||
		( y == 1 && (x >= 2 && x <= 5)) ||
		( y == 6 && (x >= 2 && x <= 5)) 
	) return 6;


	return 4;
}

int main()
{
	char cx;
	int x, y;
	int count;

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> cx >> y;
		x = cx - 'a';
		y--;

		cout << Answer(x, y) << endl;
	}
}