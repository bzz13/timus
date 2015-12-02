#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;

	int max = a > b ? a : b;
	bool aIsMax = a > b;
	if (a + b < c)
		cout << "Impossible";
	else
		{
			while (c - (max--) < 0);
			max++;
			if (aIsMax)
				cout << max << " " << c - max;
			else
				cout << c - max << " " << max;
		}
}