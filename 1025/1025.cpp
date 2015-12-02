#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int count, tmp, answer = 0;
	cin >> count;
	vector<int> v;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < count / 2 + 1; ++i)
		answer += (v[i] / 2 + 1);
	cout << answer;
}