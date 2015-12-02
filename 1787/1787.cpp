#include <iostream>
using namespace std;

int main()
{
	int k, n, ai, answer = 0;
	cin >> k >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> ai;
		answer += ai;
		answer -= k;
		answer = answer < 0 ? 0 : answer;
	}
	cout << answer;
}