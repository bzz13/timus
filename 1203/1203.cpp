#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Interval
{
	int beginTime;
	int endTime;
};

int main()
{
	int count, b, e, maxTime = 0;
	cin >> count;
	std::vector<Interval> conf;
	for (int i = 0; i < count; ++i)
	{
		cin >> b >> e;
		Interval t = { b, e };
		maxTime = max(e, maxTime);
		conf.push_back(t);
	}

	int *d = new int[maxTime + 1];

	for (int i = 0; i <= maxTime; ++i)
		d[i] = 0;

	for (int i = 0; i <= maxTime; ++i)
	{
		for (std::vector<Interval>::iterator it = conf.begin(); it != conf.end(); ++it)
		{
			if (it->endTime == i)
				d[i] = max(d[i], 1 + d[it->beginTime - 1]);
		}
		if (i > 0)
			d[i] = max(d[i], d[i - 1]);
	}

	cout << d[maxTime];
	delete[] d;
}