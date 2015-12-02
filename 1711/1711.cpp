#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Task
{
public:
	int difficulty;
	string codeName;
	vector<string> names;

	void readNames()
	{
		string tmp;
		cin >> tmp; names.push_back(tmp);
		cin >> tmp; names.push_back(tmp);
		cin >> tmp; names.push_back(tmp);

		sort(names.begin(), names.end());
	}

	bool generateCodeNames(int index = 0, const string& previousVal = "")
	{
		if (index == 0)
		{
			codeName = names[0];
			return true;
		}
		else
		{
			for (std::vector<string>::iterator i = names.begin(); i != names.end(); ++i)
			{
				if (*i > previousVal)
				{
					codeName = *i;
					return true;
				}
			}
			return false;
		}
	}

	void print()
	{
		cout << difficulty << ": [";
		for (std::vector<string>::iterator i = names.begin(); i != names.end(); ++i)
			if (i == names.begin())
				cout << *i;
			else
				cout << ", " << *i;
		cout << "]" << endl;
	}
};

bool sortF(const Task& a, const Task& b)
{
	return a.difficulty < b.difficulty;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int count, tmp;
	cin >> count;
	std::vector<Task> tasks;

	for (int i = 0; i < count; ++i)
	{
		Task t;
		t.readNames();
		tasks.push_back(t);
	}
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		tasks[tmp - 1].difficulty = i;
	}

	sort(tasks.begin(), tasks.end(), sortF);

	// for (std::vector<Task>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	// 	i->print();

	bool possible = tasks[0].generateCodeNames();
	for (int i = 1; i < count && possible; ++i)
		possible = possible && tasks[i].generateCodeNames(i, tasks[i - 1].codeName);

	if (!possible)
		cout << "IMPOSSIBLE";
	else
		for (int i = 0; i < count; ++i)
			cout << tasks[i].codeName << endl;
}