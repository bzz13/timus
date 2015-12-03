#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;
int main()
{
	const string delimiter = "-";

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif

	string exitName, tmp;
	cin >> exitName;

	// cout << exitName << endl;

	map<string, int> dict;
	dict[exitName] = 1;
	vector<pair<int, int> > edges;

	while(true)
	{
		cin >> tmp;
		if (tmp == "#")
			break;
		int pos = tmp.find(delimiter);
		string 
			b = tmp.substr(0, pos),
			e = tmp.substr(pos+1);

		if (!dict[b])
			dict[b] = dict.size();
		if (!dict[e])
			dict[e] = dict.size();

		edges.push_back(pair<int, int>(dict[b], dict[e]));
	}

	// for(auto e: edges)
	// 	cout << e.first << " --> " << e.second << endl;
	cout << dict.size() - 1;

	return 0;
}