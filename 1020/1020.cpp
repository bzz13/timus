#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct Dot
{
	double x;
	double y;
};

double getLenght(Dot a, Dot b)
{
	double	dx = a.x - b.x,
			dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

int main()
{
	int count;
	double x, y, r, answer = 0, pi = 3.1415926535897;
	cin >> count >> r;
	vector<Dot> v;
	for (int i = 0; i < count; ++i)
	{
		cin >> x >> y;
		Dot d = {x,y};
		v.push_back(d);
	}

	for (int i = 0; i < count; ++i)
		answer += getLenght(v[i], v[(i+1) % count]);
	answer += 2 * pi * r;

	std::cout << std::setprecision(2);
	std::cout << std::fixed;
	cout << answer;
}