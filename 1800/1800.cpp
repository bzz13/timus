#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long double l, h, w, g = 9.81;
	cin >> l >> h >> w;
	w /= 30;

	if (2*h - l < 0.0)
	{
		cout << "butter";
		return 0;
	}

	long double t = sqrt( (2*h - l) / g ) / 10;
	// cout << "t = " << t << endl;
	long n = round(w*t); // count of half rotation
	// cout << "c = " << c << endl;

	if(n % 2 == 0)
		cout << "butter";
	else
		cout << "bread";
}