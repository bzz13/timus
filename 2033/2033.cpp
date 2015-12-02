#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int count = 6;
	std::map<string, int> devices;
	std::map<string, int>::iterator find;
	std::map<string, int> costs;

	string name, device; int cost;
	for (int i = 0; i < count; ++i)
	{
		cin >> name >> device >> cost;
		find = devices.find(device);
		if (find == devices.end())
		{
			devices[device] = 1;
			costs[device]   = cost;
		}
		else
		{
			devices[device] ++;
			costs[device] = min(costs[device], cost);
		}
	}

	std::vector<string> most;
	int counter = 0;
	for (std::map<string, int>::iterator it = devices.begin(); it != devices.end(); ++it)
		counter = max(counter, it->second);

	for (std::map<string, int>::iterator it = devices.begin(); it != devices.end(); ++it)
		if (it->second == counter)
			most.push_back(it->first);

	// for (std::map<string, int>::iterator it = devices.begin(); it != devices.end(); ++it)
	// 	cout << it->first << " (" << it->second << ") - minCost - " << costs[it->first] << endl;

	if (most.size() == 1)
	{
		cout << *(most.begin());
		return 0;
	}

	int minCost = 2000000; string answer;
	for (std::vector<string>::iterator it = most.begin(); it != most.end(); ++it)
	{
		if (costs[*it] < minCost )
		{
			minCost = costs[*it];
			answer = *it;
		}
	}
	cout << answer;
	return 0;
}