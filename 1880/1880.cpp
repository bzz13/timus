#include <iostream>
#include <map>
using namespace std;

int findInDict(map<int, int> dictionary, const int &val)
{
	int result = 0;
	for (std::map<int, int>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		if(it->second == val)
			result ++;
	}
	return result;
}

int main()
{
	map<int, int> dictionary;
	int count, tmp;

	const int N = 3;
	for (int n = 0; n < N; ++n)
	{
		cin >> count;
		for (int i = 0; i < count; ++i)
		{
			cin >> tmp;
			dictionary[tmp] ++;
		}
	}

	cout << findInDict(dictionary, N);
}