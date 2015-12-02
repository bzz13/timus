#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int an = atoi(a.c_str());
	int bn = atoi(b.c_str());

	cout << (((an%2 == 0 || bn%2 == 1)) ? "yes" : "no");
}