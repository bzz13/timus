#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

bool ContainsInVector(std::vector<string> *v, string s)
{
	bool find = false;
	for (std::vector<string>::iterator it = v->begin(); it != v->end(); ++it)
	{
		if (*it == s) { find = true; break; }
	}
	return find;
}

void AddRelations(std::map<string, std::vector<string>* > relations, string a, string b, string c)
{
	if (!ContainsInVector(relations[a], b))
		relations[a]->push_back(b);
	if (!ContainsInVector(relations[a], c))
		relations[a]->push_back(c);

	if (!ContainsInVector(relations[b], a))
		relations[b]->push_back(a);
	if (!ContainsInVector(relations[b], c))
		relations[b]->push_back(c);

	if (!ContainsInVector(relations[c], a))
		relations[c]->push_back(a);
	if (!ContainsInVector(relations[c], b))
		relations[c]->push_back(b);
}

const int inf = 9999;
const string Isenbaev = "Isenbaev";
int main()
{
	int count;
	string a, b, c;
	std::map<string, int> result;
	std::map<string, std::vector<string>* > relations;

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> a >> b >> c;
		result[a] = result[b] = result[c] = inf;

		map<string, vector<string>* >::iterator it;
		it = relations.find(a);
		if (it == relations.end())
			relations[a] = new vector<string>();
		it = relations.find(b);
		if (it == relations.end())
			relations[b] = new vector<string>();
		it = relations.find(c);
		if (it == relations.end())
			relations[c] = new vector<string>();
		AddRelations(relations, a, b, c);
	}
	
	map<string, vector<string>* >::iterator findIt = relations.find(Isenbaev);
	if (findIt != relations.end())
	{
		result[Isenbaev] = 0;
		queue<string> q;
		q.push(Isenbaev);

		while (q.size() > 0)
		{
			string tmp = q.front();
			q.pop();

			int next = result[tmp] + 1;
			for (std::vector<string>::iterator i = relations[tmp]->begin(); i != relations[tmp]->end(); ++i)
			{
				if (result[*i] > next)
				{
					result[*i] = next;
					q.push(*i);
				}
			}
		}
	}

	for (std::map<string, int>::iterator i = result.begin(); i != result.end(); ++i)
	{
		cout << i->first << " ";
		if (i->second == inf)
			cout << "undefined" << endl;
		else
			cout << i->second << endl;
	}

	for (std::map<string, std::vector<string>* >::iterator it = relations.begin(); it != relations.end(); ++it)
	{
		delete (it->second);
	}
}