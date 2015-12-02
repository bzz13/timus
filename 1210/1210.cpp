#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct E
{
	int from;
	int to;
	int cost;
};

struct V
{

	int id;
	int cost;
	vector<E> edges;

	void print()
	{
		cout << id << ": " << cost << endl;
		for(auto e: edges)
			cout << "\t --(" << e.cost << ")--> " << e.to << endl;
		cout << endl;
	}
};

const int maxCost = 999999;
const int multiplyer = 100;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	char asterisk;
	int vertexCount, levelCount, from, cost, tmp, answer = maxCost, fromV, toV;

	V root = {1, 0};

	map<int, V> vertexes;
	vertexes[root.id] = root;

	cin >> levelCount;
	for (int level = 1; level <= levelCount; ++level)
	{
		cin >> vertexCount;
		for (int v = 1; v <= vertexCount; ++v)
		{
			cin >> from;
			while(from != 0)
			{
				cin >> cost;

				fromV = (level - 1)*multiplyer + from;
				toV   =  level     *multiplyer + v;
				E e = {fromV, toV, cost};
				V v = {toV, maxCost};

				vertexes[fromV].edges.push_back(e);
				vertexes[v.id] = v;

				cin >> from;
			}
		}
		cin >> asterisk;
	}

	// for (auto p: vertexes) p.second.print();

	queue<V> qv;
	qv.push(vertexes[root.id]);
	while(qv.size() > 0)
	{
		V current = qv.front();
		qv.pop();

		for (auto e: current.edges)
		{
			cost = current.cost + e.cost;
			if (vertexes[e.to].cost > cost)
			{
				vertexes[e.to].cost = cost;
				if (e.to > levelCount*multiplyer)
				{
					if (cost < answer)
						answer = cost;
				}
				else
					qv.push(vertexes[e.to]);
			}
		}
	}

	// for (auto p: vertexes) p.second.print();
	cout << answer;

	return 0;
}
