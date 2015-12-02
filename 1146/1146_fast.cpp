#include <iostream>
#include <cmath>
using namespace std;

int maximum(int nums[], int n, int s, int t)
{
}

int main()
{
	int n, tmp, answer = -100000;
	cin >> n;

	int *r = new int[(n + 1)*(n+1)];
	int *d = new int[(n + 1)*(n+1)];

	// cout << endl;
	for (int j = 0; j <= n; ++j)
	{
		for (int i = 0; i <= n; ++i)
		{	
			if (i == 0 || j == 0)
				r[j*(n+1) + i] = 0;
			else
				cin >> r[j*(n+1) + i];

			d[j*(n+1) + i] = r[j*(n+1) + i];
			// cout << d[j*(n+1) + i] << ' ';
		}
		// cout << endl;
	}

	// cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i*(n+1) + j] = d[(i - 1)*(n+1) + j] + d[i*(n+1) + j - 1] - d[(i - 1)*(n+1) + j - 1] + r[i*(n+1) + j];
			// cout << d[i*(n+1) + j] << ' ';
		}
		// cout << endl;
	}


	// cout << endl;
	for (int x1=1;x1<=n;x1++)
		for (int y1=1;y1<=n;y1++)
			for (int x2=x1;x2<=n;x2++)
				for (int y2=y1;y2<=n;y2++){
					tmp = d[x2*(n+1) + y2] - d[(x1-1)*(n+1) + y2] - d[x2*(n+1) + y1-1] + d[(x1-1)*(n+1) + y1-1];
					answer = max(max(tmp, d[x2*(n+1) + y2]), answer);
				}


	cout << answer; 

	delete[] d;
	delete[] r;
	return 0;
}