#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int n = 3, count = 1;
	int primes[15000];
	primes[0] = 1;
	primes[1] = 2;
	while(true)
	{
		if (isPrime(n))
		{
			count++;
			primes[count] = n;
		}
		n+=2;
		if (count == 15000)
			break;
	}

	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		cout << primes[tmp] << endl;
	}

	return 0;
}