#include <iostream>
using namespace std;

unsigned long long int sum(int array[], int begin, int end)
{
	unsigned long long int result = 0;
	for (int i = begin; i < end; ++i)
		result += array[i];
	return result;
}

unsigned long long int max(const unsigned long long int& a, const unsigned long long int& b)
{
	return a > b ? a : b;
}
unsigned long long int min(const unsigned long long int& a, const unsigned long long int& b)
{
	return a < b ? a : b;
}

int main()
{
	int count, startA, startB, m;
	unsigned long long int answerA = 0, answerB = 0;
	cin >> count;
	int *array = new int[count];
	for (int i = 0; i < count; ++i)
		cin >> array[i];
	cin >> startA >> startB;
	if (startA < startB)
	{
		m = (startA + startB) / 2;
		answerA = sum(array, 0, m);
		answerB = sum(array, m, count);
	}
	else
	{
		if (startA > startB)
		{
			m = (startA + startB) / 2;
			if ((startA + startB) % 2 == 0)
				m--;
			
			answerA = sum(array, m, count);
			answerB = sum(array, 0, m);
		} 
		else //if (startA == startB)
		{
			if (startA == 1 || startA == count)
			{
				answerA = sum(array, 0, count);
				answerB = 0;
			}
			else
			{
				unsigned long long int 
					lv = sum(array, 0, startA + 1), 
					rv = sum(array, startA - 1, count);

				answerA = max(lv, rv);
				answerB = sum(array, 0, count) - answerA;
			}

		}
	}
	cout << answerA << ' ' << answerB;

	delete[] array;
}