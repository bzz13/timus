#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double d, r;
	cin >> d >> r;

	cout << setprecision(3) << std::fixed;

	if (d / 2 >= r)
		cout << M_PI * r * r;
	else
		if (r >= ((sqrt(2) * d) / 2))
			cout << d * d;
		else
		{
			float Ssec = 4*(M_PI/2 - 2 * acos(d / (2*r))) * ((r*r)/2);
			float Strn = 2*d*sqrt((r*r) - ((d*d)/4));
			cout << Ssec + Strn;
		}
}