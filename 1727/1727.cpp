#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int getDigitSum(int i)
{
	auto res = 0;
	while(i > 0)
	{
		res += i % 10;
		i /= 10;
	}
	return res;
}

struct N
{
	int v;
	int s;

	N& operator=(const N& other)
	{
		v=other.v;
		s=other.s;
		return *this;
	}
};

bool operator <(const N& x, const N& y) {
	return x.s > y.s;
}

int main()
{
	int value;
	cin >> value;
	const int max = 99999;

	vector<N> v(max);
	for (int i = 0; i < max; ++i)
	{
		auto s = i + 1;
		v[i].v = s;
		v[i].s = getDigitSum(s);
	}

	sort(v.begin(), v.end());

	vector<int> r;
	for(auto t: v)
	{
		if (value >= t.s)
		{
			r.push_back(t.v);
			value -= t.s;
		}
		if (value == 0)
			break;
	}


	cout << r.size() << endl;
	for(auto c: r)
		cout << c << " ";

	return 0;
}