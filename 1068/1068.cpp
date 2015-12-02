#include <iostream>
using namespace std;

int main()
{
	int count, sum;
	cin >> count;
	if ( count > 0)
		sum = count * ( count + 1 ) /2;
	else
		sum = (count + 1) * (2 - count) /2;
	cout << sum;
}