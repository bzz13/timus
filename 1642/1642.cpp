#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int goRight(std::vector<int>::iterator zero, std::vector<int>::iterator x)
{
	if (zero < x)
		return abs(*x);
	else
		return abs((*(zero+1))) * 2 + abs(*x);
}

int goLeft(std::vector<int>::iterator zero, std::vector<int>::iterator x)
{
	if (zero < x)
		return abs(*(zero-1)) * 2  + abs(*x);
	else
		return abs(*x);
}

int main()
{
	int n, start = 0, x, tmp;

	std::vector<int> points;
	cin >> n >> x;
	points.push_back(start);
	points.push_back(x);

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		points.push_back(tmp);
	}

	sort(points.begin(), points.end());

	// for (std::vector<int>::iterator i = points.begin(); i != points.end(); ++i) cout << *i << ' ';

	std::vector<int>::iterator positionX = find(points.begin(), points.end(), x);
	std::vector<int>::iterator positionZ = find(points.begin(), points.end(), start);

	if (
		(x < start && (positionX + 1 != positionZ || positionZ == points.end() - 1	)) ||
		(x > start && (positionX - 1 != positionZ									)) 
	)
	{
			cout << "Impossible";
			return 0;
	}

	cout << goRight(positionZ, positionX) << endl
	     << goLeft( positionZ, positionX);
}