#include <iostream>
#include <string>
using namespace std;

void printArr(string prefix, int nums[], int total, bool needEndl = false)
{
	cout << prefix;
	for (int i = 0; i < total - 1; ++i)
		cout << nums[i] << " ";
	cout << nums[total - 1];
	if (needEndl)
		cout << endl;
}

int* getNewDeltas(int count)
{
	int *delta = new int[count*2];
	for (int i = 2; i <= count; ++i)
		delta[i-2] = i;

	for (int i = count + 1; i < 2*count; ++i)
		delta[i-2] = 2*count - i + 1;

	return delta;
}

void shiftDeltas(int *nums, int count)
{
	int first = nums[0];
	for (int i = 1; i < count; ++i)
		nums[i - 1] = nums[i];
	nums[count - 1] = first;

}

int main()
{
	int count;
	cin >> count;
	int total = count * count;
	int *nums = new int[total];
	int *delta = getNewDeltas(count);

	int pos = 0;
	for (int i = 0; i < count; ++i)
	{
		pos += i;
		int dd = 0;
		for (int j = 0; j < count; ++j)
		{
			cin>>nums[pos];
			dd  += delta[j];
			pos += delta[j];
		}
		pos -= dd;

		shiftDeltas(delta, count * 2);
	}


	printArr("", nums, total);
	delete[] delta;
	delete[] nums;
}