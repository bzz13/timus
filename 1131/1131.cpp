#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	long int n, k, p = 0;
	cin >> n >> k;
	n--; // на одном уже стоит

	while(pow(2, p) <= k && n > 0)
	{
		n -= pow(2, p);
		++p;
	}

	if (n <= 0)
	{
		cout << p;
		return 0;
	}

	long int m = n % k == 0 ? (n / k) : (n / k + 1);
	cout << p + m;
}