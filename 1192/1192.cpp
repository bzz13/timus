#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double v,a, g = 10.0, pi = 3.1415926535;
	cin >> v >> a;
	double k, answer;
	cin >> k;

	answer = (v * v * sin(2 * a * pi / 180 ) * k) / (g * (k - 1));
	cout << setprecision(2) << fixed << answer;
}