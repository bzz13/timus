#include <iostream>
#include <string>
using namespace std;


int main()
{
	string bigInt;
	cin >> bigInt;
	int coeff[6] = {1, 3, 2, 6, 4, 5};
	int answer = 0;

	for (int i = 0; i < bigInt.size(); ++i)
	{
		answer += ( coeff[i % 6] * ((bigInt[bigInt.size() - 1 - i]) - '0'));
		// cout << coeff[i % 6] << " * " << (bigInt[bigInt.size() - 1 - i] - '0') << " = " << answer << endl;
	}
	cout << answer % 7;
} 