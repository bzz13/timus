#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int count = 60001;
	const int maxv = 999999;

#ifndef ONLINE_JUDGE
	// freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;

	int DP[count] = { 0, 1 };
	for (int i = 2; i < count; ++i)
		DP[i] = maxv;

	for (int k = 2; k < count; ++k)
		for (int i = sqrt(k); i > 0; --i)
			DP[k] = min(DP[k], 1 + DP[k - i*i]);

	cout << DP[n];
	return 0;
}