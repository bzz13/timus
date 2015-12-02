#include <iostream>
using namespace std;

int main()
{
	unsigned long int n, m, min, answer;
	cin >> n >> m;

	min = n < m ? n : m;
	bool mIsMin = m == min && n != min;
	answer = min * 2 - 2;
	if (mIsMin)
		answer++;
	cout << answer;
} 