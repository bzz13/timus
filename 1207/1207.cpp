#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
	int id;
	long long x;
	long long y;

	Point() { }

	Point(long long _x, long long _y) { x = _x; y = _y; }

	bool const vectorMultIsPositive(Point& other)
	{
		return y*other.x > x*other.y;
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
	if (count == 2)
	{
		cout << 1 << " " << 2 << endl;
		return 0;
	}

	vector<Point> points(count);

	long long minX, minY;
	for (int i = 0; i < count; ++i)
	{
		points[i].id = i + 1;
		cin >> points[i].x >> points[i].y;
	}

	Point s = points[0];

	for(auto e: points)
	{
		if (e.id == s.id)
			continue;

		Point basic;
		basic.x = e.x - s.x;
		basic.y = e.y - s.y;

		int pos = 0, neg = 0;
		for(auto p: points)
		{
			if (p.id == s.id || p.id == e.id)
				continue;

			Point n;
			n.x = p.x - s.x;
			n.y = p.y - s.y;
			if (basic.vectorMultIsPositive(n))
				pos++;
			else
				neg++;
		}
		// cout << "+:" << pos <<" -:"<< neg << endl;
		if (pos == neg)
		{
			cout << s.id << " " << e.id;
			return 0;
		}
	}
}