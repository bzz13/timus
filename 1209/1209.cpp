#include <iostream>
#include <math.h>
using namespace std;


int fastGetDigitAt(const unsigned long int & position)
{
	unsigned long int n = sqrt(2*position);
	return (n * (n + 1) / 2 == position) ? 1 : 0;
}

int main()
{
	unsigned long int count, position;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> position;
		cout << fastGetDigitAt(position - 1) << " ";
	}
} 