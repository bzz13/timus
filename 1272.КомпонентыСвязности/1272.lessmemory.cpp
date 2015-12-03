#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, K, M, b, e, componentsCount = 0, min, max;
	cin >> count >> K >> M;
	map<int, int> components;
	for (int i = 1; i <= count; ++i)
		components[i] = i;
	componentsCount = count;

	for (int i = 0; i < K; ++i)
	{
		cin >> b >> e;

		min = components[b] < components[e] ? components[b] : components[e];
		max = components[b] > components[e] ? components[b] : components[e];
		if (min != max)
		{
			--componentsCount;
			for (auto & p : components)
			{
				if (p.second == max)
					p.second = min;
			}
		}
	}

	// for (int i = 1; i <= count; ++i)
	// {
	// 	cout << i << ": ";
	// 	for(auto p: components)
	// 		if (p.second == i )
	// 			cout << p.first << ' ';
	// 	cout << endl;
	// }
	// cout << endl;

	cout << componentsCount - 1;
	return 0;
}