#include <iostream>
using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;
	int real = 0, expected = 0, b, g;
	for (int i = 0; i < n; ++i)
	{
		cin >> b >> g;
		real += g;
		expected += (b - 2);
	}

	// cout << real << " : " << expected;

	int diff = real - expected;
	int answer = k - 2 - diff;
	if (answer < 0)
		cout << "Big Bang!";
	else
		cout << answer;

}