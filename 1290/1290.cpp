#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int count, tmp;
	cin >> count;
	std::vector<int> v;

	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		if (i != v.begin())
			cout << endl;
		cout << (*i);
	}
}