#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, tmp, answer = 0;
	cin >> n;

	int *s = new int[n*n];
	int *d = new int[n*n];

	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n; ++i)
		{	
			cin >> s[j*n + i];
			d[j*n + i] = s[j*n + i];
		}

	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n; ++i)


			for (int l = 0; l < n-j; ++l)
				for (int k = 0; k < n-i; ++k)
				{
					tmp = 0;

					for (int o = 0; o <= l; ++o)
					{
						for (int p = 0; p <= k; ++p)
						{
							// cout << s[(j + o)*n + (i + p)] << ' ';
							tmp += s[(j + o)*n + (i + p)];
						}
						// cout << endl;
					}

					d[j*n + i] = max(d[j*n + i], tmp);
					// cout << endl;
				}


	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n; ++i)
			answer = max(answer, d[j*n + i]);

	cout << answer; 

	delete[] d;
	delete[] s;
	return 0;
}