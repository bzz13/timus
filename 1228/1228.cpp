#include <iostream>
using namespace std;


int main()
{
	int N, l, tmp;
	cin >> N >> l;
	int *D = new int[N];
	int *K = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> D[i];

	tmp = l - 1;
	for (int i = 0;  i < N; ++i)
	{
		if (i < N-1)
		{
			K[i] = tmp / D[i];
			cout << K[i] << ' ';
			tmp = tmp % D[i];
		}
		else
		{
			K[i] = tmp;
			cout << K[i];
		}
	}

	delete[] K;
	delete[] D;
	return 0;
} 