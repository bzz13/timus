#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool findPoint(const int& x,const int& y, vector<pair<int, int>>& ps)
{
	for(auto p: ps)
		if (p.first == x && p.second == y)
			return true;
	return false;
}

double distance(const pair<int,int>& a)
{
	return sqrt((double)(a.first*a.first + a.second*a.second));
}

bool sortFunc (const pair<int,int> & a, const pair<int,int> & b)
{ 
	return distance(a) < distance(b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	cin >> count;
	vector<pair<int,int>> points(count);
	for (int i = 0; i < count; ++i)
		cin >> points[i].first >> points[i].second;

	int x = 0, y = 0, cnt = 0;
	while (findPoint(x, y, points))
		if ( (cnt++) % 2 == 0)
			x++;
		else
			y++;

	// cout << "start: {" << x << ", " << y << '}' << endl;

	for(auto & p: points)
	{
		p.first -= x;
		p.second -= y;
	}

	sort(points.begin(), points.end(), sortFunc);

	// for(auto p: points)
	// 	cout << '{' << p.first << ", " << p.second << '}' << endl;

	cout << x << ' ' << y << ' ' << std::fixed << setprecision(9) << distance(*(points.end()-1)) << endl;

	return 0;
}