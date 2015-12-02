#include <iostream>
using namespace std;

int main()
{
	int l1, l2, n1, n2;
	cin >> l1 >> l2 >> n1 >> n2;

	if (n1 == n2)
		cout << l1;
	else
		if (n1 < n2)
			cout << (n2 - n1 - 1) * l1 + (n2 - n1) * 2 * l2;
		else
			cout << (n1 - n2 + 1) * l1 + (n1 - n2) * 2 * l2;
}