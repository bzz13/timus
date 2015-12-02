#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a <= b) 
		cout << b*2 + 40;
	else 
		cout << 119 + (a-40) * 2;
}