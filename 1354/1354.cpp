#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

bool isPoly(string& s, const int& offset)
{
	int begin = offset, end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin++] != s[end--])
			return false;
	}
	return true;
}

string reverse(string& s, const int& offset)
{
	int end = offset;
	stringstream ss;
	while (end >= 0)
		ss << (s[end--]);
	return ss.str();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	string S1, S2;
	cin >> S1;
	int polyb = -1, prevpolyb = -1;

	for (int i = S1.size(); i > -1; --i)
	{
		if (isPoly(S1, i))
		{
			prevpolyb = polyb;
			polyb = i;
		}
	}

	S2 = reverse(S1, polyb != 0 ?  polyb - 1 : prevpolyb - 1);

	cout << S1 << S2;
}