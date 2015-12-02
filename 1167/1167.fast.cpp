#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <sstream>
#include <string>
#include <map>
using namespace std;

const int multiplayer = 1000;

long long min(const long long& a, const long long& b)
{
	return a < b ? a : b;
}

long long calcP(const std::vector<bool>::iterator& begin, const std::vector<bool>::iterator end)
{
	int bc = 0, wc = 0;
	for (std::vector<bool>::iterator i = begin; i != end; ++i)
	{
		if (*i)
			bc ++;
		else
			wc ++;
	}
	return wc * bc;
}

long long P(std::vector<bool>& stable, const int& count, const int& k, map<int, long long>& cache)
{
	long long result = 999999999;
	if (k == 1)
	{
		result = calcP(stable.begin(), stable.end());
	}
	else
	{
		for (int s = 1; s <= k + 1; ++s)
		{
			int inPref = stable.size() - s;
			if (inPref < k-1)
				break;

			long long 
				pref = cache[inPref*multiplayer + k-1],
				suff = calcP(stable.begin() + inPref, stable.end());
			result = min(result, pref + suff );
		}
	}
	return result;
}

void printMap(const map<int, long long>& map)
{
	for(auto p: map)
	{
		cout << p.first/multiplayer << ": "<< p.first%multiplayer << " --> " << p.second << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, k, tmp;

	map<int, long long> DP;

	scanf("%d%d", &count, &k);
	vector<bool> v;
	for (int i = 1; i <= count; ++i)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
		for (int j = 1; j < k; ++j)
		{
			DP[i*multiplayer + j] = P(v, i, j, DP);
		}
	}

	// printMap(DP);

	cout << P(v, count, k, DP);

	return 0;
}
