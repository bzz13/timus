#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;


int main()
{
	std::map<string, bool> shops;

	int count, answer = 0;
	cin >> count;
	char line[30];

	for (int i = 0; i <= count; ++i)
	{
		// lines
		gets(line);
		string name(line);

		if (shops[name])
			answer ++;
		else
			shops[name] = true;
	}
	cout << answer;
}