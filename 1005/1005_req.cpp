#include <iostream>
#include <cmath>

using namespace std;


int calcArraySum(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];
	return sum;
}

double get_w_eq(int arr[], int size)
{
	return double(calcArraySum(arr, size)) / 2;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
		cout << arr[i] << ' ';
	cout << arr[size - 1];
}

int* getPartion(int arr[], int size, int index)
{
	int *vals = new int[size - 1];
	for (int i = 0; i < index; ++i)
		vals[i] = arr[i];
	for (int i = index + 1; i < size; ++i)
		vals[i - 1] = arr[i];
	return vals;
}

void printPartions(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << endl;
		cout << arr[i] << " : ";
		int *partion = getPartion(arr, size, i);
		printArray(partion, size - 1);
		delete[] partion;
		cout << endl;
	}
}

double calcOptimalMin(int arr[], int size)
{
	if (size == 1)
		return arr[0];

	double min = 999999999;
	double w_eq = get_w_eq(arr, size);
	for (int i = 0; i < size; ++i)
	{
		int w_i = arr[i];
		int *partion = getPartion(arr, size, i);
	    
	    // printPartions(partion, size - 1);		
		
		double tmp = abs(w_i + calcOptimalMin(partion, size - 1) - w_eq);
		// cout << tmp << endl;
		delete[] partion;
		if (tmp < min)
			min = tmp;
	}
	return min;
}

int main()
{
	int count;
	cin >> count;
	int *values = new int[count];
	for (int i = 0; i < count; ++i)
		cin >> values[i];
	double min = calcOptimalMin(values, count);
	cout << min;
	delete[] values;
}