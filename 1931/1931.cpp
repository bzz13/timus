#include <iostream>
using namespace std;

int main()
{
	int count, answer, currentIndex, currentValue = 1000000001, currentCount, max = 0, tmp;
	cin >> count;

	if (count == 1)
	{
		cin >> tmp;
		cout << 1;
		return 0;
	}

	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		if (tmp < currentValue)
		{
			currentValue = tmp;
			currentIndex = i;
			currentCount = i == 0 ? 1 : 2;
		}
		else
		{
			++currentCount;
		}
		if (currentCount > max)
		{
			max = currentCount;
			answer = currentIndex + 1;
		}
	}
	cout << answer;
}