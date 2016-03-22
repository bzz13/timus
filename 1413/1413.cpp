#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif

	double x = 0, y = 0, c = sqrt(0.5);
	char ch;
	while(cin.get(ch) && ch != '0') 
	{
		switch (ch)
		{
			case '1':
				x -= c;
				y -= c;
				break;
			case '2':
				y -= 1;
				break;
			case '3':
				x += c;
				y -= c;
				break;
			case '6':
				x += 1;
				break;
			case '9':
				x += c;
				y += c;
				break;
			case '8':
				y += 1;
				break;
			case '7':
				x -= c;
				y += c;
				break;
			case '4':
				x -= 1;
				break;
		}
	}
	cout << std::fixed << setprecision(10) << x << ' ' << y;
}