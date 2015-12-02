#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int maxSize = 100;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int n, k, tmp, answer = 0;
	cin >> n >> k;

	int c[maxSize][maxSize] = {0};
	
	std::map<int, bool> mst;
	for (int i = 0; i < n; ++i)
		mst[i] = false;

	for (int i = 0; i < k; ++i)
	{
		cin >> tmp;
		mst[tmp-1] = true;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> c[i][j];

	int itx = n - k;
	while(itx --> 0)
	{
		int min = 9999999, minV = -1;
		for (std::map<int,bool>::iterator i = mst.begin(); i != mst.end(); ++i)
		{
			if (!i->second)
				continue;
			for (int j = 0; j < n; ++j)
			{
				if (mst[j])
				{
					cout << j << " in mst" << endl;
					continue;
				}
				cout << "(" << i->first << "," <<  j << ") = " << c[i->first][j] << endl;
				if (min > c[i->first][j] )
				{
					min = c[i->first][j];
					minV = j;
				}
			}
		}
		answer += min;
		mst[minV] = true;
		cout << "min = " << min << "; minV = " << minV << endl << endl; 
	}

	cout << answer;

	return 0;
}
