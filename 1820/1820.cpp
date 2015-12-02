#include <iostream>
using namespace std;

int main()
{
	int n, k, sides;
	cin >> n >> k;
	sides = n * 2;
	if (k >= n)
		cout << 2;
	else 
	{
		int answer = sides / k;
		if ( sides % k >= 1) answer ++;
		cout << answer; 
	}
}