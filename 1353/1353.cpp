#include <iostream>
using namespace std;

const int rowcount = 10;
const int colcount = 82;

int sum(int n, int s, int ns[rowcount][colcount])
{
	int result = 0;
	for (int i = 0; i < 10  && i <= s; ++i)
		result += ns[n-i][s-i];
	return result;
}

int main()
{
	int nums[colcount][colcount];
	for (int i = 0; i < colcount; ++i)
		nums[0][i] = nums[1][i] = 0;
	for (int i = 0; i < 10; ++i)
		nums[1][i] = 1;

	for (int i = 1; i < rowcount; ++i)
	{
		for (int j = 1; j < colcount; ++j)
			nums[i][j] = sum(i, j, nums);
	}

	int n;
	cin >> n;
	cout << nums[9][n];
}