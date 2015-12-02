#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k, answer;
	string s;
	cin >> n >> s;
	k = s.size();

	answer = n;
	while(n - k > 0)
	{
		answer *= n-k;
		n -=k;
	}
	cout << answer;
}