#include <iostream>
using namespace std;

int max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	int n, k;
	cin >> n >> k;
	if (n == 2)
	{
		cout << 0;
		return 0;
	}
	cout << max(k - 1, n - k) - 2;
}