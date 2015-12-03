#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Vertex
{
	int Id;
	vector<int> children;
};

vector<int> dfs(vector<Vertex> &v, const int& from, deque<int> &black, deque<int> &gray)
{
	vector<int> component;
	// if (find(gray.begin(), gray.end(), from) != gray.end()) throw - 1;

	// gray.push_front(from);

	for (auto i: v[from].children)
		if (find(black.begin(), black.end(), i) == black.end())
		{
			vector<int> internal = dfs(v, i, black, gray);
			component.insert(component.cend(), internal.begin(), internal.end());
		}

	// gray.pop_front();
	black.push_front(from);
	component.insert(component.cbegin(), from);
	return component;
}

vector<vector<int> > components(vector<Vertex> &v)
{
	vector<std::vector<int> > components;
	deque<int> black;
	deque<int> gray;

	for (auto i: v)
		if (find(black.begin(), black.end(), i.Id) == black.end())
			components.push_back(dfs(v, i.Id, black, gray));

	return components;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, K, M, b, e;
	cin >> count >> K >> M;
	vector<Vertex> A(count);
	for (int i = 0; i < count; ++i)
		A[i].Id = i;

	for (int i = 0; i < K; ++i)
	{
		cin >> b >> e;
		b--; e--;
		A[b].children.push_back(e);
	}

	vector<vector<int> > comps = components(A);
	// for (auto comp: comps)
	// {
	// 	for(auto c: comp)
	// 		cout << c + 1 << ' ';
	// 	cout << endl;
	// }
	cout << comps.size() - 1;

	return 0;
}
