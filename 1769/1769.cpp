#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

long long splitInputStringIntoSetOfNums(string& input, const int& lenght, const long long& low, const long long& high, set<int>& nums)
{
	long long num, count = input.size();
	nums.clear();
	for (int i = 0; i <= count - lenght; ++i)
	{
		num = strtol(input.substr(i, lenght).c_str(), 0, 10);
		if (low <= num && num < high)
			nums.insert(num);
	}

	return high - low;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	string s;
	cin >> s;

	set<int> nums;
	for (int l = 1; l <= s.size(); ++l)
	{
		long long 
			low = pow(10, l - 1),
			high = pow(10, l),
			max = splitInputStringIntoSetOfNums(s, l, low, high, nums);
		if (nums.size() < max)
		{
			for(int i = low; i < high; ++i)
			{
				if (nums.find(i) == nums.end())
				{
					cout << i;
					goto stop;
				}
			}
		}
	}
	stop:
	return 0;
}