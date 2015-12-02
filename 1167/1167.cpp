#include <iostream>
#include <stdio.h>
#include <valarray>
#include <utility>
#include <sstream>
#include <string>
#include <map>
using namespace std;

const long long maxCost = 999999999;

long long min(const long long & a, const long long & b)
{
	return a < b ? a : b;
}

void print(valarray<bool> items)
{
	cout << "[ ";
	for(auto i: items)
		cout << i << ' ';
	cout << "] ";
}

string getKey(const valarray<bool>& items, const int& k)
{
	stringstream ss;
	for(auto i: items)
		ss << i;
	ss << ' ' << k;
	return ss.str();
}

long long P(const valarray<bool>& stable, const int& k, map<string, int>& cache, const bool& b = false)
{
	string key = getKey(stable, k);

	if (cache[key])
	{
		if (b)
		{
			cout << "from cache: " << cache[key];
		}
		return cache[key];
	}

	long long result = maxCost;
	if (k == 1)
	{
		int bc = 0, wc = 0;
		for(auto h: stable)
			if (h)
				bc ++;
			else
				wc ++;
		result = wc * bc;
		if (b)
		{
			cout << endl << "stbl : ";
			print(stable);
			cout << k << " r = " << result << endl;
		}
	}
	else
	{
		for (int s = 1; s <= k + 1; ++s)
		{
			int inPref = stable.size() - s;
			if (inPref < k-1)
				break;
			valarray<bool> pref = stable[slice(0, inPref, 1)];
			valarray<bool> suff = stable[slice(inPref, s, 1)];
			// long long p = P(pref, k-1, b) + P(suff, 1, b);
			long long p = P(pref, k-1, cache, b) + P(suff, 1, cache, b);
			result = min(result, p);
			if (b)
			{
				cout << "pref : ";
				print(pref);
				cout << "suff : ";
				print(suff);
				cout << " r = " << p << endl;
			}
		}
	}
	cache[key] = result;
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, k, tmp;

	scanf("%d%d", &count, &k);
	valarray<bool> v(count);
	for (int i = 0; i < count; ++i)
	{
		scanf("%d", &tmp);
		v[i] = tmp;
	}

	// cout << "init : ";
	// print(v);
	// cout << endl;

	map<string, int> cache;
	cout << (count <= k ? 0 : P(v, k, cache));

	return 0;
}
