#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
using namespace std;

std::map<string, int> counts;

int main()
{
	int total;

	cin >> total;
	while(total --> 0)
	{
		char input[20];
		cin.getline(input, sizeof(input));
		string s(input);
		if (s == "")
		{
			total++;
			continue;
		}
		counts[s]++;
	}

	string answer;
	int max = 0;
	for (std::map<string, int>::iterator it = counts.begin(); it != counts.end(); ++it)
	{
		if (it->second > max)
		{
			max = it->second;
			answer = it->first;
		}
		// cout << '"' << it->first << "\": " << it->second << endl;
	}
	cout << answer;
}