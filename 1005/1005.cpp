#include <iostream>
#include <cmath>

using namespace std;

int getDiff(int arr[], int size, int pos)
{
	int right = 0, left = 0;
	for (int i = 0; i < size; ++i)
	{
		if ((pos & (1 << i)) > 0)
			right += arr[i];
		else
			left += arr[i];
	}
	return abs(right - left);
}

int main()
{
	int count;
	cin >> count;
	int *values = new int[count];
	for (int i = 0; i < count; ++i)
		cin >> values[i];
	int min = 999999999;
	for (int i = 0; i < (2 << count); ++i)
	{
		int tmp = getDiff(values, count, i);
		if (tmp < min)
			min = tmp;
	}
	cout << min;
	delete[] values;
}