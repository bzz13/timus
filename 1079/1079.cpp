#include <iostream>
#include <cmath>
using namespace std;

const int count = 100000;
int NS[count];
int mNS[count];

int a(int i)
{
	if (i < 2)
		return i;
	if (i % 2 == 0)
		return NS[i/2];
	else
		return NS[i/2] + NS[i/2 + 1];
}
int ma(int i)
{
	if (i < 2)
		return i;
	else
		return max(mNS[i-1], NS[i]);
}

int main()
{
	for (int i = 0; i < count; ++i)
	{
		NS[i] = a(i);
		mNS[i] = ma(i);
	}

	int tmp;
	while(true)
	{
		cin >> tmp;
		if (tmp == 0)
			break;
		cout << mNS[tmp] << endl;
	}

	/*
	cout << "{ ";
	for (int i = 0; i < count; ++i)
	{
		if (i == 0)
			cout << mNS[i];
		else
			cout << ", " << mNS[i];
	}
	cout << " }" << endl;
	*/

}