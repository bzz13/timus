#include <iostream>
#include <cmath>
using namespace std;

struct triviality
{
	triviality(int n)
	{
		val = 1L / n;
		isSimple = true;

		for (int i = 2; i <= sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				isSimple = false;
				val += (double)i / n;
				if (n / i != i)
					val += (double)(n/i) / n;
			}
		}
	}

	bool isSimple;
	double val;
};

int main()
{
	int i,j, answer;
	cin >> i >> j;
	double minT = j; 

	if (i == 1)
	{
		answer = 1;
	}
	else
	{
		for (int k = j; k >= i; k--)
		{
			triviality t(k);
			if (t.isSimple)
			{
				answer = k;
				break; 
			}
			else
				if (minT > t.val)
				{
					answer = k;
					minT = t.val;
				}
		}
	}
	cout << answer;
}