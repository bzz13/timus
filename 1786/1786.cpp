#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void printArray(int arr[], const int& x)
{
	for (int i = 0; i < x; ++i)
		cout << arr[i];
	cout << endl;
}

int CalcCost(string a, string b, const int & pos)
{
	int answer = 0;
	char ai, bi;
	for (int i = 0; i < b.size(); ++i)
	{
		ai = a[pos + i];
		bi = b[i];
		if ( islower (ai) && isupper(bi) )
		{
			ai = toupper(ai);
			answer ++ ;
		} 
		else 
			if ( isupper (ai) && islower(bi))
			{
				ai = tolower(ai);
				answer ++ ;
			} 
		if (ai != bi)
			answer++;
	}
	return answer;
}

int main()
{
	int answer = 100000;
	string a, b = "Sandro";
	cin >> a;

	int *d = new int[a.size()];
	for (int i = 0; i <= a.size() - b.size(); ++i)
	{
		d[i] = CalcCost(a, b, i);
		if (answer > d[i])
			answer = d[i];
	}

	// printArray(d, a.size());
	cout << answer * 5;

	delete[] d;
}