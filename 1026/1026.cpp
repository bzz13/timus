#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void printArr(int arr[], const int& count)
{
	cout << '[' ;
	for (int i = 0; i < count; ++i)
	{
		if (i)
			cout << ", ";
		cout << arr[i];
	}
	cout << ']' << endl;
}

void InsertSort(int arr[], int& size, const int& val)
{
	int index = size++;
	arr[index] = val;

	// printArr(arr, size);
	while(index > 0 && arr[index - 1] > arr[index])
	{
		arr[index] = arr[--index];
		arr[index] = val;
		// printArr(arr, size);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output1.txt", "wt", stdout);
#endif

	const int limit = 100001; 
	int v[limit], size = 0, count, tmp;

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		InsertSort(v, size, tmp);
	}
	// printArr(v, size);

	string d;
	cin >> d;

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		cout << v[tmp - 1] << endl;
	}
}