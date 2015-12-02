#include <iostream>
#include <string>
using namespace std;

void printArray(int arr[], const int& x, const int& y)
{
	for (int j = 0; j < y; ++j)
	{
		for (int i = 0; i < x; ++i)
			cout << arr[j*y + i];
		cout << endl;
	}
}

int main()
{
	int changes = 0;
	string a, b = "Sandro", substr;
	cin >> a;

	const int x = a.size() + 1;
	const int y = b.size() + 1;

	int *d = new int[x * y];
	int u, v, answer = 0;
	for (int j = 0; j < y; ++j)
	{
		for (int i = 0; i < x; ++i)
		{
			if (i == 0 || j == 0)	
			{
				d[j*y + i] = 0;
				continue;
			}
			if (b[j - 1] == a[i - 1])
				d[j*y + i] = d[(j-1)*y + i- 1] + 1;
			else
				d[j*y + i] = 0;

			if (d[j*y + i] > answer)
			{
				answer = d[j*y + i];
				u = j; v = i;
				substr = b.substr(u - answer, answer);
			}

			// cout << b[j - 1] << '?' << a[i - 1] << " -> " << d[j*y + i] << endl;
		}
	}

	printArray(d, x - 1, y - 1);
	cout << endl << substr << endl;
}