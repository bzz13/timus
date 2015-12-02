#include <iostream>
#include <cmath>
using namespace std;

float getMaxSize(const int& figureType, const int& a)
{
	switch (figureType)
	{
		case 1:
			return 2*a;
		case 2:
			return sqrt(2.0)*a;
		default:
			return a;
	}
}

float getMinSize(const int& figureType, const int& a)
{
	switch (figureType)
	{
		case 1:
			return 2*a;
		case 2:
			return a;
		default:
			return (sqrt(3.0) * a) / 2; 
	}
}

int main()
{
	int figureType, a, count, answer = 0;
	float maxSize, minSize;
	cin >> figureType >> a;
	maxSize = getMaxSize(figureType, a);
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> figureType >> a;
		if (getMinSize(figureType,a) <= maxSize )
			answer++;
	}
	cout << answer;
	return 0;
}