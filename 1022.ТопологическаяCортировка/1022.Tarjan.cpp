#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Vertex
{
	int Id;
	vector<int> children;
};

void dfs(vector<Vertex> &v, const int& from, deque<int> &black, deque<int> &gray)
{
	if (find(gray.begin(), gray.end(), from) != gray.end()) throw - 1;

	gray.push_front(from);

	for (std::vector<int>::iterator i = v[from].children.begin(); i != v[from].children.end(); ++i)
		if (find(black.begin(), black.end(), *i) == black.end())
			dfs(v, *i, black, gray);

	gray.pop_front();
	black.push_front(from);
}

deque<int> topologySort(vector<Vertex> &v)
{
	deque<int> black;
	deque<int> gray;

	for (vector<Vertex>::iterator i = v.begin(); i != v.end(); ++i)
		if (find(black.begin(), black.end(), i->Id) == black.end())
			dfs(v, i->Id, black, gray);

	return black;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, tmp;
	cin >> count;
	vector<Vertex> A(count);
	for (int i = 0; i < count; ++i)
		A[i].Id = i;

	for (int i = 0; i < count; ++i)
	{
		while (true)
		{
			cin >> tmp;
			if (tmp == 0)
				break;
			A[i].children.push_back(tmp - 1);
		}
	}

	deque<int> answer = topologySort(A);
	while (answer.size() > 0)
	{
		cout << answer.front() + 1 << ' ';
		answer.pop_front();
	}


	return 0;
}
