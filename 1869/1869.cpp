#include <iostream>
#include <stdio.h>
using namespace std;

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
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			cout << ary[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int const getIncomeCount(int** ary, const int& row, const int& count)
{
	int result = 0;
	for (int i = row; i < count; ++i)
		result += ary[row][i];
	return result;
}

int const getGoneCount(int** ary, const int& row, const int& count)
{
	int result = 0;
	for (int i = 0; i < row; ++i)
		result += ary[i][row];
	return result;
}

int** createTranspon(int** ary, const int& count)
{
	int** tr = create(count);
	for (int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			tr[count - 1 - i][count - 1 - j] = ary[i][j];
	return tr;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif

	int count;
	cin >> count;

	int** ary = create(count);

	for (int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			cin >> ary[i][j];
	// print(ary, count);

	int inTrain = 0, max = 0;
	inTrain = max = getIncomeCount(ary, 0, count);
	// cout << inTrain << endl;
	for (int i = 1; i < count; ++i)
	{
		inTrain = inTrain + getIncomeCount(ary, i, count) - getGoneCount(ary, i, count);
		if (inTrain > max)
			max = inTrain;
		// cout << inTrain << endl;
	}

	int** tr = createTranspon(ary, count);
	// print(tr, count);

	inTrain = getIncomeCount(tr, 0, count);
	if (inTrain > max)
		max = inTrain;
	// cout << inTrain << endl;
	for (int i = 1; i < count; ++i)
	{
		inTrain = inTrain + getIncomeCount(tr, i, count) - getGoneCount(tr, i, count);
		if (inTrain > max)
			max = inTrain;
		// cout << inTrain << endl;
	}
	// cout << endl;

	cout << (max / 36 + (max % 36 ? 1 : 0));

	free(ary, count);
	free(tr, count);
}