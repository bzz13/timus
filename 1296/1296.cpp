#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int count;
	cin >> count;
	int *ns = new int[count];

	for (int i = 0; i < count; ++i)
		cin >> ns[i];

	int ans = 0, sum = 0;
	for (int i = 0; i < count; ++i)
	{
		if (sum + ns[i] > 0)
			sum += ns[i];
		else
			sum = 0;
		ans = max(ans, sum);
	}

	cout << ans;

	delete[] ns;
}