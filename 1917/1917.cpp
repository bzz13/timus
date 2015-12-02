#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int minAttempts(map<int, int>& coins, int p)
{
	// for(auto c: coins)
	// 	cout << c.first << ": " << c.second << endl;
	// cout << endl;

	int count = 0;
	for(auto c: coins)
	{
		count += c.second;
		if (count*c.first > p)
		{
			map<int, int>::iterator m = coins.find(c.first);
			coins.erase(coins.begin(), m);
			return 1 + minAttempts(coins, p);
		}
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, p, tmp;
	cin >> count >> p;

	map<int, int> coins;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		if (coins[tmp] == 0)
			coins[tmp] = 1;
		else
			coins[tmp]++;
	}

	int distroyCount = 0, minAttemptsCount = 0, maxMagicPower = 0;
	for(auto c: coins)
	{
		int magicPower = c.first;
		int coinsCount = c.second;
		if (coinsCount*magicPower <= p)
		{
			distroyCount += coinsCount;
			maxMagicPower = magicPower;
		}
		else
			break;
	}

	map<int, int>::iterator m = ++coins.find(maxMagicPower);
	coins.erase(m, coins.end());
	if (distroyCount)
		minAttemptsCount = minAttempts(coins, p);

	cout << distroyCount << ' ' << minAttemptsCount;
}