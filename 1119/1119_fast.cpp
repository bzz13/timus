#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

void readDiagonals(const int &count, vector<pair<int, int> >* diagonals)
{
	int x, y;
	for (int i = 0; i < count; ++i)
	{
		cin >> x >> y;
		pair<int, int> p(y - 1, x - 1);
		(*diagonals).push_back(p);
	}
}

bool sortFunction(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first)
		return true;
	if (a.first == b.first)
		return a.second < b.second;
	return false;
}

int main()
{
	int sizeX, sizeY, K;
	cin >> sizeX >> sizeY >> K;
	if (K == 0)
	{
		cout << (sizeY + sizeX) * 100;
		return 0;
	}

	double step = 100, stepd = 141.42135623730950488016887242097;

	vector<pair<int, int> > diagonals;
	readDiagonals(K, &diagonals);
	sort(diagonals.begin(), diagonals.end(), sortFunction);

	int *diags = new int[K];
	int dMax = 0, i = -1, j = -1;
	for (std::vector<pair<int, int> >::iterator it1 = diagonals.begin(); it1 != diagonals.end(); ++it1)
	{
		i++;
		diags[i] = 1;
		j = -1;
		for (std::vector<pair<int, int> >::iterator it2 = diagonals.begin(); it2 < it1; ++it2)
		{
			j++;
			if (it2->first < it1->first && it2->second < it1->second)
				diags[i] = max( diags[i], diags[j] + 1);
		}
		if (dMax < diags[i])
			dMax = diags[i];
	}

	cout << (int)((sizeY + sizeX) * step - dMax * (2 * step - stepd) + 0.5);
	delete[] diags;
}