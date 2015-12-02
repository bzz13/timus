#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int count = 4;
const int rotation[count][count] = 
{
	0, 1, 2, 1,
	1, 0, 1, 2,
	2, 1, 0, 1,
	1, 2, 1, 0,
};

int getMaxCountD( const int ( &a )[count][count])
{
	map<int, int> m;
	for (int i = 0; i < count; ++i)
		m[i] = 0;

	m[a[0][0]]++;
	m[a[0][1]]++;
	m[a[1][0]]++;
	m[a[1][1]]++;
	int max = 0;

	if (m[a[0][0]] > max)
		max = m[a[0][0]];
	if (m[a[0][1]] > max)
		max = m[a[0][1]];
	if (m[a[1][0]] > max)
		max = m[a[1][0]];
	if (m[a[1][1]] > max)
		max = m[a[1][1]];

	for(auto i: m)
		if (i.second == max)
			return i.first;
}

int rot(const int& a, const int& b)
{
	return rotation[a-1][b-1];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int r[count][count];
	int m[count][count];
	for (int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			cin >> m[i][j];

	map<int, int> conv;
	conv[m[0][0]] = 1;
	conv[m[0][3]] = 2;
	conv[m[3][3]] = 3;
	conv[m[3][0]] = 4;

	for (int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			for(auto c: conv)
				if (m[i][j] == c.first)
					r[i][j] = c.second;

	int answer = 0;
	int tmp = getMaxCountD(r);
	answer += rot (r[0][0], tmp);
	answer += rot (r[0][1], tmp);
	answer += rot (r[1][0], tmp);
	answer += rot (r[1][1], tmp);
	cout << answer;

}