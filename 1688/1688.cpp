#include <iostream>
using namespace std;

int main()
{
	unsigned long long int n, m, x = 1, sum = 0, tmp;
	cin >> n >> m;
	n *= 3;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		sum += tmp;
		if (sum <= n)
			x++;
	}
	if (sum <= n)
		cout << "Team.GOV!";
	else
		cout << "Free after " << x << " times.";
}