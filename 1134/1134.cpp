#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int No() { cout << "NO"; return 0; }
int Yes() { cout << "YES"; return 0; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int total, count, tmp;
	cin >> total >> count;

	vector<int> available(total + 1, 2);
	available[0] = available[total] = 1;

	vector<int> sequence(count);
	for (int i = 0; i < count; ++i)
		cin >> sequence[i];
	sort(sequence.begin(), sequence.end());

	for(auto s: sequence)
	{
		if (available[s] == 0)
			return No();
		available[s] --;
		if (s > 0 && available[s-1] > 0)
			available[s-1] --;
		else
			if (s < total && available[s+1] > 0)
				available[s+1] --;
			else
				return No();
	}
	return Yes();
}