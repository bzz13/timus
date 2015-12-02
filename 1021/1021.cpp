#include <iostream>
#include <map>
using namespace std;

const int limit = 10000;

int main()
{
	int count, tmp;
	bool has = false;
	cin >> count;
	std::map<int, bool> expected;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		expected[limit - tmp] = true;
	}
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		has = has || expected[tmp];
	}
	if (has)
		cout << "YES";
	else
		cout << "NO";
}