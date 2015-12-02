#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int i1 = 0, i2 = 0, s1 = str1.size(), s2 = str2.size(), answer = 0;
	char c1, c2;
	while (i1 + i2 < s1 + s2)
	{
		if (i1 == s1)
		{
			answer++;
			i2++;
			continue;
		}
		if (i2 == s2)
		{
			answer++;
			i1++;
			continue;
		}

		c1 = str1[i1];
		c2 = str2[i2];

		if ((c1 == 'L' || c2 == 'L') && c1 != c2)
		{
			if (c1 == 'L')
				i2++;
			else
				i1++;
		}
		else
		{
			i1++;
			i2++;
		}
		answer++;
	}
	cout << answer;
}