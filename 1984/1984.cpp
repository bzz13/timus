#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int maxSize = 100;

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;

	cout << std::setprecision(6) << std::fixed;
	if (n == 1)
		cout << 1.0L;
	else
		cout << ( 1.0L / sin(M_PI / (double)n) + 1.0L);
}
