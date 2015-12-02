#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int count, tmp;
	cin >> count;
	double answer;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		answer += tmp;
	}

	answer /= count;
	cout << std::fixed << std::setprecision(6) << answer;
}