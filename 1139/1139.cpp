#include <iostream>
using namespace std;

int gcd ( int a, int b )
{
	int c;
	while ( a != 0 ) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int main()
{
	int n, k;
	cin >> n >> k;
	n--;
	k--;
	cout << n + k - gcd(n, k);
}