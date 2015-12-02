#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, tmp, begin, end, val;
	cin >> count;
	unordered_map<int, set<int> > ri;
	for (int i = 1; i <= count; ++i)
	{
		cin >> tmp;
		ri[tmp].insert(i);
	}
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> begin >> end >> val;
		set<int>::iterator 
			lower = ri[val].lower_bound(begin),
			upper = ri[val].upper_bound(end);
		cout << ( lower != upper ? 1 : 0);
	}
	return 0;
}