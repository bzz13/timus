#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, rightCount = 0, answer = 0;
	cin >> count;
	char c;
	
	for (int i = 0; i < count; ++i)
	{
		cin >> c;
		if (c == '<')
			answer += rightCount;
		else 
			if (c == '>')
				rightCount ++;
	}

	cout << ((rightCount == 0 || rightCount == count) ? 0 : answer);
}