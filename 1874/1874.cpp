#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;
	double answer = (a*a + b*b) / 4 + sqrt(2) * a * b / 2;
	cout << setprecision(6) << fixed << answer;
	return 0;
}