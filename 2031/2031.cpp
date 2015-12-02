#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	switch(n)
	{
		case 1:
			cout << "11";
			break;
		case 2:
			cout << "11 01";
			break;
		case 3:
			cout << "06 68 88";
			break;
		case 4:
			cout << "16 06 68 88";
			break;
		default:
			cout << "Glupenky Pierre";
	}
}