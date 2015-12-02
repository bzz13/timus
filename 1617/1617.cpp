#include <iostream>
#include <map>
using namespace std;

int main()
{
	int count, tmp, answer = 0;
	map<int, int> sizes;

	cin>>count;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		sizes[tmp]++;
		if (sizes[tmp] == 4)
		{
			answer ++;
			sizes[tmp] = 0;
		}
	}
	cout << answer;
	return 0;
}