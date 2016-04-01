#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Edge
{
public:
	Edge() { }
	Edge(const int& b, const int& e)
	{
		Begin = b;
		End = e;
		Removed = false;
	}

	int Begin;
	int End;
	bool Removed;
};

class DSU
{
	vector<int> parent;
	vector<int> rank;

	void Link(const int& x, const int& y)
	{
		if (rank[x] > rank[y])
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
			if (rank[x] == rank[y])
				rank[y] ++;
		}
	}

public:
	DSU(const int& size) 
	{
		ComponentsCount = size;
		rank = vector<int>(size);
		parent = vector<int>(size);
		for (int i = 0; i < size; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	};

	int ComponentsCount;


	void Union(const int& x, const int& y)
	{
		int sx = FindSet(x), sy = FindSet(y);
		if (sx != sy)
		{
			Link(sx, sy);
			ComponentsCount --;
		}
	}

	int FindSet(const int& v)
	{
		if (v != parent[v])
			parent[v] = FindSet(parent[v]);
		return parent[v];
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	cin >> count;
	DSU dsu(count);

	cin >> count;
	vector<Edge> edges(count);
	for (int i = 0; i < count; ++i)
	{
		int b,e;
		cin >> b >> e;
		edges[i] = Edge(b - 1, e - 1);
	}

	cin >> count;
	vector<int> removedEdges(count);
	for (int i = 0; i < count; ++i)
	{
		int r;
		cin >> r;
		removedEdges[i] = r - 1;
		edges[removedEdges[i]].Removed = true;
	}

	for(auto e: edges)
	{
		if (!e.Removed)
		{
			dsu.Union(e.Begin, e.End);
		}
	}

	reverse(removedEdges.begin(), removedEdges.end());
	stack<int> result;
	for(auto re: removedEdges)
	{
		result.push(dsu.ComponentsCount);
		dsu.Union(edges[re].Begin, edges[re].End);
	}

	while(result.size() > 0)
	{
		cout << result.top() << " ";
		result.pop();
	}

	return 0;
}