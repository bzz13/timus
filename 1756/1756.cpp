#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int dig, d1, d2;
	cin >> dig >> d1 >> d2;
	int m = dig*d1;
	int c = m/d2;
	vector<int> v(d2, c);
	int over = m - c*d2;
	if (over < d2)
		for (int i = 0; i < over; ++i)
			v[i]++;

	for(auto x: v)
		cout << x << ' ';
}