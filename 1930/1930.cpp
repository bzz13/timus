#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void printRoads(const map<int, vector<int>>& roads)
{
	for (auto u : roads)
	{
		cout << u.first << ": ";
		for (auto b : u.second)
			cout << b << " ";
		cout << endl;
	}
	cout << endl;
}

int min(const int& a, const int& b)
{
	return a < b ? a : b;
}

enum Color
{
	white,
	gray,
	black
};

struct Stage
{
	int costUp;
	int costDown;
	Color color;

	const int MinCost()
	{
		return min(costUp, costDown);
	}
};

void bfs(
	queue<int>& q,
	vector<Stage>& stages,
	map<int, vector<int>>& up,
	map<int, vector<int>>& down)
{
	if (q.size() == 0)
		return;

	int current = q.front();
	q.pop();

	stages[current].color = Color::gray;

	map<int, std::vector<int> >::iterator it;

	it = up.find(current);
	if (it != up.end())
		for (auto u : up[current])
		{
			stages[u].costUp = 
				min(
					stages[u].costUp,
					min(stages[current].costUp, stages[current].costDown + 1)
				);
			if (stages[u].color == Color::white)
				q.push(u);
		}

	it = down.find(current);
	if (it != down.end())
		for (auto d : down[current])
		{
			stages[d].costDown = 
				min(
					stages[d].costDown,
					min(stages[current].costDown, stages[current].costUp + 1)
				);
			if (stages[d].color == Color::white)
				q.push(d);
		}

	bfs(q, stages, up, down);

	stages[current].color = Color::black;
}

int findMinPathCost(
	const int& count, 
	const int& begin, 
	const int& end, 
	map<int, vector<int>>& up, 
	map<int, vector<int>>& down)
{
	if (begin == end)
		return 0;

	vector<Stage> stages(count, Stage{ 999999, 999999, Color::white });
	stages[begin].costUp = stages[begin].costDown = 0;

	queue<int> queue;
	queue.push(begin);

	bfs(queue, stages, up, down);

	return stages[end].MinCost();
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int n, count;
	cin >> n >> count;

	map<int, vector<int>> up;
	map<int, vector<int>> down;
	// for (int i = 0; i < n; ++i)
	// {
	// 	vector<int> v;
	// 	up[i] = v;
	// 	down[i] = v;
	// }

	for (int i = 0; i < count; ++i)
	{
		int bottom, top;
		// cin >> bottom >> top;
		scanf("%d%d", &bottom, &top);
		bottom--;
		top--;
		up[bottom].push_back(top);
		down[top].push_back(bottom);
	}

	int begin, end;
	// cin >> begin >> end;
	scanf("%d%d", &begin, &end);
	begin--;
	end--;

	// printRoads(up);
	// printRoads(down);

	cout << findMinPathCost(n, begin, end, up, down);
}