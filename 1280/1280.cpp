#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int N, M, b, e;
	cin >> N >> M;

	vector<pair<int,int> > limitations(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> b >> e;
		limitations[i] = pair<int, int>(b, e);
	}

	vector<int > plan(N);
	for (int i = 0; i < N; ++i)
		cin >> plan[i];

	map<int, bool> learnd;
	for(auto subject: plan)
	{
		for(auto l: limitations)
		{
			if (l.second == subject && learnd[l.first] == false)
			{
				cout << "NO";
				return 0;
			}
		}
		learnd[subject] = true;
	}
	cout << "YES";
	return 0;
}