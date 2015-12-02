#include <iostream>
using namespace std;

int min(const int& a, const int& b)
{
	return a < b ? a : b;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(a - b * c, a - b - c);
	return 0;
}