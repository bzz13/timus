#include <iostream>
#include <cmath> 
using namespace std;


int main()
{
	int N;
	cin >> N;
	int answerA = 0, answerP = 0;
	for (int p = 1; p <= sqrt(2*N); ++p)
	{
		if ( (2 * N) % p == 0)
		{
			int a2 = ((2 * N) / p + 1 - p) ;
			if (a2 % 2 == 0 && answerP < p)
			{
				answerA = a2 / 2;
				answerP = p;
			}
		}
	}
	cout << answerA << " " << answerP;
}