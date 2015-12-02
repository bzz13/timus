#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct City
{
public:
	int id;
	int x;
	int y;
	
	bool operator <(const City& other) const
	{
		if (x < other.x)
			return true;
		else
			if (x == other.x)
				return y < other.y;
			else
				return false;
	}

	int dist() const
	{
		return x*x + y*y;
	}

	void print()
	{
		cout << id << "(" << x << ", " << y << "): " << dist() << endl;
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
	std::vector<City> v(count);
	for (int i = 0; i < count; ++i)
	{
		int x, y;
		cin >> x >> y;
		v[i].id = i + 1;
		v[i].x = x;
		v[i].y = y;
	}

	sort(v.begin(), v.end());
	// for (std::vector<City>::iterator c = v.begin(); c != v.end(); ++c)
	// 	c->print();

	for (int i = 0; i < count / 2; ++i)
		cout << v[i*2].id << ' ' << v[i*2+1].id << endl;
}