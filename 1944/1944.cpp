#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

bool wasShootIn(const vector<pair<int, int> >& shoots, const int& x, const int& y)
{
	for (auto s: shoots)
	{
		if (s.first == x && s.second == y)
			return true;
	}
	return false;
}

void printPoint(const vector<pair<int, int> >& shoots, const int& x, const int& y, const char& c)
{
	cout << (wasShootIn(shoots, x, y) ? '*' : c);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, x, y, minX = 0, maxX = 0, minY = 0, maxY = 0;
	cin >> count;
	vector<pair<int,int> > shoots(count);
	for (int i = 0; i < count; ++i)
	{
		cin >> x >> y;
		shoots[i] = pair<int,int>(x,y);
		if (x > maxX)
			maxX = x;
		if (x < minX)
			minX = x;
		if (y > maxY)
			maxY = y;
		if (y < minY)
			minY = y;
	}

	// cout << minX << ", " << maxY << " -> " << maxX << ", " << minY;
	for (int y = maxY; y >= minY; --y)
	{
		if (y != maxY)
			cout << endl;
		for (int x = minX; x <= maxX; ++x)
		{
			if (x == 0 && y == 0)
				printPoint(shoots, x, y, '+');
			else
				if (x == 0)
					printPoint(shoots, x, y, '|');
				else
					if (y == 0)
						printPoint(shoots, x, y, '-');
					else
						printPoint(shoots, x, y, '.');
		}
	}
	return 0;
}