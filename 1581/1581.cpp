#include <iostream>
using namespace std;

int main()
{
	int count, prev, n = 1, tmp;
	cin >> count;
	cin >> prev;
	
	while (count --> 1)
	{
		cin >> tmp;
		if (tmp == prev)
		{
			n++;
			continue;
		}
		cout << n << " " << prev << " ";
		prev = tmp;
		n = 1;		
	}
	cout << n << " " << prev << " ";
}