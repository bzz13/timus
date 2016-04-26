#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool sorter (int i,int j) { return (i>j); }

int** create(const int& count)
{
	int** ary = new int*[count];
	for(int i = 0; i < count; ++i)
		ary[i] = new int[count];
	return ary;
}

void free(int** ary, const int& count)
{
	for(int i = 0; i < count; ++i) 
		delete [] ary[i];
	delete [] ary;
}

void print(int** ary, const int& count)
{
	for(int i = 0; i < count; ++i) 
	{
		for (int j = 0; j < count; ++j)
		{
			cout << ary[i][j] << " ";
		}
		cout << endl;
	}
}
 
void leftRotatebyOne(int arr[], const int& n)
{
	int i, temp;
	temp = arr[0];
	for (i = 0; i < n-1; i++)
		arr[i] = arr[i+1];
	arr[i] = temp;
}

void leftRotate(int arr[], const int& d, const int& n)
{
	for (int i = 0; i < d; i++)
		leftRotatebyOne(arr, n);
}

void fill(int** ary, vector<int>& v, const int& count)
{
	for(int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			ary[i][j] = v[count*i+j];
}

void verticalRotateByOne(int** ary, const int& count)
{
	int* temp = ary[0];
	for (int i = 0; i < count - 1; ++i)
		ary[i] = ary[i+1];
	ary[count - 1] = temp;
}

void reverse(int arr[], const int& d)
{
	for(int i = 0; i < d/2; ++i)
	{
		int temp = arr[i];
		arr[i] = arr[d - 1 - i];
		arr[d - 1 - i] = temp;
	}
}

void rotate(int** ary, const int& count)
{
	for(int i = 0; i < count; ++i)
		leftRotate(ary[i], count / 2 + 1, count);

	for (int i = 0; i < count/2 + 1; ++i)
		verticalRotateByOne(ary, count);

	for (int i = 0; i < count/2; ++i)
		verticalRotateByOne(ary, count/2 - i);

	for(int i = 0; i < count; ++i)
		reverse(ary[i], count / 2 );
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif

	int count;
	cin >> count;
	vector<int> sizes(count*count);
	for (int i = 0; i < count*count; ++i)
		cin >> sizes[i];
	sort(sizes.begin(), sizes.end(), sorter);
	// for(auto s: sizes)
	// 	cout << s << " ";
	// cout << endl;

	int** sq = create(count);
	fill(sq, sizes, count);
	// print(sq, count);
	rotate(sq, count);
	print(sq, count);
	free(sq);
}