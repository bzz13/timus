#include <iostream>
using namespace std;


int main()
{
	long long int n, count, tmp, answer;
	bool neg = false;

	cin >> n >> count;
	cin >> answer;
	for (int i = 1; i < count; ++i)
	{
		cin >> tmp;
		answer = (answer + tmp - n);
		if (answer < 0)
			neg = true;
	}

	cout << neg ? 0 : answer;
}