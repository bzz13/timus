#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	switch (N)
	{
		case 1:
			cout << "1 2 3";
			break;
		case 2:
			cout << "3 4 5";
			break;
		default:
			cout << -1;
			break;
	}
}