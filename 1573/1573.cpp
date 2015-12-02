#include <iostream>
#include <string>
using namespace std;

unsigned long long binomialCoefficient(int n, int k)
{
	if (k < 0 || k > n)
		return 0;
	if (k > n - k) // take advantage of symmetry
		k = n - k;
	if (k == 0 or n <= 1)
		return 1;
	return binomialCoefficient(n-1, k) + binomialCoefficient(n-1, k-1);
}

const string Blue = "Blue";
const string Red = "Red";
const string Yellow = "Yellow";

int main()
{
	int ingridients[3] = {0, 0, 0};
	int reciepts[3] = {0, 0, 0};
	cin >> ingridients[0] >> ingridients[1] >> ingridients[2];
	int count;
	cin >> count;

	string ingridient;
	int ind;
	for (int i = 0; i < count; ++i)
	{
		cin >> ingridient;
		if (ingridient == Blue)
			ind = 0;
		if (ingridient == Red)
			ind = 1;
		if (ingridient == Yellow)
			ind = 2;
		reciepts[ind]++;
	}

	unsigned long long answer = 
		binomialCoefficient(ingridients[0], reciepts[0]) *
		binomialCoefficient(ingridients[1], reciepts[1]) *
		binomialCoefficient(ingridients[2], reciepts[2]);

	cout << answer;
	return 0;
}