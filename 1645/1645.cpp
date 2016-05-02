#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Position
{
	int Number;
	int Min;
	int Max;
};

bool positionSortFn(const Position& p1, const Position& p2)
{
	return p1.Number < p2.Number;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	cin >> count;

	Position init;
	init.Number = 0;
	init.Min = 1;
	init.Max = count;

	vector<Position> positions(count, init);
	for (int i = 0; i < count; ++i)
		cin >> positions[i].Number;

	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if (i == j)
				continue;
			if (j < i && positions[j].Number > positions[i].Number)
				positions[i].Min ++;
			if (j > i && positions[j].Number < positions[i].Number)
				positions[i].Max --;

		}
	}

	sort(positions.begin(), positions.end(), positionSortFn);
	for(auto p: positions)
		cout << p.Min << " " << p.Max << endl;

	return 0;
}
