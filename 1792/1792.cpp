#include <iostream>
using namespace std;

int sumMod2(int a, int b)
{
	return a ^ b;
}

int sumMod2(int a, int b, int c)
{
	return (a ^ b) ^ c;
}

int sumMod2(int a, int b, int c, int d)
{
	return ((a ^ b) ^ c) ^ d;
}
int invert(int a)
{
	return a == 0 ? 1 : 0;
}

int main()
{
	int i1, i2, i3, i4, r1, r2, r3, s1, s2, s3;
	cin >> i1 >> i2 >> i3 >> i4 >> r1 >> r2 >> r3;

	s1 = sumMod2(r1, i2, i3, i4);
	s2 = sumMod2(r2, i1, i3, i4);
	s3 = sumMod2(r3, i1, i2, i4);

	// cout << s1 << " " << s2 << " " << s3 << endl;
	// cout << (s1 << 2) << " " << (s2 << 1) << " " << s3 << endl;
	
	int syndrom = s1 * 100  + s2 * 10 + s3;
	// cout << syndrom << endl;
	switch (syndrom)
	{
		case 11:
			i1 = invert(i1);
			break;
		case 101:
			i2 = invert(i2);
			break;
		case 110:
			i3 = invert(i3);
			break;
		case 111:
			i4 = invert(i4);
			break;
		case 100:
			r1 = invert(r1);
			break;
		case 10:
			r2 = invert(r2);
			break;
		case 1:
			r3 = invert(r3);
			break;
		default:
			break;
	}
	cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << r1 << " " << r2 << " " << r3;
}