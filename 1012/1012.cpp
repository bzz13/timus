#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	std::map<int, unsigned long long> f;
	f[-2] = f[-1] = 0;
	f[0] = 1;
	f[1] = k-1;
	for (int i = 2; i <= n; ++i)
		f[i] = f[i-1]*k - f[i-3]*(k-1);

	cout << f[n];
}