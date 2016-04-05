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

void LCA(const int& u, vector<int>& ancestor, vector<bool>& color, vector<vector<int> >& links, DSU& dsu, vector<Edge> edges)
{
	ancestor[dsu.FindSet(u)] = u;
	for (int i = 0; i < links[u].size(); ++i)
	{
		int v = links[u][i];
		LCA(v, ancestor, color, links, dsu, edges);
		dsu.Union(u, v);
		ancestor[dsu.FindSet(u)] = u;
	}
	color[u] = true;
	for(auto edge: edges)
	{
		if (edge.Begin == u && color[edge.End])
			cout << u << " " << edge.End << ": " << ancestor[dsu.FindSet(edge.End)] << endl;
		if (edge.End == u   && color[edge.Begin])
			cout << edge.Begin << " " << u << ": " << ancestor[dsu.FindSet(edge.Begin)] << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.Torjan.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	cin >> count;
	vector<int> ancestor(count, -1);
	vector<bool> color(count, false);
	DSU dsu(count);

	vector<vector<int> > links(count);
	for (int i = 0; i < count; ++i)
	{
		int childCount;
		cin >> childCount;
		for (int j = 0; j < childCount; ++j)
		{
			int child;
			cin >> child;
			links[i].push_back(child);
		}
	}

	cin >> count;
	vector<Edge> edges(count);
	for (int i = 0; i < count; ++i)
	{
		int b,e;
		cin >> b >> e;
		edges[i] = Edge(b, e);
	}

	LCA(0, ancestor, color, links, dsu, edges);

	return 0;
}