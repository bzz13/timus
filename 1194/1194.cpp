#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct group
{
	int id;
	int groupsCount;
	int peopleCount;
	int answer;
};

void printGroup(const group& g)
{
	cout << "{ id: " << g.id << ", gc: " << g.groupsCount
		<< ", pc: " << g.peopleCount << ", a: " << g.answer
		<< " }" << endl;
}

int readGroup(int n, string input, std::map<int, group>* all)
{
	int c, answer = 0;
	if (input == "")
		return answer;
	stringstream in(input);
	group current = { 0, 0, 0, 0 };
	in >> current.id >> current.groupsCount;
	if (current.id == 1)
		(*all)[current.id].peopleCount = n;
	c = (*all)[current.id].peopleCount;

	for (int i = 0; i < current.groupsCount; ++i)
	{
		group tmp = { 0, 0, 0, 0 };
		in >> tmp.id >> tmp.peopleCount;
		current.answer += tmp.peopleCount * (c - tmp.peopleCount);
		answer += tmp.peopleCount * (c - tmp.peopleCount);
		c -= tmp.peopleCount;

		(*all)[tmp.id] = tmp;
	}
	(*all)[current.id] = current;
	return answer;
}

int main()
{
	int n, k, answer = 0, c;
	cin >> n >> k;

	std::map<int, group> all;

	string input;
	getline(cin, input);

	while(getline(cin, input)) 
	{
		if (input == "")
			break;
		answer += readGroup(n, input, &all);
	}

	// for (std::map<int, group>::iterator it = all.begin(); it != all.end(); ++it)
	// {
	// 	printGroup(it->second);
	// }

	cout << answer;
}