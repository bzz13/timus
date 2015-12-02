#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class cyclicVector
{
	vector<int> v;

	int abs(int t) { return t >= 0 ? t : -t; }

public:
	cyclicVector(const int& n): v(n) { }
	~cyclicVector() { }

	      int& operator[](int idx)       { return v[idx]; };
    const int& operator[](int idx) const { return v[idx]; };

	int getAvarage(const int& start)
	{
		int answer = 0;
		int pos = 1;
		for (int i = start; i < v.size(); ++i)
			answer += abs(v[i] - pos++) == 0 ? 1 : 0;
		for (int i = 0; i < start; ++i)
			answer += abs(v[i] - pos++) == 0 ? 1 : 0;;
		return answer;
	}

	void print(const int& start)
	{
		for (int i = start; i < v.size(); ++i)
			cout << v[i] << ' ';
		for (int i = 0; i < start; ++i)
			cout << v[i] << ' ';
		cout << endl;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, answer = 0, position = 0;
	cin >> count;

	cyclicVector group(count);
	for (int i = 0; i < count; ++i)
		cin >> group[i];

	for (int i = 1; i <= count; ++i)
	{
		int tmp = group.getAvarage(i-1);

		// group.print(i);
		// cout << tmp << endl << endl;

		if (tmp > answer)
		{
			answer = tmp;
			position = i;
		}
	}

	cout << position;
}