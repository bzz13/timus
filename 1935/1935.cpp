#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int count, tmp, answer;
	std::vector<int> v;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int l = 0, r = 0;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if (it == v.begin())
			answer = (*it) * 2;
		else
			answer += (*it);
	}

	cout << answer;
}