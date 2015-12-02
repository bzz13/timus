#include <iostream>
using namespace std;

int resolve(int n, int k)
{
	int divNK = n / k;
	int modNK = n % k;
	int* gr = new int[k];
	for (int i = 0; i < k; ++i)
		gr[i] = 0;

	for (int i = 0; i < n; ++i)
		gr[i % k]++;

	int answer = 0;
	for (int i = 0; i < k - 1; ++i)
	{
		answer += gr[i] * (n - gr[i]);
		n -= gr[i];
	}
	delete[] gr;
	return answer;
}

int main()
{
	int T, n, k;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n >> k;
		if (i != 0)
			cout << endl;
		cout << resolve(n,k);
	}
}