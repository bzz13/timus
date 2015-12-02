#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool myfunction (int i,int j)
{
	return i > j; 
}

double calcWeight(double m1, double m2)
{
	return 2 * sqrt(m1 * m2);
}

int main()
{
	int count, tmp;
	cin >> count;

	std::vector<int> numbers;
	
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		numbers.push_back(tmp);
	}

	if (count == 1)	
	{
		cout << std::fixed << std::setprecision(2) << *(numbers.begin());
		return 0;
	}
	
	sort(numbers.begin(), numbers.end(), myfunction);

	double answer = calcWeight( *(numbers.begin()), *(numbers.begin() + 1) );
	for (std::vector<int>::iterator it = numbers.begin() + 2; it != numbers.end(); ++it)
		answer = calcWeight(answer, *it);

	cout << std::fixed << std::setprecision(2) << answer;
}