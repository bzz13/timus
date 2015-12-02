#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool F(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	int girls, boys, answer = 0, r, min, win, lost;
	cin >> girls >> boys;
	std::vector<int> girlValues(girls);
	std::vector<int> boyValues(boys);

	for (int i = 0; i < girls; ++i)
	{
		cin >> girlValues[i];
		answer += girlValues[i];
	}
	for (int i = 0; i < boys; ++i)
	{
		cin >> boyValues[i];
	}

	sort(girlValues.begin(), girlValues.end(), F);
	sort(boyValues.begin(), boyValues.end(), F);

	if (girls >= boys)
	{
		answer = 0;
		for (int g = boys; g < girls; ++g)
		{
			answer += girlValues[g];
		}
	}
	else
	{
		for (int g = 0; g < girls; ++g)
		{
			win = girlValues[g] + g * boyValues[g];
			lost = 0;
			for (int b = g + 1; b < boys; ++b)
				lost += boyValues[b];

			if (win > lost)
				answer = answer - win + lost;
			else
				break;
		}
	}

	cout << answer;
}