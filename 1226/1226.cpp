#include <iostream>
#include <stdio.h>
#include <cctype>
#include <stack>
using namespace std;

void flushStack(stack<char>& s)
{
	while(s.size() > 0)
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif	
	char c;
	stack<char> s;	
	while (std::cin.get(c))
	{
		if (isalpha(c))
		{
			s.push(c);
		}
		else 
		{
			flushStack(s);
			cout << c;
		}

	}
	flushStack(s);
	return 0;
}