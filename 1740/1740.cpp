#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int l,k;
	double h;
	cin >> l >> k >> h;
	double min, max;
	min = (l / k) * h;
	max = (l / k + (l % k == 0 ? 0 : 1)) * h;

	cout << setprecision(6) << std::fixed;
	cout << min << ' ' << max;
}