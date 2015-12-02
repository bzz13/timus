#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	cin >> count;

	vector<int> a(count), cont(count);

	for(int i = 0; i < count; ++i)
		cin >> a[i];

	for(int i = 0; i < count; ++i)
		++cont[((i - a[i] + 1) % count + count) % count];

	int best = 0, pos = 0;

	for(int i = 0; i < count; ++i)
	{
		if(cont[i] > best)
		{
			best = cont[i];
			pos = i;
		}
	}

	cout << pos + 1;

	return 0;
}