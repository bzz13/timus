#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		string s, sub;
		cin >> s;
		int position = 0, length = s.length();
		while(position < length)
		{
			if (s[position] == 'o' && s[position+1] == 'u' && s[position+2] == 't' && s[position+3] == 'p' && s[position+4] == 'u' && s[position+5] == 't')
			{
				position += 6;
				continue;
			}
			if ((s[position] == 'p' && s[position+1] == 'u' && s[position+2] == 't' && s[position+3] == 'o' && s[position+4] == 'n') || 
				(s[position] == 'i' && s[position+1] == 'n' && s[position+2] == 'p' && s[position+3] == 'u' && s[position+4] == 't'))
			{
				position += 5;
				continue;
			}
			if ((s[position] == 'o' && s[position+1] == 'u' && s[position+2] == 't') || 
				(s[position] == 'o' && s[position+1] == 'n' && s[position+2] == 'e'))
			{
				position += 3;
				continue;
			}
			if (s[position] == 'i' && s[position+1] == 'n')
			{
				position += 2;
				continue;
			}
			break;
		}
		cout << (position == length ? "YES" : "NO" ) << endl;
	}

	return 0;
}