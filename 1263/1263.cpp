#include <iostream>
#include <map>
#include <cmath>
#include <stdio.h>
using namespace std;

std::map<int, int> voice;

int main()
{
	int N, total, tmp;
	cin >> N;
	for (int i = 0; i < N; ++i)
		voice[i] = 0;
	cin >> total;
	for (int i = 0; i < total; ++i)
	{
		cin >> tmp;
		voice[tmp - 1]++;
	}

	for (int i = 0; i < N; ++i)
	{
		float f = (((float)voice[i]) / total * 100);
		printf("%.2lf%%\n", f);
	}
}