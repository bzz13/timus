#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output2.txt", "wt", stdout);
#endif

	int count, tmp;
	cin >> count;
	vector<int> v(count);
	for (int i = 0; i < count; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	string d;
	cin >> d;

	cin >> count;
	vector<int> q(count);
	for (int i = 0; i < count; ++i)
		cin >> q[i];

	for (int i = 0; i < count; ++i)
		cout << v[q[i] - 1] << endl;
}