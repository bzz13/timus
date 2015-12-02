#include <iostream>
using namespace std;

void ptintArr(int n[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << n[i] << " ";
	}
	cout << endl;
}

int main()
{
	int count;
	cin >> count;
	int *n = new int[count];

	int tmp = 0, prev;
	int m = 0, pos = 0;

	for (int i = 0; i < count; ++i)
	{
		prev = tmp;
		cin >> tmp;

		if (i > 0)
		{
			n[i-1] += tmp;
			// ptintArr(n, count);
			if ( n[i-1] > m) 
			{
				m = n[i-1];
				pos = i;
			}
		}
		n[i] = prev + tmp;
		
		if (n[i] > m)
		{
			m = n[i];
			pos = i + 1;
		}

		// ptintArr(n, count);
		// cout << endl;
	}

	cout << m << " " << pos;
	delete[] n;
}