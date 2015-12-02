#include <iostream>
#include <utility>
#include <stack>
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

bool containsInDiagonals(pair<int, int> p, vector<pair<int, int> >* diagonals)
{
	for (std::vector<pair<int, int> >::iterator it = diagonals->begin(); it != diagonals->end(); ++it)
		if (it->first == p.first && it->second == p.second)
			return true;
	return false;
}

bool containsTopDiagonals(pair<int, int> p, vector<pair<int, int> >* diagonals)
{
	for (std::vector<pair<int, int> >::iterator it = diagonals->begin(); it != diagonals->end(); ++it)
		if (it->first > p.first && it->second == p.second)
			return true;
	return false;
}
bool containsRightDiagonals(pair<int, int> p, vector<pair<int, int> >* diagonals)
{
	for (std::vector<pair<int, int> >::iterator it = diagonals->begin(); it != diagonals->end(); ++it)
		if (it->first == p.first && it->second > p.second)
			return true;
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

	double **weight = new double*[sizeY + 1];
	for (int i = 0; i <= sizeY; ++i)
		weight[i] = new double[sizeX + 1];

	for (int i = 0; i <= sizeY; ++i)
		for (int j = 0; j <= sizeX; ++j)
			weight[i][j] = 0;

	vector<pair<int, int> > diagonals;
	readDiagonals(K, &diagonals);

	pair<int, int> first(0, 0);
	stack<pair<int, int> > stck;
	stck.push(first);
	while (stck.size() > 0)
	{ 
		pair<int, int> tmp = stck.top();
		stck.pop();

		// if (tmp.first == sizeY && tmp.second == sizeX)
		// 	break;

		double w = weight[tmp.first][tmp.second];
		bool add = false;

		if (tmp.first < sizeY && containsTopDiagonals(tmp, &diagonals))
		{
			if (weight[tmp.first + 1][tmp.second] == 0 ||
				weight[tmp.first + 1][tmp.second] > w + step)
			{
				weight[tmp.first + 1][tmp.second] = w + step;
				stck.push(pair<int, int>(tmp.first + 1, tmp.second));
				add = true;
			}
		}
		if (tmp.second < sizeX && containsRightDiagonals(tmp, &diagonals))
		{			
			if (weight[tmp.first][tmp.second + 1] == 0 ||
				weight[tmp.first][tmp.second + 1] > w + step)
			{
				weight[tmp.first][tmp.second + 1] = w + step;
				stck.push(pair<int, int>(tmp.first, tmp.second + 1));
				add = true;
			}
		}
		if (containsInDiagonals(tmp, &diagonals))
		{
			if (weight[tmp.first + 1][tmp.second + 1] == 0 ||
				weight[tmp.first + 1][tmp.second + 1] > w + stepd)
			{
				weight[tmp.first + 1][tmp.second + 1] = w + stepd;
				stck.push(pair<int, int>(tmp.first + 1, tmp.second + 1));
				add = true;
			}
		}
		if (!add)
		{
			if (tmp.first < sizeY)
			{
				if (weight[tmp.first + 1][tmp.second] == 0 ||
					weight[tmp.first + 1][tmp.second] > w + step)
				{
					weight[tmp.first + 1][tmp.second] = w + step;
					stck.push(pair<int, int>(tmp.first + 1, tmp.second));
				}
			}
			if (tmp.second < sizeX)
			{
				if (weight[tmp.first][tmp.second + 1] == 0 ||
					weight[tmp.first][tmp.second + 1] > w + step)
				{
					weight[tmp.first][tmp.second + 1] = w + step;
					stck.push(pair<int, int>(tmp.first, tmp.second + 1));
				}
			}
		}
	}

	cout << (int)(weight[sizeY][sizeX] + 0.5);

	for (int i = 0; i <= sizeY; ++i)
		delete[] weight[i];
	delete[] weight;
}