#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int count;
	double total = 0, b;
	cin >> count;
	double * v = new double[count];
	for (int i = 0; i < count; ++i)
	{
		cin >> v[i];
		total += v[i];
	}

	b = total / (count + 1);
	total = 0;

	for (int i = 0; i < count; ++i)
	{
		v[i] = v[i] > b ? (v[i] - b) : 0;
		total += v[i];
	}

	for (int i = 0; i < count; ++i)
	{
		cout << floor(100.0 * (v[i] / total) + 0.0000001 ) << ' ';
	}

	delete[] v;
}