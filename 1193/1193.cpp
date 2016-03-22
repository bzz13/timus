#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Timer
{
	int T1;
	int T2;
	int T3;

	const string ToString()
	{
		std::ostringstream stm;
		stm << "[" << T1 << ";\t" << T2 << ";\t" << T3 << "]";
		return stm.str();
	}
};

const int xabs(const int &a)
{
	return (a < 0) ? 0 : a;
}

int findMaxMargin(vector<Timer> &timers)
{
	int margin = 0, start = 0;
	for(auto t: timers)
	{
		// cout << t.ToString() << " -> " << start << endl;
		if (start < t.T1)
		{
			start = t.T1 + t.T2;
		}
		else
		{
			start += t.T2;
		}
		margin = max(margin, xabs(start - t.T3));
	}
	return margin;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int N;
	cin >> N;
	vector<Timer> times;
	for (int i = 0; i < N; ++i)
	{
		Timer t;
		cin >> t.T1 >> t.T2 >> t.T3;
		times.push_back(t);
	}

	sort(times.begin(), times.end(), [](const Timer &t1, const Timer & t2) -> bool { return t1.T1 < t2.T1; });

	cout << findMaxMargin(times);
}