#include <iostream>
#include <string>
using namespace std;

bool good(int num)
{
	int r = 0, l = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (i < 3)
			r += num % 10;
		else
			l += num % 10;
		num = num / 10;
	}
	return l == r;
}

int main()
{
	int number, prev, next;
	cin >> number;
	prev = number - 1;
	next = number + 1;
	if (good(prev) || good(next))
		cout << "Yes";
	else 
		cout << "No";
}