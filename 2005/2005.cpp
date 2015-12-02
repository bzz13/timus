#include <iostream>
#include <algorithm>
using namespace std;

void printPath(int path[], const int & count)
{
	for (int i = 0; i < count - 1; ++i)
		cout << path[i] << " ";
	cout << path[count - 1];
}

int minVal(int a, int b, int c, int d)
{
	return min(min(a,b), min(c,d));
}

int main()
{
	const int count = 5;
	int path[count][count];
	for (int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			cin >> path[i][j];

	int path1[count] = {1, 2, 3, 4, 5};
	int path2[count] = {1, 3, 2, 4, 5};
	int path3[count] = {1, 3, 4, 2, 5};
	int path4[count] = {1, 4, 3, 2, 5};

	int cost1 = 0, cost2 = 0, cost3 = 0, cost4 = 0;

	for (int i = 0; i < count - 1; ++i)
	{
		cost1 += path[path1[i] - 1][path1[i+1] - 1];
		cost2 += path[path2[i] - 1][path2[i+1] - 1];
		cost3 += path[path3[i] - 1][path3[i+1] - 1];
		cost4 += path[path4[i] - 1][path4[i+1] - 1];
		// cout << cost1 << " - " << cost2 << endl;
	}

	int minValue = minVal(cost1, cost2, cost3, cost4);
	if (minValue == cost1)
	{
		cout << cost1 << endl;
		printPath(path1, count);
		return 0;
	}
	if (minValue == cost2)
	{
		cout << cost2 << endl;
		printPath(path2, count);
		return 0;
	}
	if (minValue == cost3)
	{
		cout << cost3 << endl;
		printPath(path3, count);
		return 0;
	}
	if (minValue == cost4)
	{
		cout << cost4 << endl;
		printPath(path4, count);
		return 0;
	}
}