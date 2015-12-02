#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Interval
{
	int beginTime;
	int endTime;
};

bool f(Interval i1, Interval i2)
{
	if (i1.endTime < i2.endTime)
		return true;
	else
		if (i1.endTime == i2.endTime)
			return i1.beginTime < i2.beginTime;
		else
			return false;
}

int maxValue(int d[], int c)
{
	int answer = 0;
	for (int i = c; i >= 0; i--)
		if (d[i] > 0)
			return d[i];
	return answer;
}

int main()
{
	int count, b, e, maxTime = 0, answer = 0;
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

	sort(conf.begin(), conf.end(), f);

	for (std::vector<Interval>::iterator it = conf.begin(); it != conf.end(); ++it)
	{
		d[it->endTime] = max(d[it->endTime], 1 + maxValue(d, it->beginTime - 1));
		d[it->endTime] = max(answer, d[it->endTime]);
		answer = d[it->endTime];
	}

	cout << answer;
	delete[] d;
}