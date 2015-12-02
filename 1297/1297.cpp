#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string input, answer;
	cin >> input;
	int x = 0, count = input.size();

	std::vector<int> d1(count, 0);
	for (int i = 0; i < count; ++i)
	{
		int k = 1;
		while(i-k >= 0 && i+k < count && input[i-k] == input[i+k])
		{
			// cout << input[i-k] << " <- " << input[i] << " -> " << input[i+k] << endl; 
			k++;
		}
		d1[i] = (--k);
	}
	for (int i = 0; i < count; i++)
	{
		// cout << d1[i] << ' ';
		if ( d1[i] * 2 + 1 > x)
		{
			x = d1[i] * 2 + 1;
			answer = input.substr(i - d1[i], x);
			// cout << answer;
		}
	}
	// cout << endl << endl;

	std::vector<int> d2(count, 0);
	for (int i = 0; i < count - 1; ++i)
	{
		int k = 0;
		while(i-k >= 0 && i+1+k < count && input[i-k] == input[i+1+k])
		{
			// cout << input[i-k] << " <- " << '|' << " -> " << input[i+1+k] << endl; 
			k++;
		}
		d2[i] = k;
	}
	for (int i = 0; i < count; i++)
	{
		// 	 cout << d1[i] << ' ';
		if ( d2[i] * 2 > x)
		{
			x = d2[i] * 2;
			answer = input.substr(i - d2[i] + 1, x);
			// cout << answer;
		}
	}
	// cout << endl << endl;

	cout << answer;
	return 0;
}