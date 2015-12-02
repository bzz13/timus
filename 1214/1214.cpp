#include <iostream>
using namespace std;
int main()
{
	long x,y;
	
	cin >> x >> y;
	if (x <= 0 || y <= 0 || (x+y) % 2 == 0)
		cout << x << " " << y;
	else
		cout << y << " " << x;

	return 0;
}