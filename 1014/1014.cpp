#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
	unsigned long long N;
	cin >> N;
	stack<int> d;
	bool notExists = true;
	if (N == 0)
	{
		cout << 10;
		return 0;
	}
	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 9; i > 1 && N > 1; i--)
	{
		while(N % i == 0 && N > 1)
		{
			notExists = false;
			d.push(i);
			N = N / i;
		}
	}
	if (N != 1)
		notExists = true;
	if (notExists)
		cout << -1;
	else
	{
		while(d.size() > 0)
		{
			cout << d.top();
			d.pop();
		}
	}
	return 0;
}