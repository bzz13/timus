#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count;
	cin >> count;
	std::vector<short> v(count + 1);
	for (int i = 1; i <= count; ++i)
	{
		short a,b;
		cin >> a >> b;
		v[i] = a + b;
	}
	for (int i = count; i > 0; --i)
	{
		v[i-1] += v[i] / 10;
		v[i] %= 10;
	}
	for (int i = 0; i <= count; ++i)
	{
		if (i == 0 && v[i] == 0)
			continue;
		cout << v[i];
	}
}