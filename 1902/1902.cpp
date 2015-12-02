#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n, t, s, t1, dt;
	cin >> n >> t >> s;

	std::cout << std::fixed;
	std::cout << std::setprecision(6);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> t1;
		dt = (t - t1 + s) / 2;
		cout << (t1 + dt) << endl;
	}
}