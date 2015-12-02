#include <iostream>
#include <string>
#include <map>
using namespace std;

const string gold = "gold";
const string silver = "silver";
const string bronze = "bronze";

int main()
{
	map<string, string> results;
	string teamName, tmp, result;
	for (int i = 0; i < 12; ++i)
	{
		cin >> teamName;
		switch (i/4)
		{
			case 0: results[teamName] = gold; break;
			case 1: results[teamName] = silver; break;
			case 2: results[teamName] = bronze; break;
		}
	}
	int count, max = 0, answer = 0;
	cin >> count;
	int *k = new int[count];
	int *a = new int[count];

	for (int i = 0; i < count; ++i)
	{
		cin >> k[i];
		a[i] = 0;
		while (k[i] --> 0)
		{
			cin >> teamName >> tmp >> result;
			if (results[teamName] == result)
				a[i] ++;
		}
		if (a[i] > max)
			max = a[i];
	}

	for (int i = 0; i < count; ++i)
		if (a[i] == max)
			answer ++;
	cout << answer * 5;

	delete[] a;
	delete[] k;
}