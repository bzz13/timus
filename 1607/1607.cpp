#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int l = a, r = c;
	while(l < r)
	{
		if (l + b < r)
			l += b;
		else
			l = r;

		if (r - d > l)
			r -= d;
		else 
			r = l;

		// cout << l << " : " << r << endl;
	}
	cout << l;
}