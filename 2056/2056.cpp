#include <iostream>
using namespace std;

int min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int main()
{
	int count, sum = 0;
	cin >> count;
	int *n = new int[count];
	for (int i = 0; i < count; ++i)
		cin >> n[i];

	for (int i = 0; i < count; ++i)
	{
		if (n[i] <= 3)
		{
			cout << "None";
			return 0;
		}
		sum += n[i];
	}
	if (sum == count * 5)
	{
		cout << "Named";
		return 0;
	}

	if (((float)sum) / count >= 4.5)
		cout << "High";
	else
		cout << "Common";

	delete[] n;
	return 0;
}