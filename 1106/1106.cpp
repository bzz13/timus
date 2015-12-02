#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;


struct Vertex
{
	int id;
	int color;
	int componentNumber;
	vector<int> vrts;
};

void printVertex(Vertex v)
{
	cout << "{ id: " << v.id << ", clr: " << v.color << ", cmp: " << v.componentNumber
		 << ", vrts: [ ";
	for (std::vector<int>::iterator it = v.vrts.begin(); it != v.vrts.end(); ++it)
	{
		if (it != v.vrts.begin())
			cout << ", ";
		cout << *it;
	}
	cout << " ]}" << endl;
}

Vertex readVertex(int id)
{
	int t;
	Vertex tmp = { id, -1, -1, vector<int>()};
	while(true)
	{
		cin >> t;
		if (t == 0)
			break;
		else
			tmp.vrts.push_back(t);
	}
	return tmp;
}

void fillComponents(map<int, Vertex> *all, map<int, map<int, Vertex> >* components)
{
	int cmp = 0;
	for (map<int, Vertex>::iterator it = (*all).begin(); it != (*all).end(); ++it)
	{
		if (it->second.componentNumber == -1)
		{
			cmp++;
			it->second.componentNumber = cmp;
			stack<int> stck;
			stck.push(it->first);
			while(stck.size() > 0)
			{
				Vertex tmp = (*all)[stck.top()];
				stck.pop();
				for (vector<int>::iterator itr = tmp.vrts.begin(); itr != tmp.vrts.end(); ++itr)
				{
					if ((*all)[*itr].componentNumber == -1)
					{
						(*all)[*itr].componentNumber = cmp;
						stck.push(*itr);
					}
				}
			}
		}
	}

	for (int i = 1; i <= cmp; ++i)
		(*components)[i] = map<int, Vertex>();

	for (map<int, Vertex>::iterator it = (*all).begin(); it != (*all).end(); ++it)
		(*components)[(it->second).componentNumber][it->first] = it->second;

}

int main()
{
	int count;
	cin >> count;

	map<int, Vertex> all;

	for (int i = 0; i < count; ++i)
		all[i+1] = readVertex(i+1);

	map<int, map<int, Vertex> > components;
	fillComponents(&all, &components);

	for (map<int, map<int, Vertex> >::iterator it = components.begin(); it != components.end(); ++it)
	{
		map<int, Vertex>::iterator itr = (it->second).begin();

		(*itr).second.color = 0;
		stack<int> stck;
		stck.push((*itr).second.id);

		while(stck.size() > 0)
		{
			Vertex tmp = components[it->first][stck.top()];
			stck.pop();
			// printVertex(tmp);
			for (std::vector<int>::iterator v = tmp.vrts.begin(); v != tmp.vrts.end(); ++v)
			{
				if (components[it->first][*v].color == -1)
				{
					components[it->first][*v].color = (tmp.color + 1) % 2;
					stck.push(components[it->first][*v].id);
				}
			}
		}
	}

	int findColor = 0;
	vector<int> answer;
	for (map<int, map<int, Vertex> >::iterator it = components.begin(); it != components.end(); ++it)
	{
		// cout << it->first << ": ";
		for (map<int, Vertex>::iterator itr = (it->second).begin(); itr != (it->second).end(); ++itr)
		{
			// cout << '\t' ;
			// printVertex(itr->second);
			if ((itr->second).color == findColor)
				answer.push_back((itr->second).id);
		}
	}

	cout << answer.size();
	if (answer.size() > 0)
	{
		cout << endl;
		for (std::vector<int>::iterator a = answer.begin(); a != answer.end(); ++a)
		{
			if (a != answer.begin())
				cout << " ";
			cout << (*a);
		}
	}
}