#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int main()
{
	const int maxCount = 100;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int n, k;
	cin >> n >> k;
	deque<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int m[maxCount][maxCount];
	for (int i = 0; i < maxCount; ++i)
		for (int j = 0; j < maxCount; ++j)
			m[i][j] = -1;

	int row = n%k == 0 ? n/k : n/k+1;
	int col = 0;

	while(col < k && v.size() > 0)
	{
		for (int i = 0; i < row && v.size(); ++i)
		{
			m[i][col] = v.front();
			v.pop_front();
		}
		col++;
	}

	for (int i = 0; i < row; ++i)
	{
		if (i)
			cout << endl;
		for (int j = 0; j < maxCount; ++j)
			if (m[i][j] != -1)
				printf("%4i", m[i][j]);
	}	
}