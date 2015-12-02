#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;


int main()
{
	int count, tmp;
	map<int, int> dates;
	std::map<int, int>::iterator it;

	scanf("%d", &count);
	for (int i = 0; i < count; ++i)
	{
		scanf("%d", &tmp);
		dates[tmp] = 0;
	}

	scanf("%d", &count);
	for (int i = 0; i < count; ++i)
	{
		scanf("%d", &tmp);
		it = dates.find(tmp);
		if (it != dates.end())
			dates[tmp] ++;
	}

	int answer = 0;
	for (it = dates.begin(); it != dates.end(); ++it)
	{
		if (it->second > 0)
			answer += it->second;
	}
	cout << answer;
}